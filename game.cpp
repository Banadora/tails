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
    heroBlock->setFlag(QGraphicsItem::ItemIsFocusable);
    heroBlock->setFocus();

    //create map
    mapLayout = new xMapLayout;
    paintMap(1);
}

////////// place blocks on scene based on which mapLayout is called
void xGame::paintMap(int nLvl) {
    mapLayout->setLayout(nLvl); //get layout
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            block = new xBlock(mapLayout->getBlockName(x,y));
            block->setPos(x*PixelsX, y*PixelsY);
            scene->addItem(block);
            activeBlocks[x][y] = block; //place block in array to access it later
        }
    }

    heroBlock->setPos(mapLayout->getStartX()*PixelsX, mapLayout->getStartY()*PixelsY); //place heroBlock on scene
    heroBlock->setX(mapLayout->getStartX());
    heroBlock->setY(mapLayout->getStartY());
    scene->addItem(heroBlock);
}

