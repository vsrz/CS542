
#ifndef DOMINOCOLLECTION_H
#define DOMINOCOLLECTION_H

#pragma once

#include <vector>
#include <iostream>

#include "Domino.h"



class DominoCollection {

protected:
	std::vector<Domino> dominoes;

public:
	DominoCollection( void ) {}
	DominoCollection( const Domino &d ) { dominoes.push_back( d ); }
	DominoCollection( const std::vector<Domino> &d ) { dominoes = d; }
	~DominoCollection( void ) {} 

	Domino removeDomino( void );
	void drawDomino( void );
	Domino getDomino( Domino d );

	void addDomino( Domino d );
	void shuffle( void );
	bool isEmpty( void );
	void print( std::ostream & out );

	int getSize( void );
};

std::ostream & operator << ( std::ostream & out, DominoCollection d );
#endif

