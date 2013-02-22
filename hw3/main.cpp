#include <iostream>
#include "String.h"

using namespace std;

int main(int argc, char** argv[])
{
	String s("dum");
	String s2("my");
	if(s == s2)
		cout<< endl << "true";
	getchar();
	return 0;
}