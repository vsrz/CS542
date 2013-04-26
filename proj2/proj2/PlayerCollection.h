
#ifndef PLAYERCOLLECTION_H
#define PLAYERCOLLECTION_H

#include "PlayerAI.h"
#include <vector>

#pragma once
class PlayerCollection
{
private:
    std::vector<Player*> players;
    
    int turn;
    int marks[2];
    

public:
    PlayerCollection(void);
    ~PlayerCollection(void);

    void addPlayer( Player *p );
    Player* nextPlayer( void );
    void setNextPlayer( int playerIndex );

    int playerCount( void );
    bool contains( int seat );

    int getTeam( int seat );
    int getMarks( int seat );
    void addMarks( int seat, int marks = 1 );

    Player* operator [] ( const int index );



};

#endif
