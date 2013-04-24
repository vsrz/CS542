
#include "Texas42Game.h"
#include "Texas42Set.h"

void Texas42Game::createPlayers()
{
    for( int i = 0; i < 4; ++i )
    {
        ai[i].setName( "Player " + i );
        table.addPlayer( &ai[i] );
    }
    
}

void Texas42Game::begin( DominoCollection set )
{    
    // Add the players to the table
    createPlayers();

    // Generate a playset
    dominoSet.generateDoubleSixSet();
    

    // Enter set loop
    while( table.getMarks( &ai[0] ) < 7  && table.getMarks( &ai[1] ) < 7 )
    {
        // Shuffle the dominoes
        dominoSet.shuffle();

        // continue to play sets until one team makes their mark
        Texas42Set set( &table, dominoSet );
        set.begin();

    }

    
}
