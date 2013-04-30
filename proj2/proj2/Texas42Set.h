
#ifndef TEXAS42SET_H
#define TEXAS42SET_H

#pragma once

#include "PlayerCollection.h"
#include "DominoCollection.h"
#include "Trick.h"

class Texas42Set
{
private:
    PlayerCollection *players;
    DominoCollection dominoSet;
    Trick tricks[7];

    Player *openingBidder;
    Player *winningBidder;

    Bid winningBid;
    
    int teamCount[2];
    
    
public:
    Texas42Set( PlayerCollection *players, DominoCollection dominoSet, Player *openingBidder ) : 
        players( players ), dominoSet( dominoSet ), openingBidder( openingBidder )  {  } 
    ~Texas42Set(void) { teamCount[0] = 0; teamCount[1] = 0; }

    void drawHands( Player *firstDraw );
    Player* playTrick( Trick *trick, Player *lead );
    int solicitBids( void );
    void resolveSet( void );
    void setWinningBid( Bid bid );
    void giveCount( int lead, Trick trick );

    void play( void );
};

#endif
