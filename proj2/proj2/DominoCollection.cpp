
#include <iterator>
#include <vector>
#include <cassert>

#include "DominoCollection.h"
#include "RandomNumberGenerator.h"


/**
 * Adds the specified domino into the stack of dominoes
 */
void DominoCollection::addDomino( Domino d ) {
	dominoes.push_back( d );
}

/**
 * Removes and returns the next domino on the stack of dominoes.
 */
Domino DominoCollection::removeDomino( void )
{
	Domino d(dominoes.back());
	dominoes.pop_back();
	return Domino( d );
}

/**
 * Removes and returns a random domino from the stack
 */	
// Domino DominoCollection::drawDomino( void )
// {
// 	RandomNumberGenerator r;
// 	int index = 0; // = r.nextNumber( dominoes.size()  );
// 	Domino d( dominoes[0] );
// 	dominoes.erase(dominoes.begin());
	
// 	return d;
	

// }
void DominoCollection::drawDomino( void )
{
    assert(dominoes.size() != 0 && "Your vector is empty");
    int index = 0; //random.nextNumber( dominoes.size()  );
    assert(index < dominoes.size() && "Buffer overflow...");
    std::cout << " Size is > 0 " << std::endl;
    dominoes.erase( dominoes.begin() + index );
}
/**
 * Shuffles the dominoes in the entire stack
 */	
void DominoCollection::shuffle() {
	throw "Not yet implemented";
}

/**
 * Returns and removes a specific domino from the collection, returning an instance
 * of the domino.
 */
Domino DominoCollection::getDomino( Domino d ) {
	throw "Not yet implemented";
}

bool DominoCollection::isEmpty( void )
{
	return dominoes.size() == 0;
}

/**
 * Prints all the dominoes in the stack, in order
 */
void DominoCollection::print( std::ostream & o )
{
	int count = 0;
	
	// loop through each domino in the stack and print it
    for( std::vector<Domino>::iterator it = dominoes.begin();
    		it != dominoes.end();
    		++it )
    {
    	Domino d = *it;
    	o << d;

    	// line-break every 7 dominoes
    	if( ++count % 7 == 0 ) std::cout << std::endl;
    }
    	

}

int DominoCollection::getSize( void )
{
	return dominoes.size();
}

std::ostream & operator << ( std::ostream & out, DominoCollection d )
{
	d.print( out );
	return out;

}

