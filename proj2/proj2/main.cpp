

#include <iostream>

#ifdef RUN_TESTS

#include "Tests.h"
#include "DominoCollectionTests.h"
#include "DominoTests.h"
#include "RandomNumberGenerator.h"

#endif

int main( int argc, char** argv)
{

#ifdef RUN_TESTS

	DominoTests dt;
	DominoCollectionTests dct;

	dt.RunAllTests();
	dct.RunAllTests();

#endif
    return 0;
}
