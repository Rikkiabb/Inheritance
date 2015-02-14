#include <iostream>
#include "Organism.h"
#include "World.h"

// Create an organism at the given coordinates in the given world.
Organism::Organism(World* aWorld, int xcoord, int ycoord) {
        world = aWorld;
        x = xcoord;
        y = ycoord;
        breedTicks = 0;
        moved = false;
        world->setAt(x, y, this);
}

// flags the organism as moved or not
void Organism::setMoved(bool hasMoved) {
    moved = hasMoved;
}

// has the organism moved or not?
bool Organism::hasMoved() const {
    return moved;
}

// moves the organism from coordinates (x,y) to (xNew,yNew)
void Organism::movesTo(int xNew, int yNew) {
    
    // Ef tetta er fyrir utan grid ta turfum getum vid ekki farid a stadinn og sleppum tvi einfaldlega
    if(inTheGridOrg(xNew, yNew)){
        
        // Setjum tad sem er a gamla stadnum a nyja stadinn
        world->setAt(xNew, yNew, world->getAt(x, y));
        
        // nullum gamla stadinn
        world->setAt(x, y, NULL);
        
        x = xNew;
        y = yNew;
    }
}

// Breeds an organism at an adjacent cell. This method calls the
// generateOffspring() method.
// Breeds a new organism at an adjacent cell. Tries to produce one new
// organism in UP, DOWN, LEFT, or RIGHT cell (in that order).  Makes
// sure not to breed off the grid.
void Organism::breedAtAdjacentCell()  {
    
    // Skodum fyrst upp, hvort tad er laust svo skodum vid nidur, svo vinstri og svo haegri
    // Ef stadur er laus ta buum vid til afkvaemi tar
    if(world->getAt(x, y + 1) == NULL && inTheGridOrg(x, y + 1)) {
        generateOffspring(x, y + 1);
        return;
    }
    
    else if(world->getAt(x, y - 1) == NULL && inTheGridOrg(x, y - 1)) {
        generateOffspring(x, y - 1);
        return;
    }
    
    else if(world->getAt(x - 1, y) == NULL && inTheGridOrg(x - 1, y)) {
        generateOffspring(x - 1, y);
        return;
    }
    
    else if(world->getAt(x + 1, y) == NULL && inTheGridOrg(x + 1, y)) {
        generateOffspring(x + 1, y);
        return;
    }
}

// Returns true if organism is dead, false otherwise.
bool Organism::isDead() const {
    return false;
}

bool Organism::inTheGridOrg(int newX, int newY){
    return (newX >= 0) && (newX < WORLDSIZE) && (newY >= 0) && (newY < WORLDSIZE);
}
