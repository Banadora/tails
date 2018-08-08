
#include "game.h"

/*QWidget *parent*/
xGame::xGame() {
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,32,32); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(200,150);

    // create the player
    bloc = new xBloc();
    bloc->setPos(0,0); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    bloc->setFlag(QGraphicsItem::ItemIsFocusable);
    bloc->setFocus();
    // add the player to the scene
    scene->addItem(bloc);

}
