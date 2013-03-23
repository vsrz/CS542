
#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Counter
{
private:

    map<string, int> wordlist;
    vector<string> exclusionList;

public:
    
    /* Finds the word and returns the number of 
        occurances in the map */
    int getWordCount( string word )
    {
        map<string, int>::iterator it = wordlist.find( word );
        if( it == wordlist.end() ) return 0;
        return it->second;
    }    

    void eraseElement( string word )
    {
        wordlist.erase(word);

    }

    /* returns true if the word is allowed in the wordlist */
    bool isAllowed( string word )
    {
        return find(exclusionList.begin(), exclusionList.end(), word) ==  exclusionList.end();
    }

    /* excludes a specific word from being allowed into the list */
    void loadExclusionWord( string word )
    {
        exclusionList.push_back(word);

    }

    /* allows for a user provided exclusion set */
    void loadExclusionList( string list )
    {
        stringstream ss(list);

        while ( ss != NULL )
        {
            string token;
            ss >> token;

            loadExclusionWord( token );

        }
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

            /* do not insert a blank string */
            if( token.length() == 0) continue;

            int count = getWordCount( token );
            
            /* remove the old element if it exists */
            if( count > 0 )
                wordlist.erase(token);

            if( isAllowed( token ) )
                wordlist.insert( make_pair( token, count + 1 ) );

        };

    }

    void printExclusionList()
    {
        cout << "Excluded Words:" << endl;
        for ( vector<string>::iterator it = exclusionList.begin(); it != exclusionList.end(); ++it)
        {
            cout << *it << endl;
        }   

    }

    /* print the entire contents of the wordlist */
    void printWordList()
    {
        for( map<string,int>::iterator p = wordlist.begin(); p != wordlist.end(); ++p )
            cout << p->first << " | " << p->second << endl;

    }


  
};

#endif
