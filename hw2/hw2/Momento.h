//
//  Momento.h
//  hw2
//
//  Created by vsrz on 2/14/13.
//  Copyright (c) 2013 vsrz. All rights reserved.
//

#ifndef hw2_Momento_h
#define hw2_Momento_h

#include <iostream.h>
class StackException
{
    char * message;
public:
    StackException(char *msg)
    : message(msg)
    {
    }
    inline friend ostream & operator << (ostream & out, StackException & e)
    {
        return out << "StackException: " << e.message;
    }
};
#define STACK_SIZE 1024
class StackMemento
{
    friend class ArrayStack;
    int top;
    char buf[STACK_SIZE];
    StackMemento(char * curBuf, int curTop)
    {
        top = curTop;
        for ( int i = 0; i < curTop; ++i )
            buf[i] = curBuf[i];
    }
    void restore( char * curBuf, int & curTop )
    {
        curTop = top;
        for ( int i = 0; i < top; ++i )
            curBuf[i] = buf[i];
    }
};
class StackIter;
class ArrayStack
{
    friend class StackIter;
    // static const int STACK_SIZE = 1024;
    char buf[STACK_SIZE];
    int top;
public:
    ArrayStack()
    : top(0)
    {
    }
    void push(char c)
    throw (StackException)
    {
        if ( isFull() )
            throw StackException("Full");
            buf[top++] = c;
    }
    char pop()
    throw (StackException)
    {
        if ( isEmpty() )
            throw StackException("Empty");
            return buf[--top];
    }
    bool isEmpty()
    {
        return top <= 0;
    }
    bool isFull()
    {
        return top >= STACK_SIZE;
    }
    StackMemento * createMemento()
    {
        return new StackMemento(buf, top);
    }
    void restoreState( StackMemento * m )
    {
        m->restore(buf, top);
    }
    StackIter * createIter();
};
class StackIter
{
    ArrayStack * stk;
    int index;
public:
    StackIter( ArrayStack * s )
    {
        stk = s;
        reset();
    }
    void reset()
    {
        index = 0;
    }
    void advance()
    {
        ++index;
    }
    bool hasMore()
    {
        return index < stk->top;
    }
    char current()
    {
        return stk->buf[index];
    }
};
StackIter * ArrayStack::createIter()
{
    return new StackIter( this );
}
ostream & operator << (ostream & out, ArrayStack & stk)
{
    for ( StackIter & i = *stk.createIter(); i.hasMore(); i.advance() )
        out << i.current();
        return out;
}
int main()
{
    ArrayStack & stk = *new ArrayStack();
    try
    {
        for ( char c = 'A'; c <= 'Z'; ++c )
            stk.push(c);
        cout << "Stack: " << stk << endl;
        StackMemento * m = stk.createMemento();
        cout << "Stack: " << stk << endl;
        cout << "Stack: ";
        while ( !stk.isEmpty() )
            cout << stk.pop();
        cout << endl;
        cout << "Stack: " << stk << endl;
        stk.restoreState( m );
        cout << "Stack: " << stk << endl;
    }
    catch (StackException & e)
    {
        cout << e << endl;
    }
}

#endif
