//
//  LinkedListStack.h
//  hw2
//
//  Created by Jeremy Villegas on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef __hw2__LinkedStack__
#define __hw2__LinkedStack__

#include <iostream>
#include "CharLinkedListPair.h"
#include "StackMomento.h"

using namespace std;

class LinkedStack
{
private:
    CharLinkedList head;
	friend class StackMomento;

public:
    LinkedStack() : head( 0 ) { }
    void push( char c );
    char pop();
	int size();
    void print( ostream & out );
	void restore(StackMomento* l);
    ~LinkedStack();
	StackMomento* createMomento();
};

ostream &operator<<(ostream &out, LinkedStack &s);
#endif /* defined(__hw2__LinkedStack__) */
