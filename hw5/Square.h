
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Square : public Shape
{
private:
	double length;

public:
	Square () {}
	Square ( double l, string c ) : Shape ( c ), length ( l ) {}
	
	double area()
	{
		return length * 2;

	}

	double perimeter()
	{
		return length * 4;
	}

};


#endif