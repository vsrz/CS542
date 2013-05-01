
#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "Player.h"

class PlayerAI : public Player {

public:
    PlayerAI( void ) : Player () {}
    PlayerAI( std::string p, int s ) : Player ( p, s ) {}
	PlayerAI( std::string p ) : Player ( p ) {}

    Bid makeBid( Bid b );

    Domino playDomino( Bid bid, DominoCollection trick );


};

#endif
