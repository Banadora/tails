#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QTimer>

class xEnemy : public QObject, public xCharacter {

    Q_OBJECT

    QTimer *movetimer;

public:
    xEnemy(QString enemyName="unknown");

public slots:
    void randMove();
};

#endif // ENEMY_H
