#include "DominoCollection.h"

/**
 * Adds the specified domino into the stack of dominoes
 */
void DominoCollection::addDomino( Domino d ) {
	dominoes.push_back( d );
}

/**
 * Removes and returns an instance of the next domino on the stack of dominoes.
 */
Domino DominoCollection::drawDomino( void )
{

}

/**
 * Removes and returns a random domino from the stack
 */	
Domino DominoCollection::drawRandomDomino( void )
{

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

std::ostream & operator << ( std::ostream & out, DominoCollection d )
{
	d.print( out );
	return out;

}

