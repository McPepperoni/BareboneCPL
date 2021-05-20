#ifndef __VARIABLE__
#define __VARIABLE__

#include <iostream>

typedef unsigned long long ull;

using namespace std;

class Variable
{
private:
    string name;
public:
    Variable();
    Variable(string _name);

    string getName();
    
    void setValue(ull _value);
};


#endif