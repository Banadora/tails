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
    heroBlock = new xBlockHero("hero");

    //create map
    mapLayout = new xMapLayout;
    paintMap(1);
}

////////// place blocks on scene based on which mapLayout is called
void xGame::paintMap(int nLvl) {

    clearMap(nLvl);
    mapLayout->setLayout(nLvl); //get layout

    for (int x = 0; x < nbBlocksX; x++) {
        for (int y = 0; y < nbBlocksY; y++) {

            if (    (x == mapLayout->getExitsX(1))   &&    (y == mapLayout->getExitsY(1))   ) { block = new xBlockExit(mapLayout->getBlockName(x,y), 2, 7, 11); } //exit1
            else if (    (x == mapLayout->getExitsX(2))   &&    (y == mapLayout->getExitsY(2))   ) { block = new xBlockExit(mapLayout->getBlockName(x,y), 2, 2, 11); } //exit2
            else { block = new xBlock(mapLayout->getBlockName(x,y)); }

            block->setPos(x*PixelsX, y*PixelsY);
            scene->addItem(block);
            activeBlocks[x][y] = block; //place block in array to access it later
        }
    }

    heroBlock->setFlag(QGraphicsItem::ItemIsFocusable);
    heroBlock->setFocus();
    heroBlock->setPos(mapLayout->getStartX()*PixelsX, mapLayout->getStartY()*PixelsY); //place heroBlock on scene
    heroBlock->setX(mapLayout->getStartX());
    heroBlock->setY(mapLayout->getStartY());
    scene->addItem(heroBlock);
}

void xGame::clearMap(int nLvl) {
    if (nLvl != 1) {
        for (int x = 0; x < nbBlocksX; x++) {
            for (int y = 0; y < nbBlocksY; y++) {
                scene->removeItem(activeBlocks[x][y]);
                delete activeBlocks[x][y];
            }
        }
        scene->removeItem(heroBlock);
    }
}

