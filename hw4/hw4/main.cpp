
#include <iostream>
#include "String.h"

using namespace std;
using namespace lstring;

int main(int argc, char** argv)
{
	
	// Linked list test
	String one("one");
	String two("two");
	cout << "Test constuctors (and operator <<): " << one << endl;
			

	//// Test operator =
	one = two;
	cout << "Operator = (\"one\" = \"two\") : " << one << endl;
	one = "one";
	
	// Operator index
	cout << "Operator [] one[1] : " << one[1] << " index: " << one.indexOf('n') << endl;

	// Length and index
	cout << "Length of one is : " << one.length() << endl;

	//// Test operator +
	cout << "Operator = (one + two) : " << one + two << endl;
	one += two;
	cout << "Operator += (one += two) : " << one << endl;

	//// Test operator ==
	cout << "Operator == (\"one\" == \"one\") : " << (one == one) << endl;
	cout << "Operator == (\"one\" == \"two\") : " << (one == two) << endl;

	// Test read
	cout << "Input: ";
	cin >> one;
	cout << "You entered: " << one;
	cin.ignore();

	// The following code produces 4 copy creations and 97 function calls
	// This is because some of the code is writetn recursively
	// String s("Hello");
	// String t("There");
	// s = s + t;

	// The following code produces 3 copies and 40 function calls	
	// String s("Hello");
	// String t("There");
	// s += t;

	//cin.get();
	return 0;
}
