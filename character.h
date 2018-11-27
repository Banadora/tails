#ifndef CHARACTER_H
#define CHARACTER_H

#include "characterview.h"
#include "weapon.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter : public QObject {

    QString name;
    int hp;
    xWeapon weapon;

    xCharacterView view;
    QString direction;

    bool isAttacking;

public:
    xCharacter(QString nName="",
               int nHP=100,
               QString nWeapon="none"
            );

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    bool moveView (QString direction);

    void setDirection(QString nDirection);
    QString getDirection();

    void setName(QString nName);
    QString getName();

    int getHP();
    void setHP(int nHP);

    xWeapon* getWeapon();

    void takeDmg(int dmg);

    void setIsAttacking(bool nIsAttacking);
    bool getIsAttacking();

    virtual bool checkAttack();
};

#endif // CHARACTER_H
