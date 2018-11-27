#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


class xCharacterView : public QGraphicsPixmapItem {

    QObject *p; //parent object

    QString name;

public:
    xCharacterView();
    xCharacterView(QObject *parent=nullptr, QString viewName="");

    QObject* getParent();

    QString getViewName();
    void setViewName(QString nName);
    bool move(QString direction);
};

#endif // CHARACTERVIEW_H
