#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QDebug>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName, int nHP, QString nDirection, QString nWeapon) :
    xCharacter(parent, heroName, nHP, nWeapon),
    direction(nDirection)
{
    getWeapon()->changeWeapon(nWeapon); //equip a weapon
    getView()->setViewName(heroName + "_" + direction + "_" + getWeapon()->getName());
}

void xHero::setDirection(QString nDirection) { direction = nDirection; }
QString xHero::getDirection() { return direction; }

void xHero::attack() {
    //create & play new anim + change hero's view to no weapon during anim
    anim = new xAnimation(getWeapon()->getName(), "attack", 150, 0, 35);
    getView()->setViewName(getName() + "_" + direction + "_" + "none");
    game->scene->addItem(anim->getAnimView());
    anim->startAnim();
}

bool xHero::checkAttack()
{
    //check if anim collides with an enemy, return true if enemy took a shot
    xCharacterView *ev = new xCharacterView(nullptr, ""); //pointer to enemies' views

    QList<QGraphicsItem *> colliding_items = anim->getAnimView()->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) {
            ev = qgraphicsitem_cast<xCharacterView *>(colliding_items[i]);
            //qDebug() << ev->getViewName() << ev->getParent();
            if (ev->getViewName().contains("hero") == false) { //delete character objects (with associated views)
                xEnemy *e = dynamic_cast<xEnemy *>(ev->getParent());
                e->takeDmg(50);
                qDebug() << "enemy's HP : " << e->getHP();
                //if enemy has no life, delete it
                if (e->getHP() <= 0) { delete e->getAnimView(); delete e; }
                return true;
            }
        }
    }
    return false;
}

xAnimation *xHero::getAnim() { return anim; }
