//
//  LinkedStackException.h
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw2_LinkedStackException_h
#define hw2_LinkedStackException_h

class LinkedStackException
{
    char * message;
public:
    LinkedStackException(char *msg)
    : message(msg)
    {
    }
    inline friend ostream & operator << (ostream & out, LinkedStackException & e)
    {
        return out << "LinkedStackException: " << e.message;
    }
};

#endif

