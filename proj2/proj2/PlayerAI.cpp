#include "PlayerAI.h"

Bid PlayerAI::makeBid( Bid b ) {
	
    // Just return a bid for now
    //return Bid( 30, 0, (Player*) this);
	return Bid(30, 0);
}


Domino PlayerAI::playDomino( Bid bid, DominoCollection trick )
{
    // For now, draw a random domino, ignoring rules
    return hand.drawDomino();
}
