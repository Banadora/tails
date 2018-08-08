
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
    for (int i = 0; i < 12; i++) {
        for (int y = 0; y < 12; y++) {
            bloc = new xBloc("grass0");
            bloc->setPos(i*32,y*32);
            scene->addItem(bloc);
        }
    }
}
