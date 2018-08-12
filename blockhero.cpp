#include "block.h"
#include "blockhero.h"
#include "blockexit.h"
#include "game.h"


extern xGame *game;


xBlockHero::xBlockHero(QString blocName) :
    xBlock(blocName)
{ }

////////// get pressed key and take actions (only on focused item)
void xBlockHero::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if (x == game->mapLayout->getExitX() && y == game->mapLayout->getExitY()) {
            xBlockExit exit;
            exit = game->activeBlocks[x][y].get();
            game->mapLayout->setStartX(game->activeBlocks[x][y].get()->getX());
            game->mapLayout->setStartY(nbBlocksY-1);
            game->paintMap(2);
        }
        else {
            if (     (y > 0)       &&    (game->activeBlocks[x][y-1]->isObstacle() == false)     ) { //move only if destination is in map and not an obstacle
                setPos(x*PixelsX, (y-1)*PixelsY);
                setY(y-1);
            }
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (     (y+1 < nbBlocksY)    &&    (game->activeBlocks[x][y+1]->isObstacle() == false)     ) {
            setPos(x*PixelsX, (y+1)*PixelsY);
            setY(y+1);
        }
    }
    else if (event->key() == Qt::Key_Left) {
        if (     (x > 0)       &&    (game->activeBlocks[x-1][y]->isObstacle() == false)     ) {
            setPos((x-1)*PixelsX, y*PixelsY);
            setX(x-1);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (     (x+1 < nbBlocksX)    &&    (game->activeBlocks[x+1][y]->isObstacle() == false)     ) {
            setPos((x+1)*PixelsX, y*PixelsY);
            setX(x+1);
        }
    }
    else if (event->key() == Qt::Key_Space) {  }
}
