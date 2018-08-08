#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include <QString>

class xMapLayout {

    QString layout[12];
    int startX;
    int startY;

public:
    void setLayout(int layoutNumber);
    int getStartX();
    int getStartY();
    QString getBlocName(int x, int y);
};



#endif // MAPLAYOUT_H
