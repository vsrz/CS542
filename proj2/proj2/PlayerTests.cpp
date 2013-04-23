
#include <iostream>
#include <string>
#include "PlayerTests.h"


PlayerTests::PlayerTests(void)
{
    name = "PlayerTests";
}


PlayerTests::~PlayerTests(void)
{
}

void PlayerTests::RunAllTests( void )
{
    DrawDominoes();
}

void PlayerTests::DrawDominoes( void )
{
    name = "Draw dominoes for 7 players";
    beginTest();

    DominoCollection set;
    set.generateDoubleSixSet();

    PlayerAI p1("Player 1");    
    PlayerAI p2("Player 2");    
    PlayerAI p3("Player 3");    
    PlayerAI p4("Player 4");    

    p1.drawDominoes( set );
    assert( set.size() == 21 );

    p2.drawDominoes( set );
    assert( set.size() == 14 );
    assert( p1.getHand() != p2.getHand() );

    p3.drawDominoes( set );
    assert( set.size() == 7 );
    assert( p1.getHand() != p3.getHand() );
    assert( p2.getHand() != p3.getHand() );

    p4.drawDominoes( set );
    assert( p1.getHand() != p4.getHand() );
    assert( p2.getHand() != p4.getHand() );
    assert( p3.getHand() != p4.getHand() );

    assert( set.size() == 0 );
    
    std::cout << " Ok." << std::endl;
    endTest();

}