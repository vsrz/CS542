//
//  LinkedStack.cpp
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include "StackMomento.h"
#include "LinkedStack.h"

using namespace std;

void LinkedStack::push( char c )
{
	head = new CharLinkedListPair( c, head );
}

char LinkedStack::pop()
{
	char c = head->info;
	CharLinkedList p = head;
	head = head->next;
	delete p;
	return c;
}

void LinkedStack::print(ostream & out)
{
	for ( CharLinkedList p = head; p != 0; p = p->next )
		out << p->info << ' ';
}

int LinkedStack::size()
{
	int s = 0;
	for ( CharLinkedList p = head; p != 0; p = p->next )
		s++;
	return s;
}

void LinkedStack::restore(StackMomento* l)
{
	l->restore(this);
}
LinkedStack::~LinkedStack() 
{
	CharLinkedList temp;
	for ( CharLinkedList p = head; p != 0; )
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}

StackMomento* LinkedStack::createMomento()
{
	return new StackMomento(this);
}

ostream &operator<<(ostream &out, LinkedStack &s)
{
	s.print(out);
	return(out);

}


