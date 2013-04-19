
#ifndef DOMINOGAME_H
#define DOMINOGAME_H
#pragma once

#include "Player.h"
#include "DominoCollection.h"

class DominoGame {

private:
	Player player;
	DominoCollection dominoSet;

public:
	void beginGame();
};

#endif
