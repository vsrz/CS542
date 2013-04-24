
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
    
    int indexOf( Player *p );
    int getTeam( Player *p );

public:
    PlayerCollection(void);
    ~PlayerCollection(void);

    void addPlayer( Player *p );
    Player* nextPlayer( void );
    void setNextPlayer( Player *p );


    int playerCount( void );
    bool contains( Player *p );

    int getMarks( Player *p );
    void addMarks( Player *p, int marks = 1 );



};

#endif
