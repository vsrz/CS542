#include "Texas42Set.h"

void Texas42Set::drawHands( Player *firstDraw )
{
    players->setNextPlayer( firstDraw );
	do
	{
		players->getNextPlayer()->drawDominoes( dominoSet );
    } while( players->nextPlayer() != firstDraw );

}

/**
 * Determines the set winner and awards marks to the winning team
 */
void Texas42Set::resolveSet( void )
{
    int marks = 1;

	// This will need to change so as to consider bids 2/3/4 marks etc.
    if( winningBid.getBid() > 42 ) marks++;

	/** 
	 *  If the seat of the winning bidder did not make their bid, increment 
	 *  the seat of the game winner by 1 so the opposing team will be assigned
	 *  winning marks
	 */
	  
    
}

/**
 *  Play a trick and return the index of the player that won the trick
 * starting with the lead Player.
 */
Player* Texas42Set::playTrick( Trick *trick, Player *lead)
{    
    int winner = 0;
    players->setNextPlayer( lead );

    // Have each player play a domino
    do
    {
        trick->addDomino( players->getNextPlayer()->playDomino( winningBid, *trick ) );
    } while( lead != players->nextPlayer() );
    
    // Set the winner of the trick as the first player for the next trick
    winner = trick->getWinner();


    return NULL;
}

/**
 * solicit bids and trumps from the players
 */ 
int Texas42Set::solicitBids( void )
{           
    Bid highBid;
    int highBidder;

    // Set the opening bidder 
    players->setNextPlayer( openingBidder );

    // Go around the table and get the bids
	/*do
	{

	} while( players->nextPlayer() != openingBidder );
    */
    // Set the high bid and player as the first to act
    //return highBidder;
	return 0;
}

/**
 * Set the winning bid for this set
 */
void Texas42Set::setWinningBid( Bid bid )
{
    winningBid = bid;
}

/**
 * Gives the count provided by the trick to the winning team
 */
void Texas42Set::giveCount( int lead, Trick trick )
{
}

/**
 * Play this set and give marks to the winning team
 */
void Texas42Set::play( void )
{
    // Draw hands
    drawHands( openingBidder );

    // Get the bids and set the winning bid as the starting player
    int lead = solicitBids();
    
    // Set the winning bidder for this set
    //winningBidder = lead + 1;

    // Play each trick
	/*
    for( int turn = 0; turn < 7; ++turn )
    {
        lead = playTrick( &tricks[turn], lead );
        std::cout << tricks[turn] << std::endl;
        players->setNextPlayer( lead );
        Player *winner = players->nextPlayer();
        std::cout << *winner << " wins the trick!" << std::endl;
        // Assign the points for the trick
        giveCount( lead, tricks[turn] );
        
    }
	*/
    resolveSet();
    //std::cout << 9
    //Player *winner = players->nextPlayer();

    

}
