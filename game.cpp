
#include "game.h"

/*QWidget *parent*/
xGame::xGame(int viewWidth, int viewHeight) {

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, viewWidth, viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create map
    mapLayout = new xMapLayout;
    paintMap(1);
}

void xGame::paintMap(int nLvl) {
    mapLayout->setLayout(nLvl);
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            bloc = new xBloc(mapLayout->getBlocName(x,y));
            bloc->setPos(x*32, y*32);
            scene->addItem(bloc);
        }
    }
    heroBloc = new xBloc("hero");
    heroBloc->setPos(mapLayout->getStartX()*32, mapLayout->getStartY()*32); //hero start in x=4,y=10
    scene->addItem(heroBloc);
}

void xGame::moveHero(int nX, int nY) {
    scene->removeItem(heroBloc);
    delete heroBloc;

    heroBloc = new xBloc("hero");
    heroBloc->setPos(nX*32, nY*32); //hero start in x=4,y=10
    scene->addItem(heroBloc);
}
