
#ifndef TEXAS42GAME_H
#define TEXAS42GAME_H
#pragma once


#include "DominoGame.h"

class Texas42Game : DominoGame {

private:
	int Bid_currentBid;
	int Domino_trump;
	int DominoCollection_played;
	int leadPlayer;

public:
	void playTrick();

	void drawDominoes();

	void solicitBid();
};

#endif
