#include "characterview.h"
#include "block.h"
#include "game.h"

#include <QDebug>


extern xGame *game;

////////// get direction from eventfilter and take actions
xCharacterView::xCharacterView()
{
    setPixmap(QPixmap(":/img/hero.png"));
}

void xCharacterView::move(QString direction) {

    //key up pressed
    if (direction == "north") {
        if (pos().y()-PixelsMove < 0) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("north"));
            setPos(pos().x(), PixelsY*(nbBlocksY-1));
        }
        else {
            xBlock *topleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x(), pos().y()-PixelsMove), QTransform()));
            xBlock *topright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1, pos().y()-PixelsMove), QTransform()));
            if (    (topleft->getIsObstacle() == false) && (topright->getIsObstacle() == false)    )  { setPos(pos().x(), pos().y()-PixelsMove); }
        }
    }

    //key down pressed
    else if (direction == "south") {
        if (pos().y()+PixelsMove > PixelsY*(nbBlocksY-1)) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("south"));
            setPos(pos().x(), 0);
        }
        else {
            xBlock *bottomleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x(), pos().y()+PixelsY-1+PixelsMove), QTransform()));
            xBlock *bottomright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1, pos().y()+PixelsY-1+PixelsMove), QTransform()));
            if (    (bottomleft->getIsObstacle() == false) && (bottomright->getIsObstacle() == false)    )  { setPos(pos().x(), pos().y()+PixelsMove); }
        }
    }

    //key left pressed
    else if (direction == "west") {
        if (pos().x()-PixelsMove < 0) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("west"));
            setPos(PixelsX*(nbBlocksX-1), pos().y());
        }
        else {
            xBlock *topleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()-PixelsMove, pos().y()), QTransform()));
            xBlock *bottomleft = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()-PixelsMove, pos().y()+PixelsY-1), QTransform()));
            if (    (topleft->getIsObstacle() == false) && (bottomleft->getIsObstacle() == false)    )  { setPos(pos().x()-PixelsMove, pos().y()); }
        }
    }

    //key right pressed
    else if (direction == "east") {
        if (pos().x()+PixelsMove > PixelsX*(nbBlocksX-1)) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("east"));
            setPos(0, pos().y());
        }
        else {
            xBlock *topright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1+PixelsMove, pos().y()), QTransform()));
            xBlock *bottomright = dynamic_cast<xBlock*>(game->scene->itemAt(QPointF(pos().x()+PixelsX-1+PixelsMove, pos().y()+PixelsY-1), QTransform()));
            if (    (topright->getIsObstacle() == false) && (bottomright->getIsObstacle() == false)    )  { setPos(pos().x()+PixelsMove, pos().y()); }
        }
    }

}
