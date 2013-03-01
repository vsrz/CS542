#include <iostream>
#include "String.h"

using namespace std;
using namespace zstring;

int main(int argc, char** argv)
{

	// Test constuctor (and operator <<)
	String one("one");
	cout << "Test constructor char* \"one\" : " << one << endl;

	//// Test constructor, String based
	//String two(String("two"));
	//cout << "Test constructor using String \"two\" : " << two << endl;

	//// Test operator =
	//one = two;
	//cout << "Operator = (\"one\" = \"two\") : " << one << endl;
	//one = "one";

	//// Test operator +
	//cout << "Operator = (one + two) : " << one + two << endl;

	//// Test operator ==
	//cout << "Operator == (\"one\" == \"one\") : " << (one == one) << endl;
	//cout << "Operator == (\"one\" == \"two\") : " << (one == two) << endl;

	//// Test operator !=
	//cout << "Operator != (\"one\" != \"two\") : " << (one != two) << endl;
	//cout << "Operator != (\"one\" != \"one\") : " << (one != one) << endl;

	//// Test operator >
	//cout << "Operator > (\"one\" > \"two\") : " << (one > two) << endl;
	//cout << "Operator > (\"two\" > \"one\") : " << (two > one) << endl;

	//// Test operator <
	//cout << "Operator < (\"one\" < \"two\") : " << (one < two) << endl;
	//cout << "Operator < (\"two\" < \"one\") : " << (two < one) << endl;

	//// Test operator >=
	//cout << "Operator <= (\"one\" <= \"two\") : " << (one >= two) << endl;
	//cout << "Operator <= (\"two\" <= \"one\") : " << (two >= one) << endl;
	//cout << "Operator <= (\"one\" <= \"one\") : " << (one >= one) << endl;

	//// Test operator <=
	//cout << "Operator <= (\"one\" <= \"two\") : " << (one <= two) << endl;
	//cout << "Operator <= (\"two\" <= \"one\") : " << (two <= one) << endl;
	//cout << "Operator <= (\"one\" <= \"one\") : " << (one <= one) << endl;


	cin.get();
	return 0;
}
