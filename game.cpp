#include "game.h"

#include <QDebug>

////////// init
/*QWidget *parent*/
xGame::xGame(int viewWidth, int viewHeight) {

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, viewWidth, viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create hero
    hero = new xCharacter;

    //create map
    mapLayout = new xMapLayout;
    paintMap(0); //init map
}

////////// place blocks on scene based on which mapLayout is called
void xGame::paintMap(int nLvl) {

    clearMap(nLvl);
    mapLayout->setLayout(nLvl); //get layout

    for (int x = 0; x < nbBlocksX; x++) {
        for (int y = 0; y < nbBlocksY; y++) {

            block = new xBlock(mapLayout->getBlockName(x,y));

            block->setPos(x*PixelsX, y*PixelsY);
            scene->addItem(block);
            activeBlocks[x][y] = block; //place block in array to access it later
        }
    }

    hero->setViewPos(mapLayout->getStartX()*PixelsX, mapLayout->getStartY()*PixelsY); //place heroBlock on scene
    scene->addItem(hero->getView());
}

void xGame::clearMap(int nLvl) {
    if (nLvl != 0) {
        for (int x = 0; x < nbBlocksX; x++) {
            for (int y = 0; y < nbBlocksY; y++) {
                scene->removeItem(activeBlocks[x][y]);
                delete activeBlocks[x][y];
            }
        }
        scene->removeItem(hero);
    }
}

