#include "enemy.h"
#include "game.h"

#include <QTime>
#include <QGraphicsPixmapItem>
#include <QDebug>


extern xGame *game;


xEnemy::xEnemy(QObject *parent, QString enemyName, int nHP, QString nWeapon) :
    xCharacter(parent, enemyName, nHP, nWeapon)
{
    getWeapon()->changeWeapon(nWeapon); //equip a weapon

    animView = new QGraphicsPixmapItem;
    animView->setZValue(12);

    //connect timers
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(randMove()));
    moveTimer->start(800);

    attackTimer = new QTimer;
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attack()));

    animTimer = new QTimer;
    connect(animTimer, SIGNAL(timeout()), this, SLOT(animation()));
}

QLineF xEnemy::getDistanceLine() {
    QPointF enemyPos(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2);
    QPointF heroPos(game->hero->getView()->pos().x() + PixelsX/2, game->hero->getView()->pos().y() + PixelsY/2);
    QLineF ln(enemyPos, heroPos);
    return ln;
}


QGraphicsPixmapItem* xEnemy::getAnimView() { return animView; }

void xEnemy::randMove() {
    //check distance between enemy and hero then stop moving and switch to attack if hero is close
    double ln = getDistanceLine().length();
    if (ln < 36) {
        moveTimer->stop();


        game->scene->addItem(animView);
        animTimer->start(450);

        attackTimer->start(1000);
        qDebug()<< "attacked!";
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
    //check distance between enemy and hero then stop attacking and switch to moving if hero is far
    double ln = getDistanceLine().length();
    if (ln > 36) {
        attackTimer->stop();

        game->scene->removeItem(animView);
        animTimer->stop();

        moveTimer->start(800);
        qDebug()<< "moving!";
        return;
    }

    game->hero->takeDmg(getWeapon()->getDmg());
    qDebug() << "hero's HP : " << game->hero->getHP();
}

void xEnemy::animation() {
    //set angle
    double angle = getDistanceLine().angle() * -1;
    //animView->setTransformOriginPoint(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2);
    animView->setTransformOriginPoint(animView->pos().x() + 9.5, animView->pos().x() + 6);
    animView->setRotation(angle);
    animView->setTransformOriginPoint(0, 0);
    //on/off
    if (animToken == 1) {
        animView->setPixmap(QPixmap(":/anim/" + getWeapon()->getName() + ".png"));
        animView->setPos(getView()->pos().x() + PixelsX/2 + getDistanceLine().dx()/3, getView()->pos().y() + PixelsY/2+ getDistanceLine().dy()/3);
        animToken = 0;
    }
    else {
        animView->setPixmap(QPixmap(""));
        animView->setPos(getView()->pos().x() + PixelsX/2 + getDistanceLine().dx()/4, getView()->pos().y() + PixelsY/2+ getDistanceLine().dy()/4);
        animToken = 1;
    }
}
