//
//  Bug.cpp
//  Inheritance_and_polymorphism
//
//  Created by Rikard Arnar B. Birgisson on 01/04/14.
//  Copyright (c) 2014 Rikard Arnar B. Birgisson. All rights reserved.
//

#include "Bug.h"
#include <cstdlib>


Bug::Bug(World* aWorld, int x, int y) : Organism(aWorld, x, y){
    eat = 0;
}

Bug::~Bug(){}

// In the given world moves this organism.
void Bug::move(){
    moved = true;
    breedTicks++;
    eat++;
    
    // Ef ant er ekki til stadar ta faerum vid a sama hatt og ant faerir sig
    if (!antAround()){
        
        Move moveBug = world->randomMove();
        if (moveBug == UP){
            
            if(world->getAt(x, y + 1) == NULL) {
                movesTo(x, y + 1);
                return;
            }
        }
        
        else if (moveBug == DOWN){
            
            if(world->getAt(x, y - 1) == NULL){
                movesTo(x, y - 1);
                return;
            }
        }
        
        else if (moveBug == LEFT){
            
            if(world->getAt(x - 1, y) == NULL){
                movesTo(x - 1, y);
                return;
            }
        }
        
        else if (moveBug == RIGHT){
            
            if(world->getAt(x + 1, y) == NULL){
                movesTo(x + 1, y);
                return;
            }
        }
    }
}

bool Bug::antAround(){
    // skodum hvort ant se til stadar, i tessari rod: up, down, left, right.
    // skodum fyrst hvort reiturinn se null
    if (world->getAt(x, y + 1) != NULL){
        
        //Skodum svo hvort a ant se a honum
        if (world->getAt(x, y + 1)->getType() == ANT){
            // Eydum og faerum tangad
            delete world->getAt(x, y + 1);
            movesTo(x, y + 1);
            eat = 0;
            return true;
        }
    }
    
    if (world->getAt(x, y - 1) != NULL){
        
        if (world->getAt(x, y - 1)->getType() == ANT){
            delete world->getAt(x, y - 1);
            movesTo(x, y - 1);
            eat = 0;
            return true;
        }
    }

    if (world->getAt(x - 1, y) != NULL){
        
        if (world->getAt(x - 1, y)->getType() == ANT){
            delete world->getAt(x - 1, y);
            movesTo(x - 1, y);
            eat = 0;
            return true;
        }
    }
    
    if (world->getAt(x + 1, y) != NULL){
        
        if (world->getAt(x + 1, y)->getType() == ANT){
            delete world->getAt(x + 1, y);
            movesTo(x + 1, y);
            eat = 0;
            return true;
        }
    }
    
    return false;
}

// Makes this organism breed.
void Bug::breed(){
    
    if(breedTicks >= BREED_BUGS){
        breedAtAdjacentCell();
    }
}

// Returns the type of this organism.
OrganismType Bug::getType() const{
    return BUG;
}

// The character representation of this organism.
char Bug::representation() const{
    return 'X';
}

// The size of this organism.
int Bug::size() const{
    return 30;
}

// Returns true if organism is dead, false otherwise.
bool Bug::isDead() const{
    return eat >= STARVE_BUGS;
}

// Generates an offspring at the given position.
void Bug::generateOffspring(int whereX, int whereY){
    new Bug(this->world, whereX, whereY);
    breedTicks = 0;
}