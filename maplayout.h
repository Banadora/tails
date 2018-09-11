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

    QJsonDocument doc;
    QJsonObject rootObj;
    QJsonObject blockObj;
    QJsonArray blocksArray;

public:
    xMapLayout();

    int getStartX();
    int getStartY();
    void setStartX(int nX);
    void setStartY(int nY);

    void loadMap(QString nName);
};



#endif // MAPLAYOUT_H
