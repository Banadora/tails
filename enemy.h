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

    int hp;

public:
    xEnemy(QObject *parent=nullptr, QString enemyName="unknown");

    QLineF getDistanceLine();

    int getHP();
    void setHP(int nHP);

    void getDamaged(int dmg);

public slots:
    void randMove();
    void attack();
    void animation();
};

#endif // ENEMY_H
