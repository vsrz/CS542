
#ifndef TEXAS42SET_H
#define TEXAS42SET_H

#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"
#include "Trick.h"

class Texas42Set
{
private:
    PlayerCollection *table;
    DominoCollection dominoSet;
    Trick tricks[7];

    int firstBid;
    Player *highBidder;

    Bid bid;
    
public:
    Texas42Set( PlayerCollection *t, DominoCollection d, int openingBidder ) : 
        table( t ), dominoSet( d ), firstBid( openingBidder )  {} 
    ~Texas42Set(void) {}

    void playTricks( void );
    Bid solicitBids( void );
    void resolveSet( void );

    void play( void );
};

#endif
