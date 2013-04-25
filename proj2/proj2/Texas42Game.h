
#ifndef TEXAS42GAME_H
#define TEXAS42GAME_H
#pragma once

#include "DominoCollection.h"
#include "PlayerCollection.h"

class Texas42Game 
{

private:
    DominoCollection dominoSet;
    PlayerCollection table;
    PlayerAI player[4];

public:    
    void createPlayers();
    void begin( DominoCollection dominoSet );
};

#endif
