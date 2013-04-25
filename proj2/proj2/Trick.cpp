
#include "Trick.h"

#include <iostream>


/**
 * Play a domino for this trick, keeping track of the
 * player who played it
 */
void Trick::addDomino( Domino d, Player *p )
{
    DominoCollection::addDomino( d );
    player[dominoes.size() - 1] = p;
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
            if( winningDomino.getHighPip() == trump )
            {
                suit = trump;
            }
             
        } 
        // if not the first domino, check to see if its larger
        else
        {
            // if the current leader is not trump, ours automatically wins, and we set trump as suit
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
                }
            }

            // the current leader plays a suit which we followed
            else if(  winningDomino.isLargerThan( *it, suit ) )
            {
                winningPlayerIndex = currentPlayerIndex;
                winningDomino = *it;
            }
        }
        
        currentPlayerIndex++;
    }

    return player[winningPlayerIndex];

}
