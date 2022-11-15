#include "grass.h"
#include "helper.h"

bool putGrass(Grass* grass, Grid* nextGrid, const int x, const int y) {
    if (nextGrid->outOfBounds(x, y)) {
        // Out of bounds, do not spawn grass
        delete grass;
        return false;
    }
    if (nextGrid->getCell(x, y)) {
        // Already something here, do not spawn grass
        delete grass;
        return false;
    }
    nextGrid->setCell(grass, x, y);
    return true;
}

void Grass::putSelf(Grid* nextGrid, const int x, const int y) {
    Grass* nextSelf = new Grass(*this);
    if (putGrass(nextSelf, nextGrid, x, y))
        setNextSelf(nextSelf);
}

void Grass::putClone(Grid* nextGrid, const int x, const int y) const {
    putGrass(new Grass(getBoard()), nextGrid, x, y);
}

void Grass::update(Grid* nextGrid) {
    // Spread every SPREAD_COOLDOWN steps
    if (countdown(spreadCounter, getSpreadCooldown())) {
        // Grass spreads in 4 direction
        putClone(nextGrid, getX()+1, getY());
        putClone(nextGrid, getX()-1, getY());
        putClone(nextGrid, getX(), getY()+1);
        putClone(nextGrid, getX(), getY()-1);
    }

    // This grass stays if nothing else is moving here
    putSelf(nextGrid, getX(), getY());
}