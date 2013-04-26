
#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <string>
#include <iostream>

#include "Bid.h"
#include "Domino.h"
#include "DominoCollection.h"

class Player {

private:
	std::string name;
    Player *partner;
	DominoCollection hand;
    int seat;
	Bid bid;    

public:
	Player( void ) : name( "Unnamed Player" ), seat( 0 ) {}
	Player( std::string n, int s ) : name( n ), seat( s ) {};
	~Player( void ) {}

	virtual Bid makeBid( Bid b ) = 0;
	//virtual Domino playDomino( Bid bid, int trump, DominoCollection trick ) = 0;

    DominoCollection getHand( void );

    void setName( std::string n );
	void printName( std::ostream &o );
	void printHand( std::ostream &o );
    
    void setSeat( int );
    int getSeat( void );
    void setPartner( Player *partner );
    Player *getPartner( void );

    void drawDominoes( DominoCollection & set );

};

std::ostream & operator << ( std::ostream & out, Player &p );

#endif
