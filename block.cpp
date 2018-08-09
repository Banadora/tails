#include "block.h"
#include "game.h"

#include <QDebug>

extern xGame *game;

////////// init
xBlock::xBlock(QString blockName) :
        obstacle(false)
{
    setPixmap(QPixmap(":/img/" + blockName + ".png"));
    defineIfObstacle(blockName);
}

////////// get pressed key and take actions (only on focused item)
void xBlock::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if (     (y > 0)       &&    (game->activeBlocks[x][y-1]->isObstacle() == false)      ) {
            setPos(x*32, (y-1)*32);
            setY(y-1);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (     (y+1 < 12)    &&    (game->activeBlocks[x][y+1]->isObstacle() == false)      ) {
            setPos(x*32, (y+1)*32);
            setY(y+1);
        }
    }
    else if (event->key() == Qt::Key_Left) {
        if (     (x > 0)       &&    (game->activeBlocks[x-1][y]->isObstacle() == false)      ) {
            setPos((x-1)*32, y*32);
            setX(x-1);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (     (x+1 < 12)    &&    (game->activeBlocks[x+1][y]->isObstacle() == false)      ) {
            setPos((x+1)*32, y*32);
            setX(x+1);
        }
    }
    else if (event->key() == Qt::Key_Space) {  }
}

void xBlock::setName(QString nName) { name = nName;}
QString xBlock::getName() { return name; }

void xBlock::setX(int nX) { x = nX; }
void xBlock::setY(int nY) { y = nY; }

int xBlock::getX() { return x; }
int xBlock::getY() { return y; }

////////// when created, define if a certain block is an obstacle
void xBlock::defineIfObstacle(QString blockName) {
    if (blockName == "grass1") { obstacle = true; }
}

bool xBlock::isObstacle() { return obstacle; }


