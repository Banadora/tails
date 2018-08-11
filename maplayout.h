#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include "block.h"

#include <QString>

class xMapLayout {

    QString layout[12];
    int startX;
    int startY;

    int exits[10][5]; //10 exits composed of posX, posY, nLayout, nStartX, nStartY
    int activeExit;

public:
    xMapLayout();

    void clearExits();

    void setLayout(int layoutNumber);
    int getStartX();
    int getStartY();
    void setStartX(int nX);
    void setStartY(int nY);

    bool isAnExitPos(int x, int y);
    int getExits(int iX, int iY);
    int getActiveExit();

    QString getBlockName(int x, int y);
};



#endif // MAPLAYOUT_H
