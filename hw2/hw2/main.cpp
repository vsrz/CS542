//
//  main.cpp
//  hw2
//
//  Created by Jeremy Villegas on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include <iostream>
#include "CharLinkedListPair.h"
#include "StackMomento.h"
#include "LinkedStack.h"
#include "LinkedStackException.h"
#include "LinkedStackIterator.h"
using namespace std;

int main()
{
	LinkedStack stk;
	
	// First, create a momento with empty data
	StackMomento* empty = stk.createMomento();
	cout<<"Momento Test"<<endl<<"Beginning stack: "<<stk;
	cout<<endl;
		
	// Load up the stack with dummy data
	try
    {
        for ( char c = 'A'; c <= 'Z'; ++c )
            stk.push(c);
		
	}
	catch(LinkedStackException &ex)
	{
		cout<<"Stack Exception "<<ex<<endl;
	}
		
	// Display the stack after it has been loaded
	cout<<"Loaded Stack: "<<stk;
	//stk.print(cout);
	cout<< endl;
	
	// Make a momento of the stack, then empty the old stack
	StackMomento* momento = stk.createMomento();
	stk.restore(empty);
	cout<<"Emptied stack: "<<stk;
	cout<<endl;
	
	// Now, restore the stack
	stk.restore(momento);
	cout<<"Restored stack: "<<stk;
	cout<<endl;
	
	
		
    
    return 0;
    
}
