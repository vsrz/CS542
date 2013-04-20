
#ifndef DOMINOCOLLECTION_H
#define DOMINOCOLLECTION_H

#pragma once

#include <vector>
#include <iostream>

#include "Domino.h"



class DominoCollection {

private:
	int count;
	std::vector<Domino> dominoes;

public:
	
	void addDomino( Domino d );
	Domino drawDomino( void );
	Domino drawRandomDomino( void );
	void shuffle( void );
	Domino getDomino( Domino d );

	void print( std::ostream & out );

};

std::ostream & operator << ( std::ostream & out, DominoCollection d );
#endif

