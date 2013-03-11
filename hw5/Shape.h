#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape
{
protected:
	string color;

public:
	int weight;
	Shape( string c ) : color ( c) {}
	
	void print() 
	{
		cout << "This shape is " << color << endl;
	}
	virtual double area() = 0;
	Shape(void) {};
	virtual ~Shape(void) {};

};

#endif

