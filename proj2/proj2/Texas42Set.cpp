#include "Texas42Set.h"

/**
 *  Play all the tricks
 */
void Texas42Set::playTricks( void )
{
    //Player *trickWinner;

    // play tricks until all tricks are played
    for( int turns = 0; turns <= 7; ++turns )
    {
        // Have each player play a domino

        // Set the winner of the trick as the first bidder
    }

}

/**
 * solicit bids and trumps from the players
 **/ 
Bid Texas42Set::solicitBids( void )
{           
    Bid highBid;
    Player *highBidder;

    // Set the opening bidder 
    table->setNextPlayer( firstBid );

    // Go around the table and get the bids
    for( int player = table->playerCount(); player = 0; --player )
    {
        Bid b;
        Player *bidder = table->nextPlayer();        
        b = bidder->makeBid( bid );

        // If the bid is higher than the current high bid, set the high bidder and bid
        if( b > highBid ) 
        {
            highBidder = bidder;        
            highBid = b;
        }
    }

    // Set the high bid and player as the first to act
    table->setNextPlayer( highBidder );
    
    return highBid;
}

/**
 *
 */
void Texas42Set::play( void )
{
    //Player *openingBidder;

    // Get the bids and set the winning bid as the starting player
    bid = solicitBids();

    // Play game
    playTricks();

    
    // Determine the winners for this game

    

}
