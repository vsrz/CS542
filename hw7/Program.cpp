
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include "fileutils.h"
#include "Counter.h"
#include "Sorter.h"

using namespace std;
using namespace fileutils;



int main( int argc, char** argv )
{
    
    string fileText;
    string excludeText;
    Counter c;
    
    cout << "Word map test with input files.\n";
    /* read the file */
    readFile(fileText, "input.txt");  
    readFile(excludeText, "exclude.txt");

    /* build exclusion list */
    c.loadExclusionList(excludeText);
    c.insertWordList(fileText);
    c.printWordList();

    cout << "\nPress enter for next...";
    getchar();

    Sorter s;
    fileText = "";
    readFile(fileText, "nums.txt");
    s.loadNumList(fileText);
    s.printNumList();
    s.writeFiles();

    cout << "\nPress enter to quit...";
    getchar();

    return 0;
}

