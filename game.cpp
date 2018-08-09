#include "game.h"

#include <QDebug>

/*QWidget *parent*/
xGame::xGame(int viewWidth, int viewHeight) {

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, viewWidth, viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create hero
    heroBloc = new xBloc("hero");
    heroBloc->setFlag(QGraphicsItem::ItemIsFocusable);
    heroBloc->setFocus();

    //create map
    mapLayout = new xMapLayout;
    paintMap(1);
}

void xGame::paintMap(int nLvl) {
    mapLayout->setLayout(nLvl);
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            bloc = new xBloc(mapLayout->getBlocName(x,y));
            bloc->setName(mapLayout->getBlocName(x,y));
            bloc->setPos(x*32, y*32);
            scene->addItem(bloc);
            activeBlocs[x][y] = bloc;
        }
    }

    heroBloc->setPos(mapLayout->getStartX()*32, mapLayout->getStartY()*32);
    heroBloc->setX(mapLayout->getStartX());
    heroBloc->setY(mapLayout->getStartY());
    scene->addItem(heroBloc);
}

