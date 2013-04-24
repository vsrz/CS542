

#include <iostream>

#ifdef RUN_TESTS

#include "Tests.h"
#include "DominoCollectionTests.h"
#include "DominoTests.h"
#include "RandomNumberGeneratorTests.h"
#include "PlayerTests.h"
#include "PlayerCollectionTests.h"

#endif

int main( int argc, char** argv)
{

#ifdef RUN_TESTS

	DominoTests dt;
	DominoCollectionTests dct;
	RandomNumberGeneratorTests r;
    PlayerTests pt;
    PlayerCollectionTests pct;

	r.RunAllTests();
	dt.RunAllTests();
	dct.RunAllTests();
    pt.RunAllTests();
    pct.RunAllTests();

#endif
    return 0;
}
