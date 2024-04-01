#include <bits/stdc++.h>

using namespace std;
//Parent class untuk semua parser
class BaseParser{
    public:
        BaseParser(){

        }
        ~BaseParser(){
            
        }
        virtual void ParseFile() = 0;
        virtual void PrintValues() = 0;
};