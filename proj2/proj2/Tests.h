
#ifndef TESTS_H
#define TESTS_H

#pragma once

#include <iostream>
#include <cassert>

#include "Domino.h"

class Tests
{

private:
    void beginTest( std::string name );
    void endTest( std::string name );
    int number;

public:
    Tests(void);
    ~Tests(void);

    void DominoCreation( void );
    void DominoPipTests( void );
    void DominoComparison( void );
    
};

#endif
