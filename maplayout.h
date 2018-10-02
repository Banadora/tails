#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include "block.h"

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class xMapLayout {

    QString name;
    int startX;
    int startY;

    QString mapNorth;
    QString mapEast;
    QString mapSouth;
    QString mapWest;

    QJsonDocument doc;
    QJsonObject rootObj;

    QJsonObject blockObj;
    QJsonArray blocksArray;

    QJsonObject enemyObj;
    QJsonArray enemyArray;

public:
    xMapLayout();

    int getStartX();
    int getStartY();
    void setStartX(int nX);
    void setStartY(int nY);

    void setMaps(QString nMapNorth, QString nMapEast, QString nMapSouth, QString nMapWest);
    QString getNextMap(QString direction);

    void loadMap(QString nName);
};



#endif // MAPLAYOUT_H
