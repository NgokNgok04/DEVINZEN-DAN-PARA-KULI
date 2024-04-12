#ifndef PARSERMISC_HPP
#define PARSERMISC_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi misc.
class ParserMisc : public BaseParser{
    private:
        static int winningMoney;
        static int winningWeight;
        static pair<int,int> storageSize;
        static pair<int,int> fieldSize;
        static pair<int,int> farmSize;

    public:
        ParserMisc(){}
        ~ParserMisc(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        static int getWinningMoney();
        static int getWinningWeight();
        static pair<int,int> getStorageSize();
        static pair<int,int> getFieldSize();
        static pair<int,int> getFarmSize();
        friend ostream &operator<<(ostream &os, ParserMisc &PM); //untuk debugging, pake aja
};
#endif