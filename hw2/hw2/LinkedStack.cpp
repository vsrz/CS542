//
//  LinkedStack.cpp
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include "LinkedStack.h"

using namespace std;

class LinkedStack
{
private:
    CharLinkedList head;
public:
    LinkedStack() : head( 0 ) { }
    void push( char c )
    {
        head = new CharLinkedListPair( c, head );
    }
    char pop()
    {
        char c = head->info;
        CharLinkedList p = head;
        head = head->next;
        delete p;
        return c;
    }
    void print( ostream & out )
    {
        for ( CharLinkedList p = head; p != 0; p = p->next )
            out << p->info << ' ';
    }
    ~LinkedStack()
    {
        CharLinkedList temp;
        for ( CharLinkedList p = head; p != 0; )
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }
};
