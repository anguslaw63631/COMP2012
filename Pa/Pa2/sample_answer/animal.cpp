#include "animal.h"
#include "grass.h"
#include "helper.h"

bool Animal::putAnimal(Animal* animal, Grid* nextGrid, const int x, const int y) const {
    if (nextGrid->outOfBounds(x, y)) {
        // Out of bounds, do not spawn animal
        delete animal;
        return false;
    }
    if (nextGrid->getCell(x, y)) {
        // Already something here
        if (dynamic_cast<Grass*>(nextGrid->getCell(x, y)) != nullptr) {
            // If it is grass, it can be overwritten
            nextGrid->deleteCell(x, y);
        }
        else {
            // Current cell is not grass, delete the current animal
            delete animal;
            return false;
        }
    }
    nextGrid->setCell(animal, x, y);
    return true;
}

int Animal::getRandomMovementIndex(Grid* nextGrid) const {
    int numPossibleCells = 0;
    bool indexCandidate[9];
    for (int i=0; i<9; ++i) {
        indexCandidate[i] = false;
        if (i == 4) continue;

        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        if (nextGrid->outOfBounds(adjX, adjY)) {
            // Out of bounds, ignore
            continue;
        }

        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);
        if (dynamic_cast<Animal*>(adjEntity)) {
            // Adjacent cell is an animal, cannot move over
            continue;
        }

        Entity* adjNextEntity = nextGrid->getCell(adjX, adjY);
        if (dynamic_cast<Animal*>(adjNextEntity)) {
            // Adjacent cell in next grid has an animal, cannot move over
            continue;
        }

        // Found a place to move to
        ++numPossibleCells;
        indexCandidate[i] = true;
    }
    if (numPossibleCells > 0) {
        // Use a custom made random function to be consistent
        int randInd = pseudo_rand() % numPossibleCells;
        for (int i=0; i<9; ++i) {
            if (indexCandidate[i]) {
                if (randInd == 0) {
                    return i;
                }
                --randInd;
            }
        }
    }
    // No place to move to
    return -1;
}

void Animal::update(Grid* nextGrid) {
    // Animal first tries to eat
    // If hunger reaches 0, the animal dies
    if (countdown(hungerCounter, getHungerCooldown())) {
        return;
    }
    else {
        eat(nextGrid);
    }
  
    // Animal then tries to breed if there are animals nearby
    if (breedCounter == 1) {
        if (hungerCounter / static_cast<float>(getHungerCooldown()) > 0.7f) {
            // Needs high enough hunger to breed
            breed(nextGrid);
        }
    }
    else {
        countdown(breedCounter, getBreedCooldown());
    }

    // Animal finally moves if move cooldown is reached
    if (countdown(moveCounter, getMoveCooldown())) {
        move(nextGrid);
    }
    else {
        putSelf(nextGrid, getX(), getY());
    }
}