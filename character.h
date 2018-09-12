#ifndef CHARACTER_H
#define CHARACTER_H

#include "characterview.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter {

    QString name;
    xCharacterView view;

public:
    xCharacter(QString nName);

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    void move(QString direction);

    void setName(QString nName);
    QString getName();
};

#endif // CHARACTER_H
