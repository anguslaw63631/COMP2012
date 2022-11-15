#include "wolf.h"
#include "sheep.h"
#include "grass.h"
#include "helper.h"

void Wolf::putSelf(Grid* nextGrid, const int x, const int y) {
    Wolf* nextSelf = new Wolf(*this);
    if (putAnimal(nextSelf, nextGrid, x, y))
        setNextSelf(nextSelf);
}

void Wolf::putClone(Grid* nextGrid, const int x, const int y) const {
    putAnimal(new Wolf(getBoard()), nextGrid, x, y);
}

void Wolf::eat(Grid* nextGrid) {
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
        if (sheep && !sheep->isRemoved()) {
            // Adjacent cell is sheep and has not been eaten
            // Destroy the sheep entity and refill hunger
            setHungerCounter(getHungerCooldown());
            sheep->removeSelf(nextGrid);
            return;
        }
    }
}

void Wolf::breed(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }

        Wolf* wolf = dynamic_cast<Wolf*>(adjEntity);
        if (wolf) {
            // Adjacent cell is wolf, breed
            int randAdjIndex = getRandomMovementIndex(nextGrid);
            if (randAdjIndex != -1) {
                // There is place to spawn new wolf
                putClone(nextGrid, getX() + getAdjX(randAdjIndex), getY() + getAdjY(randAdjIndex));
                // Reset breed counter
                setBreedCounter(getBreedCooldown());
            }
            return;
        }
    }
}

void Wolf::move(Grid* nextGrid) {
    // First, find a sheep to target
    int closestSheepDistanceSqr = BOARD_SIZE_W * BOARD_SIZE_W + BOARD_SIZE_H * BOARD_SIZE_H;
    int targetX = -1, targetY = -1;
    for (int x=0; x<BOARD_SIZE_W; ++x) {
        for (int y=0; y<BOARD_SIZE_H; ++y) {
            Sheep* sheep = dynamic_cast<Sheep*>(getBoard()->getGrid()->getCell(x, y));
            if (sheep && !sheep->isRemoved()) {
                // Found a sheep, calculate distance to it
                int distanceX = getX() - sheep->getX();
                int distanceY = getY() - sheep->getY();
                int distanceSqr = distanceX * distanceX + distanceY * distanceY;
                // If this is the shortest distance found, update targetX/Y
                if (distanceSqr < closestSheepDistanceSqr) {
                    closestSheepDistanceSqr = distanceSqr;
                    targetX = sheep->getX();
                    targetY = sheep->getY();
                }
            }
        }
    }

    if (closestSheepDistanceSqr < BOARD_SIZE_W * BOARD_SIZE_W + BOARD_SIZE_H * BOARD_SIZE_H) {
        // Sheep found, move towards it
        int xDir = (targetX > getX()) ? 1 : ((targetX < getX()) ? -1 : 0);
        int yDir = (targetY > getY()) ? 1 : ((targetY < getY()) ? -1 : 0);
        if (!dynamic_cast<Animal*>(nextGrid->getCell(getX() + xDir, getY() + yDir))
            && !dynamic_cast<Animal*>(getBoard()->getGrid()->getCell(getX() + xDir, getY() + yDir))) {
            // There is place to move to
            putSelf(nextGrid, getX() + xDir, getY() + yDir);
        }
        else {
            // Cannot move, stay there
            putSelf(nextGrid, getX(), getY());
        }
    }
    else {
        // No sheep found, move randomly
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
}