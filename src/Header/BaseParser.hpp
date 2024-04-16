#ifndef BASEPARSER_HPP
#define BASEPARSER_HPP
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "Exception.hpp"
using namespace std;
// Parent class untuk semua parser
class BaseParser
{
public:
    BaseParser() {}
    ~BaseParser() {}
    virtual void ParseFile(string fileDirectory) = 0;
    virtual void ClearParserData() = 0;
    // virtual void PrintValues() = 0;
};
#endif