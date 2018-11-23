#include "hero.h"
#include "game.h"

#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QDebug>

extern xGame *game;


xHero::xHero(QObject *parent, QString heroName, QString nDirection, QString nWeapon) :
    xCharacter(parent, heroName),
    hp(100),
    weapon(nWeapon),
    direction(nDirection)
{
    getView()->setViewName(heroName + "_" + direction + "_" + weapon);


}

int xHero::getHP() { return hp; }
void xHero::setHP(int nHP) { hp = nHP; }

void xHero::setDirection(QString nDirection) { direction = nDirection; }
QString xHero::getDirection() { return direction; }

QString xHero::getWeapon() { return weapon; }

void xHero::getDamaged(int dmg) {
    hp -= dmg;
}

void xHero::attack() {
    //play anim and change hero's view to no weapon during anim
    anim = new xAnimation("staff", 0, 35);
    getView()->setViewName(getName() + "_" + direction + "_" + "none");
    game->scene->addItem(anim->getAnimView());
    hit = false;
    anim->startAnim();

    //add anim to scene then check if hitting an enemy, if already hitted during animation, don't check anymore
    if (hit == false) { hit = checkAttack(); }
}

bool xHero::checkAttack()
{
    //check if anim collides with an enemy, return true if enemy took a shot
    xCharacterView *ev = new xCharacterView(nullptr, ""); //pointer to enemies' views

    QList<QGraphicsItem *> colliding_items = anim->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) {
            ev = qgraphicsitem_cast<xCharacterView *>(colliding_items[i]);
            //qDebug() << ev->getViewName() << ev->getParent();
            if (ev->getViewName().contains("hero") == false) { //delete character objects (with associated views)
                xEnemy *e = dynamic_cast<xEnemy *>(ev->getParent());
                e->getDamaged(50);
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
