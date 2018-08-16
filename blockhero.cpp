#include "blockhero.h"
#include "game.h"
#include "block.h"


#include <QDebug>

extern xGame *game;


xBlockHero::xBlockHero(QString blocName) :
    xBlock(blocName)
{ }

////////// get pressed key and take actions (only on focused item)
void xBlockHero::keyPressEvent(QKeyEvent *event) {

    //key up pressed
    if (event->key() == Qt::Key_Up) {

        xBlock *topleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x(), pos().y()-PixelsMove), QTransform()));
        xBlock *topright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1, pos().y()-PixelsMove), QTransform()));
        if (    (topleft->isObstacle() == false) && (topright->isObstacle() == false)    )  { setPos(pos().x(), pos().y()-PixelsMove); }
    }

    //key down pressed
    else if (event->key() == Qt::Key_Down) {

        xBlock *bottomleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x(), pos().y()+PixelsY-1+PixelsMove), QTransform()));
        xBlock *bottomright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1, pos().y()+PixelsY-1+PixelsMove), QTransform()));
        if (    (bottomleft->isObstacle() == false) && (bottomright->isObstacle() == false)    )  { setPos(pos().x(), pos().y()+PixelsMove); }
    }

    //key left pressed
    else if (event->key() == Qt::Key_Left) {

        xBlock *topleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()-PixelsMove, pos().y()), QTransform()));
        xBlock *bottomleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()-PixelsMove, pos().y()+PixelsY-1), QTransform()));
        if (    (topleft->isObstacle() == false) && (bottomleft->isObstacle() == false)    )  { setPos(pos().x()-PixelsMove, pos().y()); }
    }

    //key right pressed
    else if (event->key() == Qt::Key_Right) {

        xBlock *topright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1+PixelsMove, pos().y()), QTransform()));
        xBlock *bottomright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1+PixelsMove, pos().y()+PixelsY-1), QTransform()));
        if (    (topright->isObstacle() == false) && (bottomright->isObstacle() == false)    )  { setPos(pos().x()+PixelsMove, pos().y()); }
    }


    else if (event->key() == Qt::Key_Space) {  }
}
