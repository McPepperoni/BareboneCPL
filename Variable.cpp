#include "Variable.h"

#include <iostream>

using namespace std;

Variable::Variable()
{
    name = "";
}

Variable::Variable(string _name)
{
    name = _name;
}

string Variable::getName()
{
    return name;
}