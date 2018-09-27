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
    QString direction;

    bool hit;

public:
    xHero(QObject *parent=nullptr, QString heroName="hero", QString nDirection="front", QString nWeapon="staff");

    int getHP();
    void setHP(int nHP);

    QString getWeapon();

    void setDirection(QString nDirection);

    void getDamaged(int dmg);
    void attack();
    bool checkAttack();

    QGraphicsPixmapItem *getAnimView();

public slots:
    void attackAnim(int frame);
    void stopAnim();
};

#endif // HERO_H
