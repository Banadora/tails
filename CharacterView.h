#ifndef _CHARACTERVIEW_H
#define _CHARACTERVIEW_H


#include <QGraphicsPixmapItem>

#include <QString>

#include <QKeyEvent>

#include "Directions.h"

class CharacterView : public QGraphicsPixmapItem {
  public:
    CharacterView(const QString & QItemName);

    void keyPressEvent(const QKeyEvent * event);

    void move(int x, int y);

    void setFacingDirection(Directions direction);

    void move(Directions direction);

};
#endif
