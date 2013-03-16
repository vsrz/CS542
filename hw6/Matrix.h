//
//  Matrix.h
//  hw6
//
//  Created by vsrz on 3/16/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw6_Matrix_h
#define hw6_Matrix_h

#include <iostream>
#include <iomanip>
#include "Array.h"

using namespace std;

template < class Element > class Matrix
{
private:
    int rows, cols;
    Array<Array<Element>*> m;
    
    // define m as an Array of Array pointers using the template
    // you defined above
public:
    Matrix( int newRows, int newCols )
    : rows( newRows ), cols( newCols ), m( rows )
    {
        for (int i = 0; i < rows; i++ )
            m[i] = new Array < Element >( cols );
    }
    int numRows()
    {
        return rows;
    }
    int numCols()
    {
        return cols;
    }
    Array < Element > & operator [] ( int row )
    {
        return * m[row];
    }
    void print( ostream & out )
    {
        // You can write this one too, but use the Array::operator<<
        for( int i = 0; i < rows; ++i)
            out << m[i] << endl;
    }
    friend ostream & operator << ( ostream & out, Matrix & m )
    {
        m.print( out );
        return out;
    }
};

#endif
