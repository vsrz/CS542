
#include <iostream>
#include <vector>
#include <iterator>
#include "DominoCollectionTests.h"
#include "Domino.h"
#include "DominoCollection.h"

void DominoCollectionTests::RunAllTests( void )
{
	DominoCollectionAddDominoes();
    DominoCollectionDrawRandomDominoes();

}

void DominoCollectionTests::DominoCollectionDrawRandomDominoes( void )
{
    name = "DominoCollection Draw Random Dominoes";
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

    int i = 0;
    std::cout << "Draw " << trick.getSize() << " random dominoes from Collection." << std::endl;
    while( ++i <= 4 )
    {
        Domino d = trick.drawRandomDomino();
        Domino q = trick.drawDomino();
        std::cout << d;
    }

    std::cout << "Ok." << std::endl;

    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );

    // int i = 0;
    // std::cout << "Draw 4 random dominoes from Collection." << std::endl;
    // while( ++i < 4 )
    // {
    //     Domino d = trick.drawRandomDomino();
    //     std::cout << d;
    // }
    // std::cout << "Ok." << std::endl;

    // trick.addDomino( doubleFive );
    // trick.addDomino( doubleFour );
    // trick.addDomino( treySix );
    // trick.addDomino( oneOne );

    // std::cout << "Draw 4 random dominoes from Collection." << std::endl;
    // while( !trick.isEmpty() )
    // {
    //     Domino d = trick.drawRandomDomino();
    //     std::cout << d;
    // }
    // std::cout << "Ok." << std::endl;

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
