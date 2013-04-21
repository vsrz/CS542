#include "Domino.h"

Domino::Domino( const Domino &d ) {
    left = d.getHighPip();
    right = d.getLowPip();

}

Domino::~Domino()
{

}

void Domino::setPip( int left, int right )
{
    this->left = left;
    this->right = right;
}

void Domino::setLeftPip( int left )
{
    this->left = left;
}

void Domino::setRightPip( int right )
{
    this->right = right;
}

int Domino::getHighPip() const 
{
	return std::max( left, right );
}

int Domino::getLowPip() const 
{
	return std::min( left, right );
}

bool Domino::isDouble() {
	return left == right;
}


bool Domino::isSuit( int suit ) {
    return suit == left || suit == right;
}

void Domino::print( std::ostream & o )
{
    o << " [ " <<  left << " | " << right << " ] ";

}

/**
 *  Returns true if the domino given is larger than another domino
 */
bool Domino::isLargerThan ( Domino d, int suit )
{
    // If our domino does not match suit, then it cannot possibly be larger
    if( !isSuit( suit ) ) return false;
    
    // If our domino matches suit and the opposing one does not, then ours is larger
    if( isSuit( suit ) && !d.isSuit( suit )) return true;
        
    // Check for doubles
    if( isDouble() ) return true;
    if( d.isDouble() ) return false;

    return( getOppositePip( suit ) > d.getOppositePip( suit ) );
    
}

bool Domino::isSmallerThan( Domino d, int suit )
{
    return ! isLargerThan( d, suit );
}


bool Domino::operator == ( const Domino & d ) const
{
    return d.left == left && d.right == right;
}

bool Domino::operator != ( const Domino & d ) const 
{
    return !( *this == d );
}


Domino & Domino::operator = ( const Domino & d )
{
    *this = d;
}

/**
 *  Returns the opposite pip of the given pip. If the pip
 *  given is not on the domino at all, return -1
 *  Ex: if pip is 5, a 5-2 domino will return 2
 */
int Domino::getOppositePip( int pip )
{
    if( left == pip ) return right;
    if( right == pip ) return left;
    return -1;
}

std::ostream & operator << ( std::ostream & out, Domino & d )
{
    d.print(out);
    return out;
}


