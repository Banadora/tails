#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include "block.h"

#include <QString>

class xMapLayout {

    QString layout[12];
    int startX;
    int startY;
    int exitX;
    int exitY;

public:
    xMapLayout();

    void setLayout(int layoutNumber);
    int getStartX();
    int getStartY();
    void setStartX(int nX);
    void setStartY(int nY);

    int getExitX();
    int getExitY();

    QString getBlockName(int x, int y);
};



#endif // MAPLAYOUT_H
