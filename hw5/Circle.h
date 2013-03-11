

#ifndef CIRCLE_H
#define CIRCLE_H
#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{

protected:
	double radius;

public:
	Circle (void) {}
	Circle ( double r, string c ) : Shape ( c ), radius ( r ) {}
	double circumference()
	{
		return 2.0 * M_PI * radius;
	}

	double area()
	{
		return M_PI * radius * radius;
	}

	double diameter()
	{
		return radius * 2;
	}

	
};

#endif 
