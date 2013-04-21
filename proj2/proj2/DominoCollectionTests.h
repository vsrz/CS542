
#ifndef DOMINOCOLLECTIONTESTS_H
#define DOMINOCOLLECTIONTESTS_H

#pragma once

#include "Tests.h"
#include "DominoCollection.h"

class DominoCollectionTests : protected Tests
{

public:
	DominoCollectionTests( void ) : Tests() { number = 0; } 
	void RunAllTests( void );
    void DominoCollectionAddDominoes( void );

};
    
#endif
