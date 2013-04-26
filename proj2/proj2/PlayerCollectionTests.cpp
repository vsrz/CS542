
#include <iostream>
#include <string>
#include "PlayerCollectionTests.h"
#include "PlayerAI.h"


void PlayerCollectionTests::RunAllTests( void )
{
    TurnTaking();
    MarksTest();
}

void PlayerCollectionTests::TurnTaking( void )
{
    name = "Test turn taking";
    beginTest();

    PlayerAI p1("AI Player 1", 0);
    PlayerAI p2("AI Player 2", 1);
    PlayerAI p3("AI Player 3", 2);
    PlayerAI p4("AI Player 4", 3);

    PlayerCollection table;

    std::cout << "Add " << p1 << " to the collection";
    table.addPlayer( &p1 );
    assert( table.contains( 0 ) );
    std::cout << " Ok." << std::endl;
    
    std::cout << "Add " << p2 << " to the collection";
    table.addPlayer( &p2 );
    assert( table.contains( 1 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Add " << p3 << " to the collection";
    table.addPlayer( &p3 );
    assert( table.contains( 2 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Add " << p4 << " to the collection";
    table.addPlayer( &p4 );
    assert( table.contains( 3 ) );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p1 << "'s turn";
    assert( table.nextPlayer() == &p1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p2 << "'s turn";
    assert( table.nextPlayer() == &p2 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p3 << "'s turn";
    assert( table.nextPlayer() == &p3 );
    std::cout << " Ok." << std::endl;

    std::cout << "Start with " << p4 << "'s turn";
    assert( table.nextPlayer() == &p4 );
    std::cout << " Ok." << std::endl;

    std::cout << "Wrap around for " << p1 << "'s turn";
    assert( table.nextPlayer() == &p1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p2 << "'s turn";
    assert( table.nextPlayer() == &p2 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p3 << "'s turn";
    assert( table.nextPlayer() == &p3 );
    std::cout << " Ok." << std::endl;

    std::cout << "Now it's " << p4 << "'s turn";
    assert( table.nextPlayer() == &p4 );
    std::cout << " Ok." << std::endl;

    std::cout << "Set the turn to " << p2 << ".";
    table.setNextPlayer( 1 );
    assert( table.nextPlayer() == &p2 );
    std::cout << " Ok." << std::endl;

    std::cout << "Set the turn to " << p4 << ".";
    table.setNextPlayer( 3 );
    assert( table.nextPlayer() == &p4 );
    std::cout << " Ok." << std::endl;

    endTest();



}

/** 
 * Simple test for giving a getting marks in a set
 */
void PlayerCollectionTests::MarksTest( void )
{
    name = "Marks test";
    beginTest();
    
    PlayerAI p1("AI Player 1", 0);
    PlayerAI p2("AI Player 2", 1);
    PlayerAI p3("AI Player 3", 2);
    PlayerAI p4("AI Player 4", 3);

    PlayerCollection table;

    table.addPlayer( &p1 );
    table.addPlayer( &p2 );
    table.addPlayer( &p3 );
    table.addPlayer( &p4 );

    std::cout << "Give team 1 a mark";
    table.addMarks( 0, 1 );
    assert(table.getMarks( 0 ) == 1 );
    std::cout << " Ok." << std::endl;

    std::cout << "Give team 2 a mark";
    table.addMarks( 1, 1);
    assert(table.getMarks( 1 ) == 1 );
    std::cout << " Ok." << std::endl;

    endTest();

}

