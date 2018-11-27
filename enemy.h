#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QTimer>

class xEnemy : public xCharacter {

    Q_OBJECT

    QGraphicsPixmapItem *animView;

    QTimer *moveTimer;
    QTimer *attackTimer;
    QTimer *animTimer;

    bool animToken = 1;

public:
    xEnemy(QString enemyName="unknown", int nHP=100, QString nWeapon="none");

    QLineF getDistanceLine();

    QGraphicsPixmapItem *getAnimView();

    bool checkAttack();

public slots:
    void randMove();
    void attack();
    void animation();
};

#endif // ENEMY_H
