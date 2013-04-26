#include "Texas42Set.h"

/**
 * Determines the set winner and awards marks to the winning team
 */
void Texas42Set::resolveSet( void )
{
    int countTeam1 = 0;
    int countTeam2 = 0;

    // for each trick, add the proper points to the team that won the trick
    for( int i = 0; i < 7; ++i )
    {
        //if( tricks[i].getWinner() == table->
    }
    //if( bid.getBid() > 
    
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
 *
 */
void Texas42Set::play( void )
{
    //Player *openingBidder;

    // Get the bids and set the winning bid as the starting player
    int lead = solicitBids();

    // Play game
    for( int turn = 0; turn <= 7; ++turn )
    {
        lead = playTrick( &tricks[turn], lead );
    }

    // Determine the winners for this game and assign marks

    

}
