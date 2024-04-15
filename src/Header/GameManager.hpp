#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP
#include <bits/stdc++.h>
#include "ParserHewan.hpp"
#include "ParserMisc.hpp"
#include "ParserTanaman.hpp"
#include "ParserProduk.hpp"
#include "ParserResep.hpp"
#include "petani.hpp"
#include "peternak.hpp"
#include "walikota.hpp"
using namespace std;

class GameManager{
    private:

        int winningMoney;
        int winningWeight;
        pair<int,int> storageSize;
        pair<int,int> fieldSize;
        pair<int,int> farmSize;
        map<string, vector<string> > productOriginConversion; //konversi tanaman/hewan menjadi produk        
        vector<Pemain*> playerList;
        int currentPlayerIndex;
        int playerAmount;
        Pemain* Winner;
        void rotatePlayer();
        //TODO:
        //1. ROTASI PEMAIN (done)
        //2. VOID NEXT
        //3. VOID UNTUK MENENTUKAN PEMENANG
        //4. LIST PEMAIN
    public:
        GameManager(ParserMisc);
        ~GameManager(){}
        void Debug();
        void insertNewPlayer(Pemain*);
        void PlayerDebug();
        void Next();
        //bool isThereAWinner();
        //Pemain* getWinner();
        Pemain* getCurrentPlayer();
        string getCurrentPlayerName();
        
        //string getWinnerName();
};
#endif