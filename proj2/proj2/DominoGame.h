
#ifndef DOMINOGAME_H
#define DOMINOGAME_H
#pragma once


#include "PlayerHuman.h"
#include "DominoCollection.h"

class DominoGame {

protected:
	// PlayerHuman player;
	DominoCollection dominoSet;


public:

	void beginGame();
};

#endif
