#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


class xBlock : public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

protected:
    QString name;
    bool obstacle;

public:
    xBlock(QString blockName);

    void setName (QString nName);
    QString getName();

    void defineIfObstacle(QString blockName);
    bool isObstacle();

    //virtual exit funcs:
    virtual int getDestinationLayout() const;
    virtual int getDestinationX() const;
    virtual int getDestinationY() const;
};

#endif // BLOCK_H
