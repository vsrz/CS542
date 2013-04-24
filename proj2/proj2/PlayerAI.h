
#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "Player.h"

class PlayerAI : public Player {

public:
    PlayerAI( void ) : Player () {}
    PlayerAI( std::string s ) : Player ( s ) {}
	
    Bid makeBid( Bid b );
	//Domino playDomino( Bid bid, int trump, DominoCollection trick );


};

#endif
