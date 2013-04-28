#include "Texas42Set.h"

void Texas42Set::drawHands( int firstDraw )
{
    table->setNextPlayer( firstDraw );
    for( int i = 0; i < 4; ++i )
    {
        table->nextPlayer()->drawDominoes( dominoSet );
    }

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
    if( teamCount[winningBidder % 2] < winningBid.getBid() ) winningBidder += 1;
    table->addMarks( (winningBidder % 2), marks );    
    table->addMarks( (winningBidder % 2) + 2, marks ); 

	  
    table->setNextPlayer( winningBidder );
    Player *team = table->nextPlayer();
    std::cout << *team << (marks > 0 ? " made " : " missed ") << "their bid!" << std::endl;
    
    std::cout << "Team 1: " << table->getMarks( 0 ) << " Team 2: " << table->getMarks( 1 ) << std::endl << std::endl;

}

/**
 *  Play a trick and return the index of the player that won the trick
 * starting with the lead Player.
 */
int Texas42Set::playTrick( Trick *trick, int leadPlayerIndex )
{    

    table->setNextPlayer( leadPlayerIndex );

    // Have each player play a domino
    for( int i = 0; i < 4; ++i )
    {
        trick->addDomino( table->nextPlayer()->playDomino( winningBid, *trick ) );
    }
    
    // Set the winner of the trick as the first player for the next trick
    return( trick->getWinner() );
}

/**
 * solicit bids and trumps from the players
 */ 
int Texas42Set::solicitBids( void )
{           
    Bid highBid;
    int highBidder;

    // Set the opening bidder 
    table->setNextPlayer( firstBid );

    // Go around the table and get the bids
    for( int seat = 0; seat < 4; ++seat )
    {
        Bid b;
        Player *bidder = table->nextPlayer();
        b = bidder->makeBid( highBid );

        // If the bid is higher than the current high bid, set the high bidder and bid
        if( b > highBid ) 
        {
            highBidder = (seat + firstBid) % 4;        
            highBid = b;
        }
    }

    // Set the high bid and player as the first to act
    table->setNextPlayer( highBidder );
    winningBid = highBid;
    return highBidder;
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
    teamCount[lead % 2] += trick.getValue();
}

/**
 * Play this set and give marks to the winning team
 */
void Texas42Set::play( void )
{
    // Draw hands
    drawHands( firstBid + 1 );

    // Get the bids and set the winning bid as the starting player
    int lead = solicitBids();
    
    // Set the winning bidder for this set
    winningBidder = lead + 1;

    // Play each trick
    for( int turn = 0; turn < 7; ++turn )
    {
        lead = playTrick( &tricks[turn], lead );
        std::cout << tricks[turn] << std::endl;
        table->setNextPlayer( lead );
        Player *winner = table->nextPlayer();
        std::cout << *winner << " wins the trick!" << std::endl;
        // Assign the points for the trick
        giveCount( lead, tricks[turn] );
        
    }

    resolveSet();
    //std::cout << 9
    //Player *winner = table->nextPlayer();

    

}
