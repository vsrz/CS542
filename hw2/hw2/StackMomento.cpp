//
//  StackMomento.cpp
//  hw2
//
//  Created by Jeremy Villegas on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include "StackMomento.h"
#include "LinkedStack.h"

StackMomento::StackMomento(LinkedStack* l)
{		
	size = l->size();
	data = new char[size];
	int i;
	CharLinkedList p;
	for ( p = l->head, i = 0; p != 0; p = p->next )
		data[i++] = p->info;
	
}	

void StackMomento::restore(LinkedStack* l)
{
	int s = l->size();
	for(int i = 0; i<s; ++i)
		l->pop();

	for(int i = size; i >= 0; i--)
		l->push(data[i]);

}

StackMomento::~StackMomento()
{
	delete data;
}
