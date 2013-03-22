
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include "fileutils.h"
#include "Counter.h"

using namespace std;
using namespace fileutils;



int main( int argc, char** argv )
{
    
    string fileText;
    Counter c;
    
    /* read the file */
    readFile(fileText, "input.txt");    
    c.insertWordList(fileText);
    c.printWordList();

    getchar();
    return 0;
}