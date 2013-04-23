

#include <iostream>

#ifdef RUN_TESTS

#include "Tests.h"
#include "DominoCollectionTests.h"
#include "DominoTests.h"
#include "RandomNumberGeneratorTests.h"
#include "PlayerTests.h"

#endif

int main( int argc, char** argv)
{

#ifdef RUN_TESTS

	DominoTests dt;
	DominoCollectionTests dct;
	RandomNumberGeneratorTests r;
    PlayerTests pt;

	r.RunAllTests();
	dt.RunAllTests();
	dct.RunAllTests();
    pt.RunAllTests();

#endif
    return 0;
}
