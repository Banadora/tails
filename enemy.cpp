#include "enemy.h"

#include <QTime>
#include <QDebug>

xEnemy::xEnemy(QString enemyName) :
    xCharacter(enemyName)
{
    //connect move timer
    movetimer = new QTimer;
    connect(movetimer, SIGNAL(timeout()), this, SLOT(randMove()));
    movetimer->start(800);
}

void xEnemy::randMove() {
    bool moved = false;

    qsrand(QTime::currentTime().msec()); //always get new seed for qrand()

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
