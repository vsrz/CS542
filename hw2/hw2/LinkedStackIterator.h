//
//  LinkedStackIterator.h
//  hw2
//
//  Created by Jeremy Villegas on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef __hw2__LinkedStackIterator__
#define __hw2__LinkedStackIterator__

#include "LinkedStack.h"

class LinkedStackIterator
{
    LinkedStack* collection;
    CharLinkedListPair* current;
public:
    LinkedStackIterator(LinkedStack * s);
    char index();
    bool end();
    void next();
    void begin();
	~LinkedStackIterator();
};
ostream &operator<<(ostream &out, LinkedStack &l);

#endif /* define __he2__LinkedStackIterator__ */
