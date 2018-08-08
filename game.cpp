
#include "game.h"

/*QWidget *parent*/
xGame::xGame(int viewWidth, int viewHeight) {
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,viewWidth,viewHeight); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(157,157);
    //setScene(scene);

    bloc = new xBloc();
    bloc->setPos(0,0); // TODO generalize to always be in the middle bottom of screen

    bloc->setFlag(QGraphicsItem::ItemIsFocusable);
    bloc->setFocus();

    scene->addItem(bloc);

}
