#ifndef CHARACTER_H
#define CHARACTER_H

#include "characterview.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter : public QObject {

    QString name;
    int hp;
    QString weapon;

    xCharacterView view;

    bool isAttacking;

public:
    xCharacter(QObject *parent=nullptr, QString nName="", int nHP=100, QString nWeapon="none");

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    bool moveView (QString direction);

    void setName(QString nName);
    QString getName();

    int getHP();
    void setHP(int nHP);

    QString getWeapon();
    void setWeapon(QString nWeapon);

    void takeDmg(int dmg);

    void setIsAttacking(bool nIsAttacking);
    bool getIsAttacking();
};

#endif // CHARACTER_H
