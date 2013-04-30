/**
 *	Extends a player collection to hold marks and members of a team
 */

#ifndef TEAM_H
#define TEAM_H

#pragma once
#include "PlayerCollection.h"

class Team : public PlayerCollection
{
private:
	int marks;

public:
	Team(void);
	~Team(void);

	int getMarks( void );
	void addMarks( int marks = 0 );

	bool isMember( Player* player );

};

#endif
