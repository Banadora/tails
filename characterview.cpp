#include "characterview.h"
#include "block.h"
#include "game.h"

#include <QDebug>


extern xGame *game;

////////// get direction from eventfilter and take actions
xCharacterView::xCharacterView(QString viewName)
{
    setPixmap(QPixmap(":/img/" + viewName));
}

void xCharacterView::move(QString direction) {

    QPointF oldPos(pos().x(), pos().y());

    //key up pressed
    if (direction == "north") {
        if (pos().y()-PixelsMove < 0) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("north"));
            setPos(pos().x(), PixelsY*(nbBlocksY-1));
        }
        else { setPos(pos().x(), pos().y()-PixelsMove); }
    }

    //key down pressed
    else if (direction == "south") {
        if (pos().y()+PixelsMove > PixelsY*(nbBlocksY-1)) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("south"));
            setPos(pos().x(), 0);
        }
        else { setPos(pos().x(), pos().y()+PixelsMove); }
    }

    //key left pressed
    else if (direction == "west") {
        if (pos().x()-PixelsMove < 0) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("west"));
            setPos(PixelsX*(nbBlocksX-1), pos().y());
        }
        else { setPos(pos().x()-PixelsMove, pos().y()); }
    }

    //key right pressed
    else if (direction == "east") {
        if (pos().x()+PixelsMove > PixelsX*(nbBlocksX-1)) {
            game->mapLayout->loadMap(game->mapLayout->getNextMap("east"));
            setPos(0, pos().y());
        }
        else { setPos(pos().x()+PixelsMove, pos().y()); }
    }

    //check is new pos is on obstacle, if true get back to old pos
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            if (dynamic_cast<xBlock*>(colliding_items[i])->getIsObstacle()) { setPos(oldPos); }
        }
    }
}
