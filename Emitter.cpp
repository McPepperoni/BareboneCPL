#include <fstream>

#include "Emitter.h"

using namespace std;

Emitter::Emitter(string _path)
{
    path = _path;
    header = "";
    code = "";
}

void Emitter::emit(string _code)
{
    code += _code;
}

void Emitter::emitLine(string _code)
{
    code += _code + '\n';
}

void Emitter::emitHeader(string _code)
{
    header += _code + '\n';
}

void Emitter::writeFile()
{
    ofstream myFile;

    myFile.open(path);
    myFile << header + code;
}