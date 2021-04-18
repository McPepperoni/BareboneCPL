#include <fstream>

#include "Emitter.h"

using namespace std;

emitter::Emitter(string _path)
{
    path = _path;
    header = "";
    code = "";
}

void emitter::emit(string _code)
{
    code += _code;
}

void emitter::emitLine(string _code)
{
    code += _code + '\n';
}

void emitter::emitHeader(string _code)
{
    header += _code + '\n';
}

void emitter::writeFile()
{
    ofstream myFile;

    myFile.open(path);
    myFile << header + code;
}