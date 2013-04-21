
#include <iterator>
#include <vector>

#include "DominoCollection.h"
#include "RandomNumberGenerator.h"


/**
 * Adds the specified domino into the queue of dominoes
 */
void DominoCollection::addDomino( Domino d ) {
	dominoes.push_back( d );
}

/**
 * Removes and returns an instance of the next domino on the queue of dominoes.
 */
Domino & DominoCollection::removeDomino( void )
{
	this->lastDomino = dominoes.back();
	dominoes.pop_back();
	return lastDomino;
}

/**
 * Removes and returns a random domino from the queue
 */	
Domino & DominoCollection::drawDomino( void )
{
	RandomNumberGenerator r;
	int index = r.nextNumber( dominoes.size()  );
	lastDomino = *( dominoes.end() - index );
	// std::cout << "Erase Index: " << index << " Size: " << dominoes.size() << d << std::endl;
	dominoes.erase( dominoes.end() - index );
	return lastDomino;
	

}

/**
 * Shuffles the dominoes in the entire queue
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
 * Prints all the dominoes in the queue, in order
 */
void DominoCollection::print( std::ostream & o )
{
	int count = 0;
	
	// loop through each domino in the queue and print it
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

