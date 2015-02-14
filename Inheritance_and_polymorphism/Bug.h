//
//  Bug.h
//  Inheritance_and_polymorphism
//
//  Created by Rikard Arnar B. Birgisson on 01/04/14.
//  Copyright (c) 2014 Rikard Arnar B. Birgisson. All rights reserved.
//

#ifndef Inheritance_and_polymorphismBug
#define Inheritance_and_polymorphismBug

#include <iostream>
#include "Organism.h"
#include "World.h"

class Bug : public Organism{
public:
    Bug(World* aWorld, int x, int y);
    
    ~Bug();
    
    // In the given world moves this organism.
    void move();
    
    // Makes this organism breed.
    void breed();
    
    // Returns the type of this organism.
    OrganismType getType() const;
    
    // The character representation of this organism.
    char representation() const;
    
    // The size of this organism.
    int size() const;
    
    // Returns true if organism is dead, false otherwise.
    bool isDead() const;
    
    // Generates an offspring at the given position.
    void generateOffspring(int whereX, int whereY);
    
    bool antAround();
    
private:
    int eat; 
};

#endif /* defined(__Inheritance_and_polymorphism__Bug__) */
