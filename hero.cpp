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

void xHero::attack() {
    //create & play new anim + change hero's view to no weapon during anim
    if (getView()->getViewName().contains("back")) {
        setAttackAngle(-115);
        QPointF pt(getView()->pos().x() + PixelsX/2 - 6, getView()->pos().y() + PixelsY/2);
        setAttackPos(pt);
    }
    else if (getView()->getViewName().contains("front")) {
        setAttackAngle(65);
        QPointF pt(getView()->pos().x() + PixelsX/2 + 6, getView()->pos().y() + PixelsY/2);
        setAttackPos(pt);
    }
    else if (getView()->getViewName().contains("right")) {
        setAttackAngle(-25);
        QPointF pt(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 - 6);
        setAttackPos(pt);
    }
    else if (getView()->getViewName().contains("left")) {
        setAttackAngle(155);
        QPointF pt(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2 + 6);
        setAttackPos(pt);
    }
    else {
        setAttackAngle(0);
        QPointF pt(getView()->pos().x(), getView()->pos().y());
        setAttackPos(pt);
    }

    getView()->setViewName(getName() + "_" + getDirection() + "_" + "none");
    getWeapon()->setAttackAnim(getWeapon()->getName(), "attack", 150, 0, 35);
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
                        delete e->getWeapon()->getAttackAnim()->getAnimView();
                    }
                    delete e;
                }

                return true;
            }
        }
    }

    return false;
}
