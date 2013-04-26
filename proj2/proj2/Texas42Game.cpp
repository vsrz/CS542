
#include "Texas42Game.h"
#include "Texas42Set.h"

void Texas42Game::createPlayers()
{
    // Creates AI players for this set
    for( int i = 0; i < 4; ++i )
    {
        player[i].setName( "Player " + i );
        table.addPlayer( &player[i] );
    }

    // Sets partners for them
    for( int i = 0; i < 2; ++i )
    {
        player[i].setPartner( & player[i+2] );
        player[i+2].setPartner( & player[i] );
    }
}

void Texas42Game::begin( DominoCollection set )
{    
    // Add the players to the table
    createPlayers();

    // Generate a playset
    dominoSet.generateDoubleSixSet();    

    // Set the opening bidder
    

    // Enter set loop
    while( table.getMarks( &player[0] ) < 7  && table.getMarks( &player[1] ) < 7 )
    {
        // Shuffle the dominoes
        dominoSet.shuffle();
        
        // Set the first bidder
        firstBidder = &player[setsPlayed % 4];

        // continue to play sets until one team makes their mark
        Texas42Set set( &table, dominoSet, firstBidder );
        set.play();

    }

    
}
