/**
 *  Jeremy Villegas
 *	CS542 HW1
 *  02/05/2013
 *
 */

#include<iostream>
#include"Stack.h"
using namespace std;

int main( int argc, char *argv[] )
{
	cout << "Hello World!\n";
	Stack s;	
	char t = ' ';
	
	/* Read user input */
	while(!cin.eof()){
		cout<<"Char, Enter when done: ";	
		cin.get(t);		
		if(t==EOF)t='\0';
		cin.ignore();
		s.push(t);
	} 
	t = ' ';
	cin.ignore();

	/* Print the stack */
	cout<<"\nResult: ";
	while(!s.isEmpty()) {
		cout<<s.top();
		s.pop();
	}
	cout<<"\n\nPress enter to quit";
	getchar();
	return(0);
}
