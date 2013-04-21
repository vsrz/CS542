
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
	DominoCollection hand;
	Bid bid;

public:
	Player( void ) : name( "Unnamed Player" ) {}
	Player( std::string n ) : name( n ) {};
	~Player( void ) {}

	virtual void makeBid( void ) = 0;
	virtual void playDomino( Bid bid, DominoCollection trick ) = 0;

	void printName( std::ostream &o );
	void printHand( std::ostream &o );


};

std::ostream & operator << ( std::ostream & out, Player &p );
#endif
