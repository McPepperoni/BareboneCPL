#ifndef __VARIABLE__
#define __VARIABLE__

#include <iostream>

typedef unsigned long long ull;

using namespace std;

class Variable
{
private:
    string name;
    ull value;
public:
    Variable();
    Variable(string _name);

    string getName();
    
    void setValue(ull _value);
    void incr();
    void decr();
    void printVar();
};


#endif