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
    enemy->setViewPos(128, 128);
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


