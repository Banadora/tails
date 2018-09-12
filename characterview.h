#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xCharacterView : public QGraphicsPixmapItem {

    QString name;

public:
    xCharacterView();
    xCharacterView(QString viewName);

    QString getViewName();
    bool move(QString direction);
};

#endif // CHARACTERVIEW_H
