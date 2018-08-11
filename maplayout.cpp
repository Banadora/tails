#include "maplayout.h"
#include "game.h"

#include <QDebug>

xMapLayout::xMapLayout() :
    startX(4),
    startY(10)
{ }

void xMapLayout::clearExits() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            exits[x][y] = -1;
        }
    }
}

////////// visually define layout of blocks and hero start position
void xMapLayout::setLayout(int layoutNumber) {
    if (layoutNumber == 0) { layoutNumber = 1; } // if init map, map = 1
    clearExits();

    switch (layoutNumber) {
        case 1:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g1 g1 g0 g1 g1 g1 g1 m0 g1 g1 g1 g1"  ; //y = 0
            layout[1] =   "g1 g0 g0 g0 g1 g0 g0 m0 g1 g0 g0 g1"  ; //y = 1
            layout[2] =   "g1 g0 g1 g0 g1 m2 m1 m4 g1 g0 g0 g1"  ; //y = 2
            layout[3] =   "g1 g0 g0 g0 g0 m0 g1 g1 g0 g0 g0 g1"  ; //y = 3
            layout[4] =   "g1 g0 g1 g0 g0 m0 g0 g1 g1 g0 g0 g1"  ; //y = 4
            layout[5] =   "g1 g0 g0 g0 g1 m5 m1 m3 g0 g1 g0 g1"  ; //y = 5
            layout[6] =   "g1 g0 g0 g1 g1 g1 g0 m0 g0 g0 g0 g1"  ; //y = 6
            layout[7] =   "g1 g0 g1 g0 g0 g0 m2 m4 g0 g1 g0 g1"  ; //y = 7
            layout[8] =   "g1 g1 g0 g0 g1 g0 m0 g0 g1 g1 g0 g1"  ; //y = 8
            layout[9] =   "g1 g0 g0 g1 m2 m1 m4 g0 g1 g1 g0 g1"  ; //y = 9
            layout[10] =  "g1 g0 g0 g0 m0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 10
            layout[11] =  "g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1"  ; //y = 11

            // exit 1               //exit 2
            exits[1][0] = 7;        exits[2][0] = 2;     //posX
            exits[1][1] = 0;        exits[2][1] = 0;     //posY
            exits[1][2] = 2;        exits[2][2] = 2;     //nLayout
            exits[1][3] = 7;        exits[2][3] = 2;     //nStartX
            exits[1][4] = 11;       exits[2][4] = 11;    //nStartY
            break;

        case 2:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1"  ; //y = 0
            layout[1] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 1
            layout[2] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 2
            layout[3] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 3
            layout[4] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 4
            layout[5] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 5
            layout[6] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 6
            layout[7] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 7
            layout[8] =   "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 8
            layout[9] =   "g1 g0 g0 g0 g0 g0 g0 m6 g0 g0 g0 g1"  ; //y = 9
            layout[10] =  "g1 g0 g0 g0 g0 g0 g0 m0 g0 g0 g0 g1"  ; //y = 10
            layout[11] =  "g1 g1 g0 g1 g1 g1 g1 m0 g1 g1 g1 g1"  ; //y = 11

            // exit 1               //exit 2
            exits[1][0] = 7;        exits[2][0] = 2;     //posX
            exits[1][1] = 11;       exits[2][1] = 11;    //posY
            exits[1][2] = 1;        exits[2][2] = 1;     //nLayout
            exits[1][3] = 7;        exits[2][3] = 2;     //nStartX
            exits[1][4] = 0;        exits[2][4] = 0;     //nStartY
            break;
    }
}

int xMapLayout::getStartX() { return startX; }
int xMapLayout::getStartY() { return startY; }
void xMapLayout::setStartX(int nX) { startX = nX; }
void xMapLayout::setStartY(int nY) { startY = nY; }


////////// check all exits to decide if we need to create xBlockExit or simple xBlock
bool xMapLayout::isAnExitPos(int x, int y)
{
    for (int i = 0; i < 10; i++) {
        if (   (x == exits[i][0]) && (y == exits[i][1])   ) { activeExit = i; return true; }
    }
    return false;
}

////////// get information of exit
// iX : exit id
// iY : information
//      iY = 0 for exitXPos
//      iY = 1 for exitYPos
//      iY = 2 for DestinationLayout
//      iY = 3 for DestinationStartX
//      iY = 4 for DestinationStartY
int xMapLayout::getExits(int iX, int iY) { return exits[iX][iY];}

int xMapLayout::getActiveExit() { return activeExit; }


////////// get the real name of block from layout identifier
QString xMapLayout::getBlockName(int x, int y) {

    QString block;

    block = layout[y].mid(x*3, 2);

    if (block == "g0") { return "grass0"; }
    else if (block == "g1") { return "grass1"; }
    else if (block == "m0") { return "mud0"; }
    else if (block == "m1") { return "mud1"; }
    else if (block == "m2") { return "mud2"; }
    else if (block == "m3") { return "mud3"; }
    else if (block == "m4") { return "mud4"; }
    else if (block == "m5") { return "mud5"; }
    else if (block == "m6") { return "mud6"; }
    else { return "blank"; }
}

