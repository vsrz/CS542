
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
    int winningBidder;

    Bid winningBid;
    
    int teamCount[2];
    
    
public:
    Texas42Set( PlayerCollection *t, DominoCollection d, int openingBidder ) : 
        table( t ), dominoSet( d ), firstBid( openingBidder )  { teamCount[0] = 0; teamCount[1] = 0; } 
    ~Texas42Set(void) { teamCount[0] = 0; teamCount[1] = 0; }

    void drawHands( int firstDraw );
    int playTrick( Trick *trick, int leadPlayerIndex );
    int solicitBids( void );
    void resolveSet( void );
    void setWinningBid( Bid bid );
    void giveCount( int lead, Trick trick );

    void play( void );
};

#endif
