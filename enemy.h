#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QTimer>

class xEnemy : public xCharacter {

    Q_OBJECT

    QTimer *moveTimer;

public:
    xEnemy(QString enemyName="unknown", int nHP=100, QString nWeapon="none");

    QLineF getDistanceLine();

    void attack();

    bool checkAttack();

public slots:
    void randMove();
};

#endif // ENEMY_H
