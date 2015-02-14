//
//  Ant.h
//  Inheritance_and_polymorphism
//
//  Created by Rikard Arnar B. Birgisson on 01/04/14.
//  Copyright (c) 2014 Rikard Arnar B. Birgisson. All rights reserved.
//

#ifndef Inheritance_and_polymorphismAnt
#define Inheritance_and_polymorphismAnt

#include <iostream>
#include "Organism.h"

class Ant : public Organism{
public:
    Ant(World* aWorld, int x, int y);
    
    ~Ant();
    
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
    
    bool inTheGridAnt(int newX, int newY);
};

#endif /* defined(__Inheritance_and_polymorphism__Ant__) */
