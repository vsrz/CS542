
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

    std::cout << "Insert dominoes into collection";

    trick.addDomino( doubleFive );
    trick.addDomino( doubleFour );
    trick.addDomino( treySix );
    trick.addDomino( oneOne );

    std::cout << trick << std::endl;

    std::cout << "Draw " << trick.getSize() << " dominoes in order from Collection." << std::endl;
    while( !trick.isEmpty() )
    {
        Domino d = trick.removeDomino();
        std::cout << d;
    }

    std::cout << "Ok." << std::endl;

    DominoCollection t2;
    t2.addDomino( doubleFive );
    t2.addDomino( doubleFour );
    t2.addDomino( treySix );
    t2.addDomino( oneOne );

    std::cout << "Draw 4 random dominoes from Collection." << std::endl;
    t2.drawDomino();
    // while( !trick.isEmpty() )
    // {
    //     trick.drawDomino();
    //     //Domino d = trick.drawDomino();
    //     //std::cout << d;
    // }
    std::cout << "Ok." << std::endl;

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
