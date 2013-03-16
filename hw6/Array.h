//
//  Array.h
//  hw6
//
//  Created by vsrz on 3/16/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw6_Array_h
#define hw6_Array_h

#include <iostream>
#include <assert.h>
#include <iomanip>
using namespace std;

template <class T> class Array
{
private:
    int len;
    T * buf;
public:
    Array( int newLen )
    : len( newLen ), buf( new T [newLen] )
    {
    }
    Array( Array & l )
    : len( l.len ), buf( new T [l.len] )
    {
        for ( int i = 0; i < l.len; i++ )
            buf[i] = l.buf[i];
    }
    int length()
    {
        return len;
    }
    T & operator [] ( int i )
    {
        assert( 0 <= i && i < len );
        return buf[i];
    }
    void print( ostream & out )
    {
        for (int i = 0; i < len; i++)
            out << setw(5) << buf[i];
    }
    friend ostream & operator << ( ostream & out, Array & a )
    {
        a.print( out );
        return out;
    }
    friend ostream & operator << ( ostream & out, Array * ap )
    {
        ap->print( out );
        return out;
    }
    // note the overloading of operator << on a pointer as well
};

#endif
