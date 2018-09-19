#ifndef HERO_H
#define HERO_H

#include "character.h"

#include <QTimer>

class xHero : public xCharacter {

    Q_OBJECT

    QGraphicsPixmapItem *animView;
    QTimer *stopAnimTimer;

    int hp;

public:
    xHero(QObject *parent=nullptr, QString heroName="heroname");

    int getHP();
    void setHP(int nHP);

    void getDamaged(int dmg);
    void attack();
    void attackAnim();

public slots:
    void stopAnim();
};

#endif // HERO_H
