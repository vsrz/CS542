
#include "Player.h"


DominoCollection Player::getHand( void )
{
    return hand;
}

void Player::setName( std::string n )
{
    name = n;
}

void Player::printName( std::ostream &o )
{
    o << name;
}

void Player::printHand( std::ostream &o )
{
    o << hand;

}
   
void Player::setPartner( Player *p )
{
    partner = p;
}

Player *Player::getPartner( void )
{
    return partner;
}

void Player::drawDominoes( DominoCollection & set )
{
    while( hand.size() < 7 ) hand.addDomino( set.drawDomino() );
}


std::ostream & operator << ( std::ostream & out, Player &p )
{
    p.printName( out );
    //out << std::endl;
    //p.printHand( out );
    return out;
}
