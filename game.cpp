#include "game.h"


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
            //xBlock block(mapLayout->getBlockName(x,y)); //Using new() methods is not advised in C++ ?
            block = new xBlock(mapLayout->getBlockName(x,y));
            block->setPos(x*PixelsX, y*PixelsY);
            scene->addItem(block);
            activeBlocks[static_cast<unsigned int>(x)][static_cast<unsigned int>(y)].reset(block); //place block in 2D vector to access it later
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
        for (unsigned int x = 0; x < nbBlocksX; x++) {               // Remove each block from map
            for (unsigned int y = 0; y < nbBlocksY; y++) {
                scene->removeItem(activeBlocks[x][y].get());
            }
        }
        activeBlocks.clear();         //Clear the 2D vector. No need to manually delete the pointers as unique_ptr objects are smart enough so memory management should be fine here.
        scene->removeItem(heroBlock); //Remove hero from map
    }
}

