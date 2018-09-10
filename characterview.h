#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xCharacterView : public QGraphicsPixmapItem {

public:
    xCharacterView();

    void move(QString direction);
};

#endif // CHARACTERVIEW_H
