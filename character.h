#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class xCharacter : public QObject, public QGraphicsPixmapItem
{

     Q_OBJECT

public:
    void Character();

    void  moveNorth();
    void  moveEast();
    void  moveSouth();
    void  moveWest();
};

#endif // CHARACTER_H
