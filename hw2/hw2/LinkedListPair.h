//
//  LinkedListPair.h
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw2_LinkedListPair_h
#define hw2_LinkedListPair_h


class CharLinkedListPair
{
public:
    char info;
    CharLinkedList next;
    CharLinkedListPair( char newInfo, CharLinkedList newNext ) : info( newInfo ), next( newNext )  {}
};

typedef class CharLinkedListPair * CharLinkedList;



#endif
