
#ifndef DOMINOCOLLECTIONTESTS_H
#define DOMINOCOLLECTIONTESTS_H

#pragma once

#include "Tests.h"

class DominoCollectionTests : protected Tests
{

public:
	DominoCollectionTests( void ) : Tests() {} 
	void RunAllTests( void );

	void DominoCollectionDrawRandomDominoes( void );
    void DominoCollectionAddDominoes( void );

};
    
#endif
