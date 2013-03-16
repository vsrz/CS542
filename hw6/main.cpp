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

int main(int argc, const char * argv[])
{
    Array<int> a(5);
    Matrix<int> m(5,5);
    
    for( int i = 0; i < a.length(); ++i )
        a[i] = i+1;
    cout << "Test array\n";
    cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl << endl;
    
    for( int r = 0; r < m.numRows(); ++r )
        for( int c = 0; c < m.numCols(); ++c )
        {
            m[r][c] = NULL;
            m[r][c] = c;
        }
    
/*    for ( int r = 0; m.numRows(); ++r )
        cout << m[r];
  */
    getchar();
    return 0;
}

