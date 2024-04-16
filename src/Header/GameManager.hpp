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
#include "Bangunan.hpp"
#include "Toko.hpp"
using namespace std;

class GameManager{
    private:

        int winningMoney;
        int winningWeight;
        pair<int,int> storageSize;
        pair<int,int> fieldSize;
        pair<int,int> farmSize;
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
        void insertNewPlayer(Pemain*);//masukkan pemain baru
        void PlayerDebug();
        void Next();
        void setupGame();
        void prosesInput(string);
        bool checkWinner(); //TODO:UNCOMMENT THIS METHOD AFTER MERGING
        Pemain* getWinner(); //dapatkan pemenang
        string getWinnerName(); //dapatkan nama pemenang
        Pemain* getCurrentPlayer(); //dapatkan pemain yang bermain sekarang
        string getCurrentPlayerName(); //dapatkan nama pemain yang bermain sekarang
        void clearPlayerList(); //membebaskan semua pointer pemain di playerlist
        vector<Pemain *> getPlayerList(); //mendapatkan list pemain
        void simpan();
        void muat();
};
#endif