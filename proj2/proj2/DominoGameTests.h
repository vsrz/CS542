
#ifndef DOMINOGAMETESTS_H
#define DOMINOGAMETESTS_H
#pragma once

#include "Tests.h"
#include "DominoGame.h"
class DominoGameTests : public Tests
{
public:
    DominoGameTests(void) { name = "DominoGameTests"; }
    ~DominoGameTests(void) {};

    void RunAllTests( void );

};

#endif
