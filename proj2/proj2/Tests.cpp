
#include "Tests.h"
#include "DominoCollectionTests.h"



void Tests::beginTest( void )
{
    std::cout << "** Begin Test : " << name << " **" << std::endl;
}

void Tests::endTest( void )
{
    std::cout << "** End Test **" << std::endl;
    std::cout << "Press enter to continue...";
    getchar();
    std::cout << std::endl;
}
