#include "enemy.h"
#include "game.h"

#include <QTime>
#include <QGraphicsPixmapItem>
#include <QDebug>


extern xGame *game;


xEnemy::xEnemy(QString enemyName, int nHP, QString nWeapon) :
    xCharacter(enemyName, nHP, nWeapon)
{
    getWeapon()->changeWeapon(nWeapon); //equip a weapon

    //connect timers
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(randMove()));
    moveTimer->start(800);
}

QLineF xEnemy::getDistanceLine() {
    QPointF enemyPos(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2);
    QPointF heroPos(game->hero->getView()->pos().x() + PixelsX/2, game->hero->getView()->pos().y() + PixelsY/2);
    QLineF ln(enemyPos, heroPos);
    return ln;
}

bool xEnemy::checkAttack()
{
    //check if anim collides with an hero, return true if hero took a shot
    xCharacterView *hv = new xCharacterView(nullptr, ""); //pointer to hero's view

    QList<QGraphicsItem *> colliding_items = getWeapon()->getAttackAnim()->getAnimView()->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {

        if (typeid(*(colliding_items[i])) == typeid(xCharacterView)) {

            hv = qgraphicsitem_cast<xCharacterView *>(colliding_items[i]);

            if (hv->getViewName().contains("hero") == true) { //delete character objects (with associated views)
                xHero *h = dynamic_cast<xHero *>(hv->getParent());
                h->takeDmg(getWeapon()->getDmg());
                qDebug() << "hero's HP : " << h->getHP();

                return true;
            }
        }
    }

    return false;
}

void xEnemy::randMove() {
    //check distance between enemy and hero then stop moving and switch to attack if hero is close
    double ln = getDistanceLine().length();
    if (ln < 36) {
        attack();
        return;
    }

    qsrand(QTime::currentTime().msec()); //always get new seed for qrand()

    bool moved = false;
    int i = 0;
    while (!moved) {
        int randDirection = qrand() % 4;
        if (randDirection == 0) { moved = moveView("north"); }
        else if (randDirection == 1) { moved = moveView("east"); }
        else if (randDirection == 2) { moved = moveView("south"); }
        else if (randDirection == 3) { moved = moveView("west"); }
        i++;
        if (i>10) { return; } //if enemy can't move in any direction, go out of func to reboot and to not freeze the program
    }
}

void xEnemy::attack() {
    //create & play new anim
    setAttackAngle((getDistanceLine().angle() * -1) - 20);
    QPointF pt(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2);
    setAttackPos(pt);

    getWeapon()->setAttackAnim(getWeapon()->getName(), "attack", 500, 0, 15);
}
