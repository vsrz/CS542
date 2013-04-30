#include "Team.h"


Team::Team(void)
{
	marks = 0;
}


Team::~Team(void)
{
}

void Team::addMarks( int marks )
{
	this->marks += marks;
}

int Team::getMarks( void )
{
	return marks;
}

// Returns true if the given player is a member of this team
bool Team::isMember( Player *player )
{
	return PlayerCollection::contains( player );
}
