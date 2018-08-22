
#include "CharacterView.h"

CharacterView::CharacterView(const QString & QItemName){

    setPixmap(QPixmap(":/img/" + QItemName + ".png"));
}

void CharacterView::move(int x, int y) {

    //Move the character from its current position to the specified position. Stop the process if an obstacle is in the way.
}

void CharacterView::setFacingDirection(Directions direction) {
    // For each character design, need pictures facing different directions. Load the right picture for the specified direction.
}

void CharacterView::move(Directions direction) {
    //Move the character to the specified direction.
}

