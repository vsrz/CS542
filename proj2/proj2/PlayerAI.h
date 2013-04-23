
#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "Player.h"

class PlayerAI : public Player {

public:
    PlayerAI( void ) : Player () {}
    PlayerAI( std::string s ) : Player ( s ) {}
	void makeBid( void );
	void playDomino( Bid bid, DominoCollection trick );


};

#endif
