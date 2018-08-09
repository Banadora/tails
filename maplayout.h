#ifndef MAPLAYOUT_H
#define MAPLAYOUT_H

#include "bloc.h"

#include <QString>

class xMapLayout {

    QString layout[12];
    //QString blocArray[12][12];
    int startX;
    int startY;

public:
    void setLayout(int layoutNumber);
    int getStartX();
    int getStartY();
    QString getBlocName(int x, int y);
    //void setBlocArray(xBloc bloc, int x, int y);
    //QString getBlocArray(int x, int y);
};



#endif // MAPLAYOUT_H
