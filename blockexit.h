#ifndef BLOCKEXIT_H
#define BLOCKEXIT_H

#include "block.h"

class xBlockExit : public xBlock
{

    int destinationLayout;
    int destinationX;
    int destinationY;

public:
    xBlockExit(QString blocName);
    xBlockExit(QString blocName,int nDestinationLayout,int nDestinationX,int nDestinationY);
    int getDestinationLayout() const;
    int getDestinationX() const;
    int getDestinationY() const;
};

#endif // BLOCKEXIT_H
