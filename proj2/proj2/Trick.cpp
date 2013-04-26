
#include "Trick.h"

#include <iostream>


/**
 * Play a domino for this trick, keeping track of the
 * player who played it. Do not allow more than 4 dominoes in a trick
 */
void Trick::addDomino( Domino d, Player *p )
{
    if( dominoes.size() < 4 )
    {
        DominoCollection::addDomino( d );
        player[dominoes.size() - 1] = p;
    }
}

int Trick::getTrump( void )
{
    return trump;
}

void Trick::setTrump( int t )
{
    trump = t;
}
/**
 *  Returns the current winner of this trick, even if it's in progress
 */
Player* Trick::getWinner( void )
{
    if(dominoes.size() == 0) 
    {
        return NULL;
    }
    
    if(dominoes.size() == 1)
    {
        return player[0];
    }

    Domino winningDomino;
    int winningPlayerIndex = 0;
    int currentPlayerIndex = 0;
    int suit;
    for( std::vector<Domino>::iterator it = dominoes.begin();
        it != dominoes.end();
        ++it )
    {
        // always assign the first domino as the winning domino
        if( currentPlayerIndex == 0 ) 
        {
            winningDomino = *it;

            // set the suit of the domino
            suit = winningDomino.getHighPip();

            // override the suit if the domino is trump
            if( winningDomino.isSuit( trump ) )
            {
                suit = trump;
            }
             
        } 
        // if not the first domino, check to see if its larger
        else
        {
            // if the current leader is not trump and ours is, we win and set trump as suit
            if( !winningDomino.isSuit( trump ) && it->isSuit( trump ) )
            {
                winningPlayerIndex = currentPlayerIndex;
                winningDomino = *it;
                suit = trump;
            }
            
            // if the current leader is a trump suit and so is ours, compare it
            else if( winningDomino.isSuit( trump ) && it->isSuit( trump ) )
            {
                if( it->isLargerThan( winningDomino, trump ) )
                {
                    winningPlayerIndex = currentPlayerIndex;
                    winningDomino = *it;
                }
            }

            // the current leader plays a suit which we followed
            else if( it->isLargerThan( winningDomino, suit ) )
            {
                winningPlayerIndex = currentPlayerIndex;
                winningDomino = *it;
            }
        }
        
        currentPlayerIndex++;
    }

    return player[winningPlayerIndex];

}

/**
 *  Returns the number of points that this trick is worth
 */
int Trick::getValue( void )
{
    // All tricks are worth at least 1 point
    int value = 1;
    
    for( std::vector<Domino>::iterator it = dominoes.begin();
        it != dominoes.end();
        ++it )
    {    
        value += it->isCounter();
    }

    return value;
}
