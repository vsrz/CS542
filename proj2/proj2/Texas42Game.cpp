
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
    while( table.getMarks( table.getTeam( 0 ) ) < 7  && table.getMarks( table.getTeam( 1 ) ) < 7 )
    {
        // Shuffle the dominoes
        dominoSet.shuffle();
        
        // continue to play sets until one team makes their mark
        Texas42Set set( &table, dominoSet, firstBidder++ % 4 );
        set.play();

    }

    if( table.getMarks( 0 ) > 7 ) 
    {
        std::cout << player[0] << " and " << player[2];
    }
    else
    {
        std::cout << player[1] << " and " << player[3];
    }

    std::cout << " have won the game!" << std::endl;

}
