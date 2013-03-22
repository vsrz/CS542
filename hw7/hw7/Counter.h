
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Counter
{
private:

    map<string, int> wordlist;

public:
    
    /* Finds the word and returns the number of 
        occurances in the map */
    int getWordCount( string word )
    {
        map<string, int>::iterator it = wordlist.find( word );
        if( it == wordlist.end() ) return 0;
        return it->second;
    }    

    int eraseElement( string word )
    {
        wordlist.erase(word);

    }

    /* Takes a list of words separated by newlines 
        and inserts them into the wordlist */
    void insertWordList( string l )
    {
        stringstream ss(l);
        
        while ( ss != NULL )
        {
            string token;
            ss >> token;

            int count = getWordCount( token );
            
            /* remove the old element if it exists */
            if( count > 0 )
                wordlist.erase(token);

            wordlist.insert( make_pair( token, count + 1 ) );

        };

    }

    /* print the entire contents of the wordlist */
    void printWordList()
    {
        for( map<string,int>::iterator p = wordlist.begin(); p != wordlist.end(); ++p )
            cout << p->first << " | " << p->second << endl;

    }


  
};