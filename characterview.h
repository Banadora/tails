#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xCharacterView : public QGraphicsPixmapItem {

    QString name;
    QObject *p; //parent object

public:
    xCharacterView();
    xCharacterView(QObject *parent=nullptr, QString viewName="");

    QObject* getParent();

    QString getViewName();
    bool move(QString direction);
};

#endif // CHARACTERVIEW_H
