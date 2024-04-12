#pragma once
#include <bits/stdc++.h>
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