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

    double attackAngle;
    QPointF attackPos;

    bool isAttacking;

public:
    xCharacter(QString nName="", int nHP=100, QString nWeapon="none");

    void setName(QString nName);
    QString getName();

    int getHP();
    void setHP(int nHP);

    xWeapon* getWeapon();

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    bool moveView (QString direction);

    void setDirection(QString nDirection);
    QString getDirection();

    void setAttackAngle(double nAngle);
    double getAttackAngle();

    void setAttackPos(QPointF nPos);
    QPointF getAttackPos();

    void setIsAttacking(bool nIsAttacking);
    bool getIsAttacking();

    void takeDmg(int dmg);

    virtual bool checkAttack();
};

#endif // CHARACTER_H
