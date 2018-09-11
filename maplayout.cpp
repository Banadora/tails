#include "maplayout.h"
#include "game.h"

#include <QDebug>

extern xGame *game;

xMapLayout::xMapLayout() :
    startX(4),
    startY(10)
{ }

void xMapLayout::loadMap(QString nName) {
    //open file and convert to byteArray
    //QFile file(nName + ".json");
    QFile file(":/maps/" + nName + ".json");
    if(!file.open(QIODevice::ReadOnly)) { qDebug() << "Failed to open " << name + ".json"; exit(1); }
    QTextStream file_text(&file);
    QString fullJsonString;
    fullJsonString = file_text.readAll();
    file.close();
    QByteArray json_bytes = fullJsonString.toLocal8Bit();

    //convert to jdoc
    auto json_doc=QJsonDocument::fromJson(json_bytes);
    if(json_doc.isNull()) { qDebug() << "Failed to find JSON doc."; exit(2); }
    if(!json_doc.isObject()){ qDebug() << "JSON is not an object."; exit(3); }
    rootObj = json_doc.object();
    if(rootObj.isEmpty()){ qDebug() << "JSON object is empty."; exit(4); }

    //rootMap = root json object
    QVariantMap rootMap = rootObj.toVariantMap();
    //blocksArray is an array of objects and is located directly in root, it's erased before use
    while(blocksArray.count()) {
         blocksArray.pop_back();
     }
    blocksArray = rootObj["blocks"].toArray();

    //jBlock is an object inside the blockArray
    QJsonObject jBlock;
    QVariantMap jBlockMap;
    for (int i = 0, n = blocksArray.size(); i < n; i++) {
        jBlock = blocksArray[i].toObject();
        jBlockMap = jBlock.toVariantMap();
        game->placeBlock(jBlockMap["xpos"].toInt(), jBlockMap["ypos"].toInt(), jBlockMap["name"].toString(), jBlockMap["obstacle"].toBool());
    }
    name = rootMap["name"].toString();
    qDebug() << "~~~~ Map loaded ~~~~" << '\n' << name;

    //set surrounding maps
    setMaps(rootMap["mapNorth"].toString(), rootMap["mapEast"].toString(), rootMap["mapSouth"].toString(), rootMap["mapWest"].toString());
    qDebug() << mapNorth << mapEast << mapSouth << mapWest;
}

int xMapLayout::getStartX() { return startX; }
int xMapLayout::getStartY() { return startY; }
void xMapLayout::setStartX(int nX) { startX = nX; }
void xMapLayout::setStartY(int nY) { startY = nY; }

void xMapLayout::setMaps(QString nMapNorth, QString nMapEast, QString nMapSouth, QString nMapWest) {
    mapNorth = nMapNorth;
    mapEast = nMapEast;
    mapSouth = nMapSouth;
    mapWest = nMapWest;
}

QString xMapLayout::getNextMap(QString direction) {
    if (direction == "north") {return mapNorth; }
    else if (direction == "east") {return mapEast; }
    else if (direction == "south") {return mapSouth; }
    else if (direction == "west") {return mapWest; }
    else {return "none"; }
}
