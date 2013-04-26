
#include "PlayerCollection.h"


PlayerCollection::PlayerCollection(void)
{
    turn = -1;
    marks[0] = 0;
    marks[1] = 0;
}


PlayerCollection::~PlayerCollection(void)
{
}

/**
 * Haven't thought of a better way to implement this right now
 * but the order that you push the players into the collection is
 * the order they are sitting at the table.
 */
void PlayerCollection::addPlayer( Player *p )
{
    if( players.size() < 4 )
    {
        players.push_back( p );
    }
}

/**
 * Returns a pointer to the player that is next up. Only call this once
 * per turn.
 */
Player* PlayerCollection::nextPlayer( void )
{
    turn++;
    if( (size_t) turn > players.size() - 1 ) turn = 0;
    return players[turn];
}

/**
 *  Sets the player who will be returned when nextPlayer() is called
 */
void PlayerCollection::setNextPlayer( int playerIndex )
{
    turn = playerIndex - 1;
}

int PlayerCollection::playerCount( void )
{
    return players.size();
}

/**
 * Returns true if there's a player in the seat
 */
 bool PlayerCollection::contains( int seat )
 {
     return (size_t) seat <= players.size() - 1;
 }

/**
 * Get the team ID that the player in a seat belongs to
 */
int PlayerCollection::getTeam( int seat )
{
    switch( seat )
    {
        case 0:
        case 2:
            return 0;
            break;
        case 1:
        case 3:
            return 1;
            break;
    }
    return -1;
}

/**
 * returns the number of marks for a player (and their partner)
 */
int PlayerCollection::getMarks( int seat )
{
    return marks[ getTeam( seat ) ];
}

void PlayerCollection::addMarks( int seat, int marksGiven )
{
    marks[ getTeam( seat ) ] += marksGiven;
}

/**
 * Returns the address to a player in the collection
 */
Player* PlayerCollection::operator [] ( const int index )
{
    return players[index];
}
