#include "Tests.h"


Tests::Tests(void)
{
    number = 0;
    DominoCreation();
    DominoPipTests();
    DominoComparison();
}


Tests::~Tests(void)
{
}

void Tests::DominoPipTests( void )
{
    std::string name("Domino Creation");
    Domino d( 5, 5 );
    beginTest( name );
    
    std::cout << "High PIP on a 5 | 5 == 5";
    assert( d.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 5 | 5 == 5";
    assert( d.getLowPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "5 | 5 is a double";
    assert( d.isDouble() == true );
    std::cout << " Ok." << std::endl;

    std::cout << "High PIP on a 5 | 4 == 5";
    d.setPip( 5, 4 );
    assert( d.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 5 | 4 == 4";
    assert( d.getLowPip() == 4 );
    std::cout << " Ok." << std::endl;

    std::cout << "5 | 4 is not a double";
    assert( d.isDouble() == false );
    std::cout << " Ok." << std::endl;

    std::cout << "High PIP on a 4 | 5 == 5";
    assert( d.getHighPip() == 5 );
    std::cout << " Ok." << std::endl;

    std::cout << "Low PIP on a 4 | 5 == 4";
    assert( d.getLowPip() == 4 );
    std::cout << " Ok." << std::endl;

    std::cout << "4 | 5 is not a double";
    assert( d.isDouble() == false );
    std::cout << " Ok." << std::endl;

    
    endTest( name );

}

void Tests::DominoCreation( void )
{
    std::string name("Domino Creation");
    Domino d( 5, 5 );
    beginTest( name );

    std::cout << "Creating Domino, 5 | 5 " << std::endl;
    std::cout << d << std::endl;

    endTest( name );

}

void Tests::DominoComparison( void )
{
    std::string name("DominoComparison");
    int suit = 5;
    Domino ours( 5, 5 ), theirs( 5, 4 );

    beginTest( name );

    std::cout << "Suit is Fives" << std::endl;

    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;
    
    ours.setPip( 5, 5 );
    theirs.setPip( 5, 6 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 4, 5 );
    theirs.setPip( 5, 6 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 4 );
    theirs.setPip( 5, 5 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 6, 5 );
    theirs.setPip( 5, 5 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 6 );
    theirs.setPip( 5, 4 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 0, 6 );
    theirs.setPip( 0, 4 );
    std::cout << ours << " < " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    ours.setPip( 5, 5 );
    theirs.setPip( 0, 0 );
    std::cout << ours << " > " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == true );
    assert( ours.isSmallerThan( theirs, suit ) == false );
    std::cout << " Ok." << std::endl;

    ours.setPip( 0, 6 );
    theirs.setPip( 5, 4 );
    std::cout << ours << " < " << theirs;
    assert( ours.isLargerThan( theirs, suit ) == false );
    assert( ours.isSmallerThan( theirs, suit ) == true );
    std::cout << " Ok." << std::endl;

    endTest( name );
}

void Tests::beginTest( std::string name )
{
    std::cout << "** Begin Test " << ++number << " : " << name << " **" << std::endl;
}

void Tests::endTest( std::string name )
{
    std::cout << "** End Test " << name << " **" << std::endl;
    std::cout << "Press enter to continue...";
    getchar();
    std::cout << std::endl;
}


