#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <bits/stdc++.h>
#include "../parsers/ParserHewan.hpp"
#include "../parsers/ParserMisc.hpp"
#include "../parsers/ParserTanaman.hpp"
#include "../parsers/ParserProduk.hpp"
#include "../parsers/ParserResep.hpp"
using namespace std;

class GameManager{
    private:

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
        GameManager(ParserMisc);
        ~GameManager(){}
        void Debug();
        //void Next();
        //bool isThereAWinner();
        //Pemain getWinner();
        //string getCurrentPlayerName();
        //Pemain getCurrentPlayer();
        //string getWinnerName();
};
#endif