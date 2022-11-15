#include "sheep.h"
#include "grass.h"
#include "helper.h"

void Sheep::putSelf(Grid* nextGrid, const int x, const int y) {
    Sheep* nextSelf = new Sheep(*this);
    if (putAnimal(nextSelf, nextGrid, x, y))
        setNextSelf(nextSelf);
}

void Sheep::putClone(Grid* nextGrid, const int x, const int y) const {
    putAnimal(new Sheep(getBoard()), nextGrid, x, y);
}

void Sheep::eat(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }

        Grass* grass = dynamic_cast<Grass*>(adjEntity);
        if (grass && !grass->isRemoved()) {
            // Adjacent cell is grass and has not been eaten
            // Destroy the grass entity and refill hunger
            setHungerCounter(getHungerCooldown());
            grass->removeSelf(nextGrid);
            return;
        }
    }
}

void Sheep::breed(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }

        Sheep* sheep = dynamic_cast<Sheep*>(adjEntity);
        if (sheep) {
            // Adjacent cell is sheep, breed
            int randAdjIndex = getRandomMovementIndex(nextGrid);
            if (randAdjIndex != -1) {
                // There is place to spawn new sheep
                putClone(nextGrid, getX() + getAdjX(randAdjIndex), getY() + getAdjY(randAdjIndex));
                // Reset breed counter
                setBreedCounter(getBreedCooldown());
            }
            return;
        }
    }
}

void Sheep::move(Grid* nextGrid) {
    int randAdjIndex = getRandomMovementIndex(nextGrid);
    if (randAdjIndex != -1) {
        // There is place to move to
        putSelf(nextGrid, getX() + getAdjX(randAdjIndex), getY() + getAdjY(randAdjIndex));
    }
    else {
        // Nowhere to move, stay there
        putSelf(nextGrid, getX(), getY());
    }
}