#include "blockhero.h"
#include "game.h"

extern xGame *game;

////////// get pressed key and take actions (only on focused item)
xBlockHero::xBlockHero(QString blocName) :
    xBlock(blocName)
{ }

void xBlockHero::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if (     (y > 0)       &&    (game->activeBlocks[x][y-1]->isObstacle() == false)      ) {
            setPos(x*PixelsX, (y-1)*PixelsY);
            setY(y-1);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (     (y+1 < 12)    &&    (game->activeBlocks[x][y+1]->isObstacle() == false)      ) {
            setPos(x*PixelsX, (y+1)*PixelsY);
            setY(y+1);
        }
    }
    else if (event->key() == Qt::Key_Left) {
        if (     (x > 0)       &&    (game->activeBlocks[x-1][y]->isObstacle() == false)      ) {
            setPos((x-1)*PixelsX, y*PixelsY);
            setX(x-1);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (     (x+1 < 12)    &&    (game->activeBlocks[x+1][y]->isObstacle() == false)      ) {
            setPos((x+1)*PixelsX, y*PixelsY);
            setX(x+1);
        }
    }
    else if (event->key() == Qt::Key_Space) {  }
}
