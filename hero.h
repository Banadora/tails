#ifndef HERO_H
#define HERO_H

#include "character.h"

#include <QTimer>

class xHero : public xCharacter {

    Q_OBJECT

    QGraphicsPixmapItem *animView;
    QTimer *stopAnimTimer;

    int hp;
    QString weapon;

    bool hit;

public:
    xHero(QObject *parent=nullptr, QString heroName="heroname");

    int getHP();
    void setHP(int nHP);

    void getDamaged(int dmg);
    void attack();
    bool checkAttack();

    QGraphicsPixmapItem *getAnimView();

public slots:
    void attackAnim(int frame);
    void stopAnim();
};

#endif // HERO_H
