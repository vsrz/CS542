//
//  StackMomento.h
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef __hw2__StackMomento__
#define __hw2__StackMomento__

class LinkedStack;
 
class StackMomento 
{
	friend class LinkedStack;
	char* data;
	int size;
	StackMomento(LinkedStack* l);
	void restore(LinkedStack* l);	
public:

	~StackMomento();
	
};

#endif /* defined(__hw2_StackMomento__) */

