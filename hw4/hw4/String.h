
#ifndef STRING_H
#define STRING_H

#pragma once

#include <iostream>
#include <assert.h>

// Prints functions calls and copy creations
// #define DEBUG

using namespace std;

namespace lstring {

class String
{
public:
	/// Both constructors should construct
	/// from the parameter s
	String( const char * );	
	String( const String & );
	String operator = ( const String& );
	char & operator [] ( const int );
	int length() const;
	int indexOf( char ) const;
	bool operator == ( const String& ) const;
	/// concatenates this and s
	String operator + ( const String& ) const;
	/// concatenates s onto end of this
	String operator += ( const String& );
	void print( ostream & );
	void read( istream & );
	~String();
private:
	bool inBounds( int i )
	{
		return i >= 0 && i < length();
	}
	struct ListNode
	{
		char info;
		ListNode * next;
		ListNode( char newInfo, ListNode * newNext )	: info( newInfo ), next( newNext ) {}
	};
	
	ListNode * head; // no other data members!!
	void append ( ListNode *, char ) const;	
	static ListNode *create ( const char * );
	static ListNode *copy ( const ListNode * );
	static void flush( ListNode *p );
 };

ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );

}

#endif

