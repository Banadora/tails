
#include "maplayout.h"


void xMapLayout::setLayout(int layoutNumber) {

    switch (layoutNumber) {
        case 1:
            //          x= 0  1  2  3  4  5  6  7  8  9  10 11
            layout[0] =   "g1 g1 g1 g1 g1 g1 g1 m0 g1 g1 g1 g1"  ; //y = 0
            layout[1] =   "g1 g0 g0 g0 g1 g0 g0 m0 g1 g0 g0 g1"  ; //y = 1
            layout[2] =   "g1 g0 g0 g0 g1 m2 m1 m4 g1 g0 g0 g1"  ; //y = 2
            layout[3] =   "g1 g0 g1 g0 g0 m0 g1 g1 g0 g0 g0 g1"  ; //y = 3
            layout[4] =   "g1 g0 g0 g0 g0 m0 g0 g1 g1 g0 g0 g1"  ; //y = 4
            layout[5] =   "g1 g0 g0 g0 g0 m5 m1 m3 g0 g1 g0 g1"  ; //y = 5
            layout[6] =   "g1 g0 g1 g0 g0 g0 g0 m0 g0 g0 g0 g1"  ; //y = 6
            layout[7] =   "g1 g0 g1 g0 g0 g0 m2 m4 g0 g1 g0 g1"  ; //y = 7
            layout[8] =   "g1 g1 g0 g0 g0 g0 m0 g0 g1 g1 g0 g1"  ; //y = 8
            layout[9] =   "g1 g0 g0 g0 m2 m1 m4 g0 g1 g1 g0 g1"  ; //y = 9
            layout[10] =  "g1 g0 g0 g0 g0 g0 g0 g0 g0 g0 g0 g1"  ; //y = 10
            layout[11] =  "g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1 g1"  ; //y = 11
            break;

        case 2:
            break;
    }

}

QString xMapLayout::getBlocName(int x, int y) {

    QString bloc;

    bloc = layout[y].mid(x*3,2);

    if (bloc == "g0") { return "grass0"; }
    else if (bloc == "g1") { return "grass1"; }
    else if (bloc == "m0") { return "mud0"; }
    else if (bloc == "m1") { return "mud1"; }
    else if (bloc == "m2") { return "mud2"; }
    else if (bloc == "m3") { return "mud3"; }
    else if (bloc == "m4") { return "mud4"; }
    else if (bloc == "m5") { return "mud5"; }
    else if (bloc == "m6") { return "mud6"; }
    else { return "blank"; }
}
