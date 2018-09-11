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
    bool isObstacle;

public:
    xBlock();
    xBlock(QString blockName, bool isObs);

    void setName (QString nName);
    QString getName();
    bool getIsObstacle();
};

#endif // BLOCK_H
