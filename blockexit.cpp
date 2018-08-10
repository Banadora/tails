#include "blockexit.h"


//////////////////////////////////////////////////Getters
///
int xBlockExit::getDestinationLayout() const
{
    return destinationLayout;
}

int xBlockExit::getDestinationX() const
{
    return destinationX;
}

int xBlockExit::getDestinationY() const
{
    return destinationY;
}


///////////////////////////////////////////////Constructors
///

xBlockExit::xBlockExit(QString blocName)
{
    xBlock(blocName)
}

xBlockExit::xBlockExit(QString blocName, int nDestinationLayout, int nDestinationX, int ndDestinationY)
{
    xBlock(blocName);
    xBlockExit.destinationLayout = nDestinationLayout;
    xBlockExit.destinationX = nDestinationX;
    xBlockExit.destinationY = nDestinationX;
}

