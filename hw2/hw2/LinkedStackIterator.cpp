//
//  LinkedStackIterator.cpp
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include "LinkedStack.h"

LinkedStackIterator::LinkedStackIterator(LinkedStack * s)
{
	collection = s;
	reset();
}

char LinkedStackIterator::index()
{
	return current->value;
}

bool LinkedStackIterator::end()
{
	return current == 0;
}

void LinkedStackIterator::next()
{
	current = current->next;
}

void LinkedStackIterator::begin()
{
	current = collection->head;
}

LinkedStackIterator::~LinkedStackIterator() {}

