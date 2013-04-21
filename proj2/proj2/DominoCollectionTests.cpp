
#include "DominoCollectionTests.h"


void DominoCollectionTests::RunAllTests( void )
{
	DominoCollectionAddDominoes();

}


void DominoCollectionTests::DominoCollectionAddDominoes( void )
{

    name = "DominoCollection Adding Dominoes";
    beginTest();

    Domino doubleFive( 5, 5 );
    Domino doubleFour( 4, 4 );
    Domino treySix( 3, 6 );
    Domino oneOne( 1, 1);

    DominoCollection trick;

    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );
    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );
    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );
    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );
    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );

    std::cout << "Create and print a collection." << std::endl;
    std::cout << trick << std::endl;
    std::cout << " Ok." << std::endl;

    endTest();
}
