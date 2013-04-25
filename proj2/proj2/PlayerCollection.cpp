
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
    players.push_back( p );
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
void PlayerCollection::setNextPlayer( Player *p )
{
    turn = indexOf( p ) - 1;
}

int PlayerCollection::playerCount( void )
{
    return players.size();
}

int PlayerCollection::indexOf( Player *p )
{
    int i = -1;
    for( std::vector<Player*>::iterator it = players.begin();
         it != players.end();
         ++it )
     {
         ++i;
         if( *it == p ) return i;
     }

     return -1;

}

 bool PlayerCollection::contains( Player *p )
 {
     return indexOf( p ) >= 0;
 }

/**
 * Get the team ID that the player belongs to
 */
int PlayerCollection::getTeam( Player *p )
{
    int seatNum = indexOf( p );
    switch( seatNum )
    {
        case 0:
        case 2:
            return 0;
            break;
        case 1:
        case 3:
            return 1;
            break;
        default:
            return -1;

    }

}
/**
 * returns the number of marks for a player (and their partner)
 */
int PlayerCollection::getMarks( Player *p )
{
    return marks[ getTeam( p ) ];
}

void PlayerCollection::addMarks( Player *p, int marksGiven )
{
    marks[ getTeam( p ) ] += marksGiven;
}
