

#include "TrickTests.h"
#include "PlayerAI.h"
#include "Domino.h"


void TrickTests::RunAllTests( void )
{
    TrickWinner();
}

void TrickTests::TrickWinner( void )
{
    name = "Test trick winner logic";
    beginTest();
    
    Domino fiveFive( 5,5 );
    Domino fiveSix( 5,6 );
    Domino oneOne( 1,1 );
    Domino deuceTrey( 2,3 );
    Domino deuceFour( 4,2 );
    PlayerAI a[4];
    for( int i = 0; i < 4; ++i )
    {
        a[i].setName( "Player " + i );
    }

    int trump = 5;
    std::cout << "Set trump to 5.";
    Trick trick( trump );
    assert( trick.getTrump() == trump );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 1 plays " << fiveFive;
    trick.addDomino( fiveFive, &a[0] );
    assert( trick.contains( fiveFive ) );
    assert( trick.getWinner() == &a[0] );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 2 plays " << fiveSix;
    trick.addDomino( fiveSix, &a[1] );
    assert( trick.contains( fiveSix ) );
    assert( trick.getWinner() == &a[0] );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 3 plays " << deuceTrey;
    trick.addDomino( deuceTrey, &a[2] );
    assert( trick.contains( deuceTrey ) );
    assert( trick.getWinner() == &a[0] );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 4 plays " << deuceFour;
    trick.addDomino( deuceFour, &a[3] );
    assert( trick.contains( deuceFour ) );
    assert( trick.getWinner() == &a[0] );
    std::cout << " Ok." << std::endl;

    std::cout << "Player 1 wins the trick ";
    assert( trick.getWinner() == &a[0] );
    std::cout << std::endl;

    //TODO: Add more test cases


    endTest();
}

