#include "bloc.h"
#include "game.h"

#include <QDebug>

extern xGame *game;

xBloc::xBloc(QString blocName) :
        obstacle(false)
{
    setPixmap(QPixmap(":/img/" + blocName + ".png"));
    defineIfObstacle(blocName);
}

void xBloc::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if (     (y > 0)       &&    (game->activeBlocs[x][y-1]->isObstacle() == false)      ) {
            setPos(x*32, (y-1)*32);
            setY(y-1);
        }
    }
    else if (event->key() == Qt::Key_Down) {
        if (     (y+1 < 12)    &&    (game->activeBlocs[x][y+1]->isObstacle() == false)      ) {
            setPos(x*32, (y+1)*32);
            setY(y+1);
        }
    }
    else if (event->key() == Qt::Key_Left) {
        if (     (x > 0)       &&    (game->activeBlocs[x-1][y]->isObstacle() == false)      ) {
            setPos((x-1)*32, y*32);
            setX(x-1);
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (     (x+1 < 12)    &&    (game->activeBlocs[x+1][y]->isObstacle() == false)      ) {
            setPos((x+1)*32, y*32);
            setX(x+1);
        }
    }
    else if (event->key() == Qt::Key_Space) {  }
}

void xBloc::setName(QString nName) { name = nName;}
QString xBloc::getName() { return name; }

void xBloc::setX(int nX) { x = nX; }
void xBloc::setY(int nY) { y = nY; }

int xBloc::getX() { return x; }
int xBloc::getY() { return y; }

void xBloc::defineIfObstacle(QString blocName) {
    if (blocName == "grass1") { obstacle = true; }
}

bool xBloc::isObstacle() { return obstacle; }


