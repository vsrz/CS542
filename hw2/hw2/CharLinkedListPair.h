//
//  LinkedListPair.h
//  hw2
//
//  Created by  on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw2_CharLinkedListPair_h
#define hw2_CharLinkedListPair_h

using namespace std;
typedef class CharLinkedListPair* CharLinkedList;

class CharLinkedListPair
{
public:
    char info;
    CharLinkedList next;
    CharLinkedListPair( char newInfo, CharLinkedList newNext ) 
	: info( newInfo ), next( newNext )  {}
};



#endif
