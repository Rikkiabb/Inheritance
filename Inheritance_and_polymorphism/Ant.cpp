//
//  Ant.cpp
//  Inheritance_and_polymorphism
//
//  Created by Rikard Arnar B. Birgisson on 01/04/14.
//  Copyright (c) 2014 Rikard Arnar B. Birgisson. All rights reserved.
//
#include <iostream>
#include "Ant.h"
#include "World.h"
#include <cstdlib>

using namespace std;
Ant::Ant(World* aWorld, int x, int y) : Organism(aWorld, x, y){
}

Ant::~Ant(){}

// In the given world moves this organism.
void Ant::move(){
    // Byrjum a tvi ad heakka breedticks og moved a true vegna tess ad elementid hefur lifad af adra umferd og tvi haekkum vid breedticks og vid erum ad fara faera tad svo move verdur true
    breedTicks++;
    moved = true;
    
    // Finnum random move og midum move vid tad
    Move moveAnt = world->randomMove();
    if (moveAnt == UP){
        // Ef naesti stadur er NULL, ta getur ant farid tangad og vid latum hann tangad
        if(world->getAt(x, y + 1) == NULL){
            movesTo(x, y + 1);
            return;
        }
    }
    
    else if (moveAnt == DOWN){
        
        if(world->getAt(x, y - 1) == NULL){
            movesTo(x, y - 1);
            return;
        }
    }
    
    else if (moveAnt == LEFT){
        
        if(world->getAt(x - 1, y) == NULL){
            movesTo(x - 1, y);
            return;
        }
    }
    
    else if (moveAnt == RIGHT){
        
        if(world->getAt(x + 1, y) == NULL){
            movesTo(x + 1, y);
            return;
        }
    }
}


// Makes this organism breed.
void Ant::breed(){
    
    // Skodum hvort ad ant er buinn ad lifa nogu lengi, ef svo er ta fjolgum vid honum
    if(breedTicks >= BREED_ANTS){
        breedAtAdjacentCell();
    }
}

// Returns the type of this organism.
OrganismType Ant::getType() const{
    return ANT;
}

// The character representation of this organism.
char Ant::representation() const{
    return 'o';
}

// The size of this organism.
int Ant::size() const{
    return 10;
}

// Returns true if organism is dead, false otherwise.
bool Ant::isDead() const{
    return false;
}

// Generates an offspring at the given position.
void Ant::generateOffspring(int whereX, int whereY){
    // Buum til nyjan og stillum breedticks a null
    new Ant(this->world, whereX, whereY);
    breedTicks = 0;
}