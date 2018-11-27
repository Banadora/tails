#include "characterview.h"
#include "block.h"
#include "enemy.h"
#include "game.h"

#include <QDebug>


extern xGame *game;


xCharacterView::xCharacterView()
{ }

xCharacterView::xCharacterView(QObject *parent, QString viewName) :
    p(parent),
    name(viewName)
{
    setPixmap(QPixmap(":/img/" + viewName));
}

QObject* xCharacterView::getParent() { return p; }

QString xCharacterView::getViewName() { return name; }

void xCharacterView::setViewName(QString nName)
{
    name = nName;
    setPixmap(QPixmap(":/img/" + name + ".png"));
}

//move char on scene, return true if OK, false if the char didn't move (eg:obstacle)
bool xCharacterView::move(QString direction) {

    QPointF oldPos(pos().x(), pos().y());

    //key up pressed
    if (direction == "north") {
        if (    (pos().y()-PixelsMove < 0)      &&      (pos() == game->hero->getView()->pos())     ) { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("north"));
            setPos(pos().x(), PixelsY*(nbBlocksY-1));
        }
        else { //moving
            setPos(pos().x(), pos().y()-PixelsMove);
            if (name.contains("hero")) {
                game->hero->setDirection("back");
                setViewName("hero_back_" + game->hero->getWeapon()->getName());
            }
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
            if (name.contains("hero")) {
                game->hero->setDirection("front");
                setViewName("hero_front_" + game->hero->getWeapon()->getName());
            }
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
            if (name.contains("hero")) {
                game->hero->setDirection("left");
                setViewName("hero_left_" + game->hero->getWeapon()->getName());
            }
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
            if (name.contains("hero")) {
                game->hero->setDirection("right");
                setViewName("hero_right_" + game->hero->getWeapon()->getName());
            }
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

    //if hero is attacking, still move but remove weapon's animation
    if (game->hero->getIsAttacking()) { game->scene->removeItem(game->hero->getWeapon()->getAttackAnim()->getAnimView()); }

    return true;
}
