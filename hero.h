#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "animation.h"

//#include <QTimer>

class xHero : public xCharacter {

    Q_OBJECT

    //QGraphicsPixmapItem *animView;
    //QTimer *stopAnimTimer;

    int hp;
    QString weapon;
    QString direction;
    bool hit;

    xAnimation *anim;

public:
    xHero(QObject *parent=nullptr, QString heroName="hero", QString nDirection="front", QString nWeapon="staff");

    int getHP();
    void setHP(int nHP);

    void setDirection(QString nDirection);
    QString getDirection();

    QString getWeapon();

    void getDamaged(int dmg);
    void attack();
    bool checkAttack();

    xAnimation *getAnim();
    //QGraphicsPixmapItem *getAnimView();

//public slots:
    //void attackAnim(int frame);
    //void stopAnim();
};

#endif // HERO_H
