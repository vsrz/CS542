//
//  main.cpp
//  hw6
//
//  Created by vsrz on 3/16/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#include <iostream>
#include "Array.h"
#include "Matrix.h"

using namespace std;

int altmain(int argc, const char * argv[])
{
    Array<int> a(5);
    Matrix<double> d(5,5);
    Matrix<char> ch(5,5);
    
    for( int i = 0; i < a.length(); ++i )
        a[i] = i+1;
    
	// Array test
    cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl << endl;
	
	// Matrix of Doubles
    for( int r = 0; r < d.numRows(); ++r )
        for( int c = 0; c < d.numCols(); ++c )
        {
			d[r][c] = a[c];
        }

	cout << d << endl;

	// Matrix of Chars
	for ( int r = 0; r < ch.numRows(); ++r )
		for ( int c = 0; c < ch.numCols(); ++c )
			ch[r][c] = r * 5 + c + 65;
		
	cout << ch << endl;
	getchar();
    return 0;
}

