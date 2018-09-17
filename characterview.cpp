#include "characterview.h"
#include "block.h"
#include "enemy.h"
#include "game.h"

#include <QDebug>


extern xGame *game;


xCharacterView::xCharacterView(QObject *parent)
{ }

xCharacterView::xCharacterView(QString viewName) :
    name(viewName)
{
    setPixmap(QPixmap(":/img/" + viewName));
}

QString xCharacterView::getViewName() { return name; }

//move char on scene, return true if OK, false if the char didn't move (eg:obstacle)
bool xCharacterView::move(QString direction) {

    QPointF oldPos(pos().x(), pos().y());

    //key up pressed
    if (direction == "north") {
        if (    (pos().y()-PixelsMove < 0)      &&      (pos() == game->hero->getView()->pos())     ) { //changing map
            game->clearEnemies();
            game->mapLayout->loadMap(game->mapLayout->getNextMap("north"));
            setPos(pos().x(), PixelsY*(nbBlocksY-1));
        }
        else { //moving
            setPos(pos().x(), pos().y()-PixelsMove);
            if (name.contains("hero")) { setPixmap(QPixmap(":/img/hero_back.png")); }
        }
    }

    //key down pressed
    else if (direction == "south") {
        if (    (pos().y()+PixelsMove > PixelsY*(nbBlocksY-1))      &&      (pos() == game->hero->getView()->pos())     )   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("south"));
            setPos(pos().x(), 0);
        }
        else { //moving
            setPos(pos().x(), pos().y()+PixelsMove);
            if (name.contains("hero")) { setPixmap(QPixmap(":/img/hero_front.png")); }
        }
    }

    //key left pressed
    else if (direction == "west") {
        if (    (pos().x()-PixelsMove < 0)      &&      (pos() == game->hero->getView()->pos())     )   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("west"));
            setPos(PixelsX*(nbBlocksX-1), pos().y());
        }
        else { //moving
            setPos(pos().x()-PixelsMove, pos().y());
            if (name.contains("hero")) { setPixmap(QPixmap(":/img/hero_left.png")); }
        }
    }

    //key right pressed
    else if (direction == "east") {
        if (    (pos().x()+PixelsMove > PixelsX*(nbBlocksX-1))      &&      (pos() == game->hero->getView()->pos())     )   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("east"));
            setPos(0, pos().y());
        }
        else { //moving
            setPos(pos().x()+PixelsMove, pos().y());
            if (name.contains("hero")) { setPixmap(QPixmap(":/img/hero_right.png")); }
        }
    }

    //check is new pos is on obstacle, if true get back to old pos
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xBlock)) {
            if (dynamic_cast<xBlock*>(colliding_items[i])->getIsObstacle()) { setPos(oldPos); return false;}
        }
        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) { setPos(oldPos); return false; }
    }

    return true;
}
