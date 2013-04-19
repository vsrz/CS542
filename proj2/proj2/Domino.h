
#ifndef DOMINO_H
#define DOMINO_H

#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class Domino {

private:
    int left;
	int right;    

    int getOppositePip( int pip );
public:
    Domino::Domino( int l, int r );
    ~Domino();

    void setPip( int left, int right );
    void setLeftPip( int left );
    void setRightPip( int right );
	int getHighPip();
	int getLowPip();
	bool isDouble();
	bool isSuit( int suit );
    
    bool isSmallerThan( Domino d, int suit );
    bool isLargerThan ( Domino d, int suit );
    bool operator == ( const Domino d );
    void print( std::ostream & out );
};

std::ostream & operator << ( std::ostream & out, Domino & d );

#endif
