#ifndef CHARACTER_H
#define CHARACTER_H

#include "characterview.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter {

    xCharacterView view;

public:
    xCharacter();

    void setViewPos(int nX, int nY);
    xCharacterView* getView();
    void move(QString direction);
};

#endif // CHARACTER_H
