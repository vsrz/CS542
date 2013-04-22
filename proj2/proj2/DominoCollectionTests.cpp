
#include <iostream>
#include <vector>
#include <iterator>
#include "DominoCollectionTests.h"
#include "Domino.h"
#include "DominoCollection.h"

void DominoCollectionTests::RunAllTests( void )
{
	// Other tests do this already
	// DominoCollectionAddDominoes();
    DominoCollectionDrawRandomDominoes();
    DominoCollectionShuffleTest();
}

void DominoCollectionTests::DominoCollectionShuffleTest( void )
{
    name = "DominoCollection Shuffling Test";
    beginTest();
    DominoCollection dominoes;
	DominoCollection lastshuffle;

	dominoes.addDomino( Domino( 6,6 ) );
	dominoes.addDomino( Domino( 6,5 ) );
	dominoes.addDomino( Domino( 6,4 ) );
	dominoes.addDomino( Domino( 6,3 ) );
	dominoes.addDomino( Domino( 6,2 ) );
	dominoes.addDomino( Domino( 6,1 ) );
	dominoes.addDomino( Domino( 6,0 ) );
	dominoes.addDomino( Domino( 5,5 ) );
	dominoes.addDomino( Domino( 5,4 ) );
	dominoes.addDomino( Domino( 5,3 ) );
	dominoes.addDomino( Domino( 5,2 ) );
	dominoes.addDomino( Domino( 5,1 ) );
	dominoes.addDomino( Domino( 5,0 ) );
	dominoes.addDomino( Domino( 4,4 ) );
	dominoes.addDomino( Domino( 4,3 ) );
	dominoes.addDomino( Domino( 4,2 ) );
	dominoes.addDomino( Domino( 4,1 ) );
	dominoes.addDomino( Domino( 4,0 ) );
	dominoes.addDomino( Domino( 3,3 ) );
	dominoes.addDomino( Domino( 3,2 ) );
	dominoes.addDomino( Domino( 3,1 ) );
	dominoes.addDomino( Domino( 3,0 ) );
	dominoes.addDomino( Domino( 2,2 ) );
	dominoes.addDomino( Domino( 2,1 ) );
	dominoes.addDomino( Domino( 2,0 ) );
	dominoes.addDomino( Domino( 1,1 ) );
	dominoes.addDomino( Domino( 1,0 ) );
	dominoes.addDomino( Domino( 0,0 ) );

	lastshuffle = dominoes;

    std::cout << "WARNING: Test may fail if the same shuffle occurs twice" << std::endl;
    for( int i = 0; i < 5; ++i ) 
    {
        dominoes.shuffle();
		std::cout << "Shuffling dominoes.";
		assert( lastshuffle != dominoes );
		std::cout << " Ok." << std::endl;
		lastshuffle = dominoes;
    }

	std::cout << std::endl;

    endTest();
}

void DominoCollectionTests::DominoCollectionDrawRandomDominoes( void )
{
    name = "DominoCollection Draw Random Dominoes";
    beginTest();
    Domino doubleFive( 5, 5 );
    Domino doubleFour( 4, 4 );
    Domino treySix( 3, 6 );
    Domino doubleOne( 1, 1);

    DominoCollection trick;

    std::cout << "Insert dominoes into collection";

    trick.addDomino( doubleFive );
	assert(trick.contains( doubleFive ));
    trick.addDomino( doubleFour );
	assert(trick.contains( doubleFour ));
    trick.addDomino( treySix );
	assert(trick.contains( treySix ));
    trick.addDomino( doubleOne );
	assert(trick.contains( doubleOne ));
	std::cout << " Ok." << std::endl;

    std::cout << "Remove " << trick.getSize() << " dominoes in order from Collection.";
    Domino d;

    d = trick.removeDomino();
    assert( d == doubleOne );
    d = trick.removeDomino();
    assert( d == treySix );
    d = trick.removeDomino();
    assert( d == doubleFour );
    d = trick.removeDomino();
    assert( d == doubleFive );
    std::cout << " Ok." << std::endl;

    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( doubleOne );

    std::cout << "Draw " << trick.getSize() << " random dominoes from Collection.";
    
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );
	d = trick.drawDomino();
	assert( ! trick.contains( d ) );

	std::cout << " Ok." << std::endl;

    endTest();

}

void DominoCollectionTests::DominoCollectionAddDominoes( void )
{

    name = "DominoCollection Adding Dominoes";
    
    Domino doubleFive( 5, 5 );
    Domino doubleFour( 4, 4 );
    Domino treySix( 3, 6 );
    Domino oneOne( 1, 1);

    beginTest();

    DominoCollection trick;

    std::cout << "Create and print a collection." << std::endl;
    trick.addDomino( doubleFive );
    std::cout << "Add 5,5" << trick << std::endl;
    trick.addDomino( doubleFour );
    std::cout << "Add 4,4" << trick << std::endl;
    trick.addDomino( treySix );
    std::cout << "Add 3,6" << trick << std::endl;
    trick.addDomino( oneOne );
    std::cout << "Add 1,1" << trick << std::endl;
    trick.addDomino( doubleFive );
    std::cout << "Add 5,5" << trick << std::endl;
    trick.addDomino( doubleFour );
    std::cout << "Add 4,4" << trick << std::endl;
    trick.addDomino( treySix );
    std::cout << "Add 3,6" << trick << std::endl;
    trick.addDomino( oneOne );
    std::cout << "Add 1,1" << trick << std::endl;


    std::cout << "Create and print a collection." << std::endl;
    std::cout << trick << std::endl;
    std::cout << " Ok." << std::endl;

    endTest();
}
