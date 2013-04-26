
#ifndef TEXAS42SETTESTS_H
#define TEXAS42SETTESTS_H

#pragma once
#include "Tests.h"
#include "Texas42Set.h"

class Texas42SetTests : public Tests
{
public:
    Texas42SetTests(void) { name = "Texas 42 Set Tests"; }  
    ~Texas42SetTests(void) {} 

    void RunAllTests( void );
    void PlayTrick( void );

};

#endif
