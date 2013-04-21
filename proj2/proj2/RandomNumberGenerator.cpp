
#include <ctime>
#include <cstdlib>

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator( void )
{
	seed = time( NULL );
}

int RandomNumberGenerator::nextNumber( int maxint )
{
	return rand() % (maxint);

}
