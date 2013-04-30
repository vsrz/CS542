/**
 *	Extends a player collection to hold marks and members of a team
 */

#ifndef TEAM_H
#define TEAM_H

#pragma once
#include "Player.h"

class Team
{
private:
	Player player[2];
	int marks;

public:
	Team(void);
	~Team(void);

	int getMarks( void );
	void addMarks( int marks = 0 );
	void addPlayer( Player* player );
	bool isMember( Player* player );

};

#endif
