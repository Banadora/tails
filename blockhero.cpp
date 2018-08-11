#include "blockhero.h"
#include "game.h"

#include <QDebug>

extern xGame *game;


xBlockHero::xBlockHero(QString blocName) :
    xBlock(blocName)
{ }

////////// get pressed key and take actions (only on focused item)
void xBlockHero::keyPressEvent(QKeyEvent *event) {

    //key up pressed
    if (event->key() == Qt::Key_Up) {
        if (    (typeid(*(game->activeBlocks[x][y])) == typeid(xBlockExit))  &&  (y-1 < 0)     ) { //exit map if on exitbloc AND destinationbloc is out of map
            qDebug() << "Is on Exit block";
            game->mapLayout->setStartX(game->activeBlocks[x][y]->getDestinationX());
            game->mapLayout->setStartY(game->activeBlocks[x][y]->getDestinationY());
            game->paintMap(game->activeBlocks[x][y]->getDestinationLayout());
        }
        else {
            if (     (y > 0)       &&    (game->activeBlocks[x][y-1]->isObstacle() == false)     ) { //move only if destination is in map and not an obstacle
                setPos(x*PixelsX, (y-1)*PixelsY);
                setY(y-1);
            }
        }
    }

    //key down pressed
    else if (event->key() == Qt::Key_Down) {
        if (    (typeid(*(game->activeBlocks[x][y])) == typeid(xBlockExit))  &&  (y+1 == nbBlocksY)     ) {
            qDebug() << "Is on Exit block";
            game->mapLayout->setStartX(game->activeBlocks[x][y]->getDestinationX());
            game->mapLayout->setStartY(game->activeBlocks[x][y]->getDestinationY());
            game->paintMap(game->activeBlocks[x][y]->getDestinationLayout());
        }
        else {
            if (     (y+1 < nbBlocksY)    &&    (game->activeBlocks[x][y+1]->isObstacle() == false)     ) {
                setPos(x*PixelsX, (y+1)*PixelsY);
                setY(y+1);
            }
        }
    }

    //key left pressed
    else if (event->key() == Qt::Key_Left) {
        if (     (x > 0)       &&    (game->activeBlocks[x-1][y]->isObstacle() == false)     ) {
            setPos((x-1)*PixelsX, y*PixelsY);
            setX(x-1);
        }
    }

    //key right pressed
    else if (event->key() == Qt::Key_Right) {
        if (     (x+1 < nbBlocksX)    &&    (game->activeBlocks[x+1][y]->isObstacle() == false)     ) {
            setPos((x+1)*PixelsX, y*PixelsY);
            setX(x+1);
        }
    }
    else if (event->key() == Qt::Key_Space) {  }
}
