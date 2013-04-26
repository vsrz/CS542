
#ifndef TEXAS42SET_H
#define TEXAS42SET_H

#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"

class Texas42Set
{
private:
    PlayerCollection *table;
    DominoCollection dominoSet;
    DominoCollection tricks[7];

    Player *firstBid;
    Bid bid;
    
public:
    Texas42Set( PlayerCollection *t, DominoCollection d, Player *openingBidder ) : 
        table( t ), dominoSet( d ), firstBid( openingBidder )  {} 
    ~Texas42Set(void) {}

    void playTricks( void );
    Bid solicitBids( void );

    void play( void );
};

#endif
