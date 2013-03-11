
#include <vector>
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"


int main( int argc, char** argv)
{
	Circle circle ( 4.0, "Blue" );
	Triangle triangle ( 8.0, 2.0, "Red" );
	Square square ( 2.0, "Green" ); 
	vector<Shape*> s;

	s.push_back(new Circle( 4.0, "Blue" ));
	s.push_back(new Triangle( 8.0, 2.0, "Red" ));
	s.push_back(new Square( 2.0, "Green" ));
	
	/* loop through each shape and call print() */
	for ( vector<Shape*>::iterator it = s.begin(); it != s.end(); ++it ) 
	{
		Shape &shape = **it;
		shape.print();
	

	}

	getchar();
	return 0;
}
