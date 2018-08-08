
#include "game.h"

/*QWidget *parent*/
xGame::xGame(int viewWidth, int viewHeight) {

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,viewWidth,viewHeight);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //paint map
    mapLayout = new xMapLayout;
    mapLayout->setLayout(1);
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            bloc = new xBloc(mapLayout->getBlocName(x,y));
            bloc->setPos(x*32,y*32);
            scene->addItem(bloc);
        }
    }
    heroBloc = new xBloc("hero");
    heroBloc->setPos(4*32,10*32); //hero start in x=4,y=10
    scene->addItem(heroBloc);

}

void xGame::paintMap(int nLvl) {

}
