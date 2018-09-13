#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QTimer>

class xEnemy : public QObject, public xCharacter {

    Q_OBJECT

    QTimer *moveTimer;
    QTimer *attackTimer;

public:
    xEnemy(QString enemyName="unknown");

    double getDistance();

public slots:
    void randMove();
    void attack();
};

#endif // ENEMY_H
