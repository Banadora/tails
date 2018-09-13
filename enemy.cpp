#include "enemy.h"
#include "game.h"

#include <QTime>
#include <QGraphicsPixmapItem>
#include <QDebug>


extern xGame *game;


xEnemy::xEnemy(QString enemyName) :
    xCharacter(enemyName)
{
    //connect timers
    moveTimer = new QTimer;
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(randMove()));
    moveTimer->start(800);

    attackTimer = new QTimer;
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attack()));
}

double xEnemy::getDistance() {
    QPointF enemyPos(getView()->pos().x() + PixelsX/2, getView()->pos().y() + PixelsY/2);
    QPointF heroPos(game->hero->getView()->pos().x() + PixelsX/2, game->hero->getView()->pos().y() + PixelsY/2);
    QLineF ln(enemyPos, heroPos);
    return ln.length();
}

void xEnemy::randMove() {
    //check distance between enemy and hero then stop moving and switch to attack if hero is close
    double d = getDistance();
    if (d < 36) {
        moveTimer->stop();
        attackTimer->start(1000);
        qDebug()<< "attacked!";
        return;
    }

    qsrand(QTime::currentTime().msec()); //always get new seed for qrand()

    bool moved = false;
    int i = 0;
    while (!moved) {
        int randDirection = qrand() % 4;
        if (randDirection == 0) { moved = getView()->move("north"); }
        else if (randDirection == 1) { moved = getView()->move("east"); }
        else if (randDirection == 2) { moved = getView()->move("south"); }
        else if (randDirection == 3) { moved = getView()->move("west"); }
        i++;
        if (i>10) { return; } //if enemy can't move in any direction, go out of func to reboot and to not freeze the program
    }
}

void xEnemy::attack() {
    //check distance between enemy and hero then stop attacking and switch to moving if hero is far
    double d = getDistance();
    if (d > 36) {
        attackTimer->stop();
        moveTimer->start(800);
        qDebug()<< "moving!";
        return;
    }

    game->hero->getDamaged(2);
    qDebug() << "pv: " + QString::number(game->hero->getHP());
}
