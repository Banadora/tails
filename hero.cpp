#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QDebug>


extern xGame *game;


xHero::xHero(QString heroName, int nHP, QString nDirection, QString nWeapon) :
    xCharacter(heroName, nHP, nWeapon)
{
    setDirection(nDirection);
    getWeapon()->changeWeapon(nWeapon); //equip a weapon
    getView()->setViewName(heroName + "_" + getDirection() + "_" + getWeapon()->getName());
}

bool xHero::moveView(QString direction)
{
    bool moved;
    setDirection(direction);

    //key up pressed
    if (direction == "north") {
        if (getView()->pos().y()-PixelsMove < 0) { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("north"));
            getView()->setPos(getView()->pos().x(), PixelsY*(nbBlocksY-1));
        }
        getView()->setViewName("hero_back_" + getWeapon()->getName());
    }

    //key down pressed
    else if (direction == "south") {
        if (getView()->y()+PixelsMove > PixelsY*(nbBlocksY-1))   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("south"));
            getView()->setPos(getView()->x(), 0);
        }
        getView()->setViewName("hero_front_" + getWeapon()->getName());
    }

    //key left pressed
    else if (direction == "west") {
        if (getView()->pos().x()-PixelsMove < 0)   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("west"));
            getView()->setPos(PixelsX*(nbBlocksX-1), getView()->pos().y());
        }
        getView()->setViewName("hero_left_" + getWeapon()->getName());
    }

    //key right pressed
    else if (direction == "east") {
        if (getView()->pos().x()+PixelsMove > PixelsX*(nbBlocksX-1))   { //changing map
            game->mapLayout->loadMap(game->mapLayout->getNextMap("east"));
            getView()->setPos(0, getView()->pos().y());
        }
        getView()->setViewName("hero_right_" + getWeapon()->getName());
    }

    //try move
    moved = xCharacter::moveView(direction);

    //if hero is attacking, still move but remove weapon's animation
    if (getIsAttacking()) { game->scene->removeItem(getWeapon()->getAttackAnim()->getAnimView()); }

    return moved;
}

void xHero::attack() {
    //create & play new anim + change hero's view to no weapon during anim
    if (getView()->getViewName().contains("back")) {
        setAttackAngle(-90);
        setAttackPos(QPointF(getView()->pos().x() + PixelsX/2 - 16, getView()->pos().y() + PixelsY/2));
    }
    else if (getView()->getViewName().contains("front")) {
        setAttackAngle(90);
        setAttackPos(QPointF(getView()->pos().x() + PixelsX/2 + 16, getView()->pos().y() + PixelsY/2));
    }
    else if (getView()->getViewName().contains("right")) {
        setAttackAngle(0);
        setAttackPos(QPointF(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 - 16));
    }
    else if (getView()->getViewName().contains("left")) {
        setAttackAngle(180);
        setAttackPos(QPointF(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 + 16));
    }
    else {
        setAttackAngle(0);
        setAttackPos(QPointF(getView()->pos().x(), getView()->pos().y()));
    }

    //remove weapon's name from view's name + replace with none
    getView()->setViewName(getView()->getViewName().replace(getWeapon()->getName(), "none"));

    getWeapon()->setAttackAnim(getWeapon()->getName(), "attack", 150, 0, 15);
}

bool xHero::checkAttack()
{
    //check if anim collides with an enemy, return true if enemy took a shot
    xCharacterView *ev = new xCharacterView(nullptr, ""); //pointer to enemies' views

    QList<QGraphicsItem *> colliding_items = getWeapon()->getAttackAnim()->getAnimView()->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) {

            ev = qgraphicsitem_cast<xCharacterView *>(colliding_items[i]);

            if (ev->getViewName().contains("hero") == false) { //delete character objects (with associated views)
                xEnemy *e = dynamic_cast<xEnemy *>(ev->getParent());
                e->takeDmg(getWeapon()->getDmg());
                qDebug() << "enemy's HP : " << e->getHP();
                //if enemy has no life, delete it
                if (e->getHP() <= 0) {
                    if (e->getIsAttacking()) {
                        e->getWeapon()->getAttackAnim()->getTimeline()->stop();
                        //delete e->getWeapon()->getAttackAnim()->getAnimView();
                        game->scene->removeItem(e->getWeapon()->getAttackAnim()->getAnimView());
                    }
                    delete e;
                }

                return true;
            }
        }
    }

    return false;
}
