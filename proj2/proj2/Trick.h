
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
    DominoCollection trick;    
    int trump;
    Bid bid;
    Player *player[4];
public:
    Trick( int t ) : trump( t ) { }
    ~Trick(void) {}  

    void addDomino( Domino d, Player *p );
    Player* getWinner( void );
    
    int getTrump( void );
    void setTrump( int t );
    int getValue( void );
    
    
};

#endif
