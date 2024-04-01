#include <bits/stdc++.h>
#include "../singleton/Singleton.hpp"
using namespace std;
//Parent class untuk semua parser
class BaseParser : public Singleton{
    public:
        BaseParser(){

        }
        ~BaseParser(){

        }
        virtual void ParseFile(string fileDirectory) = 0;
        virtual void PrintValues() = 0;
};