#include "game.h"

#include <QBrush>
#include <QImage>
#include <QPointF>
#include <QString>
#include <QList>
#include <QDebug>


xGame::xGame(int viewWidth, int viewHeight): QGraphicsView () {

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, viewWidth, viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create strating map
    mapLayout = new xMapLayout;

    //create hero
    hero = new xHero("hero");
    hero->setViewPos(mapLayout->getStartX()*PixelsX, mapLayout->getStartY()*PixelsY); //place heroBlock on scene
    hero->getView()->setZValue(10); //set hero view on top of map
    scene->addItem(hero->getView());

    //create enemy
    enemy = new xEnemy("squirrel");
    enemy->setViewPos(96, 96);
    enemy->getView()->setZValue(9); //set enemy view on top of map
    scene->addItem(enemy->getView());
}

void xGame::placeBlock(int xpos, int ypos, QString blockName, bool isObs) {
    //place new block
    block = new xBlock(blockName, isObs);
    block->setPos(xpos, ypos);
    scene->addItem(block);

    //remove old block
    QList<QGraphicsItem *> colliding_items = block->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
}

// list all characterviews and delete all except hero's one
void xGame::clearEnemies() {
    xCharacterView *ev = new xCharacterView();

    QList<QGraphicsItem *> sceneItems = scene->items();
    for (int i = 0, n = sceneItems.size(); i < n; ++i) {
        if (typeid(*(sceneItems[i])) == typeid(xCharacterView)) {
            ev = qgraphicsitem_cast<xCharacterView *>(sceneItems[i]);
            qDebug() << ev;
            if (ev->getViewName() != "hero") {
                scene->removeItem(ev);
                delete ev;
            }
        }
    }
}


