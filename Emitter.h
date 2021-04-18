#ifndef __EMITTER__
#define __EMITTER__

#include <iostream>

using namespace std;

class Emitter
{
private:
    string path;
    string header;
    string code;
public:
    Emitter(string _path);

    void emit(string _code);
    void emitLine(string _code);
    void emitHeader(string _code);
    void writeFile();
};

#endif