#ifndef CHARACTER_H
#define CHARACTER_H

#include "characterview.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter : public QObject {

    QString name;

    xCharacterView view;

    bool isAttacking;

public:
    xCharacter(QObject *parent=nullptr, QString nName="");

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    bool moveView (QString direction);

    void setName(QString nName);
    QString getName();

    void setIsAttacking(bool nIsAttacking);
    bool getIsAttacking();
};

#endif // CHARACTER_H
