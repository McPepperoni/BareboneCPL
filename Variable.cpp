#include "Variable.h"

#include <iostream>

using namespace std;

Variable::Variable()
{
    name = "";
    value = 0;
}

Variable::Variable(string _name)
{
    name = _name;
    value = 0;
}

string Variable::getName()
{
    return name;
}

void Variable::setValue(ull _value)
{
    value = _value;
}

void Variable::incr()
{
    value++;
}

void Variable::decr()
{
    value--;
}

void Variable::printVar()
{
    cout << value;
}