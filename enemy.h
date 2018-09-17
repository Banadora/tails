#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QTimer>

class xEnemy : public QObject, public xCharacter {

    Q_OBJECT

    QGraphicsPixmapItem *animView;

    QTimer *moveTimer;
    QTimer *attackTimer;
    QTimer *animTimer;

    bool animToken = 1;

public:
    xEnemy(QString enemyName="unknown");

    QLineF getDistanceLine();

public slots:
    void randMove();
    void attack();
    void animation();
};

#endif // ENEMY_H
