
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
	Bid bid;    

public:
	Player( void ) : name( "Unnamed Player" ) {}
	Player( std::string n ) : name( n ) {};
	~Player( void ) {}

	virtual Bid makeBid( Bid b ) = 0;
	//virtual Domino playDomino( Bid bid, int trump, DominoCollection trick ) = 0;

    DominoCollection getHand( void );

    void setName( std::string n );
	void printName( std::ostream &o );
	void printHand( std::ostream &o );
    
    void setPartner( Player *partner );
    Player *getPartner( void );

    void drawDominoes( DominoCollection & set );

};

std::ostream & operator << ( std::ostream & out, Player &p );

#endif
