
#include <iostream>
#include <sstream>
#include <algorithm>
#include "fileutils.h"

using namespace std;


class Sorter
{

private:
	vector<int> nums;	// List of numbers
	bool isSorted;		// Sorting status, so we don't sort unneccessarily

public:

	Sorter()
	{
		isSorted = false;
	}

	/* Load a number into the array */
	void loadNum( int n )
	{
		nums.push_back(n);
		isSorted = false;
	}

	/* Load a list containing integers */
	void loadNumList( string l )
	{
		stringstream ss(l);

		while ( ss != NULL )
		{
			string line;
			getline(ss, line);
			if(line.length() == 0) continue;
			istringstream iss(line);
			int n;
			iss >> n;
			loadNum( n );
		}

	}

	/* Sort the numbers */
	void sortList()
	{
		if( !isSorted )
			sort(nums.begin(), nums.end());
		isSorted = true;
	}

	/* write files */
	void writeFiles()
	{
		string odds(""), evens("");
		sortList();
		for( vector<int>::iterator it = nums.begin(); it != nums.end(); ++it )
		{
			stringstream ss;

			if( *it % 2 == 0 )
			{
				ss << *it;
				evens = evens + ss.str() + " ";	
			}
			else
			{
				ss << *it;
				odds = odds + ss.str() + " ";
			}
				
		}

		fileutils::writeFileToDisk(evens,"evens.txt");
		fileutils::writeFileToDisk(odds,"odds.txt");

	}


	/* print list of integers */
	void printNumList()
	{
		sortList();
		cout << "Number list" << endl;
		for( vector<int>::iterator it = nums.begin(); it != nums.end(); ++it )
		{
			cout << *it << endl;
		}
	}

};
