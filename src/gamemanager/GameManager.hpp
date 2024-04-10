#include <bits/stdc++.h>
#include "../parsers/ParserHewan.hpp"
#include "../parsers/ParserMisc.hpp"
#include "../parsers/ParserTanaman.hpp"
#include "../parsers/ParserProduk.hpp"
#include "../parsers/ParserResep.hpp"
using namespace std;

class GameManager{
    private:
        vector< tuple<string,string,string,int,int> > AnimalConfig;
        vector< tuple<string,string,string,int,int> > PlantConfig;
        vector< tuple<string,string,string,string,int,int> > ProductConfig;
        vector< tuple<string,string,int,vector<pair<string,int> > > > RecipeConfig;
        int winningMoney;
        int winningWeight;
        pair<int,int> storageSize;
        pair<int,int> fieldSize;
        pair<int,int> farmSize;
        map<string, vector<string> > productOriginConversion; //konversi tanaman/hewan menjadi produk
        //queue<Pemain> TurnQueue;
        //vector<Pemain> playerList;
        //Pemain Winner;
        //
        //TODO:
        //1. QUEUE PEMAIN (giliran)
        //2. VOID NEXT
        //3. VOID UNTUK MENENTUKAN PEMENANG
        //4. LIST PEMAIN
    public:
        GameManager(ParserHewan,ParserTanaman,ParserProduk,ParserResep,ParserMisc);
        ~GameManager(){}
        void Debug();
        //void Next();
        //bool isThereAWinner();
        //Pemain getWinner();
        //string getCurrentPlayerName();
        //Pemain getCurrentPlayer();
        //string getWinnerName();
};