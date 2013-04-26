#include "Texas42SetTests.h"
#include "PlayerAI.h"
#include "DominoCollection.h"
#include "PlayerCollection.h"
#include "Trick.h"

void Texas42SetTests::RunAllTests( void )
{
    PlayTrick();

}

void Texas42SetTests::PlayTrick( void )
{
    name = "Play a mock trick";
    DominoCollection doubleSixSet;
    doubleSixSet.generateDoubleSixSet();

    PlayerAI p1( "Player 1", 0 );
    PlayerAI p2( "Player 2", 1 );
    PlayerAI p3( "Player 3", 2 );
    PlayerAI p4( "Player 4", 3 );

    std::cout << "Add players to the game";
    PlayerCollection players;
    players.addPlayer( &p1 );
    players.addPlayer( &p2 );
    players.addPlayer( &p3 );
    players.addPlayer( &p4 );
    std::cout << " Ok." << std::endl;

    std::cout << "Set the winning bid";
    Bid b( 30, 6 );
    std::cout << " Trump: " << b.getTrump() << " Ok." << std::endl;
    
    Texas42Set set( &players, doubleSixSet, 0 );
    set.setWinningBid( b );
    
    Trick trick[7];    
    
    std::cout << "Draw hands for the players";
    for( int i = 0; i < 4; ++i )
    {
        players.nextPlayer()->drawDominoes( doubleSixSet );
    }
    std::cout << " Ok." << std::endl;
    

    int winner = 0;
    for( int i = 0; i < 7; ++i ) 
    {
        std::cout << "Play the trick";
        trick[i].setTrump( 6 );
        winner = set.playTrick( &trick[i], winner );
        std::cout << trick[i] << " Winner: " << winner << " Ok." << std::endl;

    }

    endTest();


}
