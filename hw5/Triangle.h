
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
private:
	double height;
	double width;

public:
	Triangle() {}
	Triangle ( double h, double w, string c ) : Shape ( c ), height( h ), width ( w ) {}
	
	double area() {
		return width * height / 2;
	}


};


#endif
