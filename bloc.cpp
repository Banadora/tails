
#include "bloc.h"


xBloc::xBloc(QString blocName) {
    setPixmap(QPixmap(":/img/" + blocName + ".png"));
}
