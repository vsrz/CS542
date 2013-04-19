
#ifndef DOMINOCOLLECTION_H
#define DOMINOCOLLECTION_H

#pragma once

#include "Domino.h"



class DominoCollection {

private:
	int count;
	int Domino_dominoes;

public:
	void addRandomDomino();

	void addDomino();

	void shuffle();

	void getDomino();
};

#endif

