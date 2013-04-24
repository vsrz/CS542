
#ifndef TRICK_H
#define TRICK_H
#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"
#include "Domino.h"
#include "Player.h"

class Trick : public DominoCollection
{
private:

    Domino trump;
    Bid bid;
public:
    Trick( Domino trump ) {}
    ~Trick(void) {}            
    
};

#endif
