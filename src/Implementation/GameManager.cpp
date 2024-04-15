#include "../Header/GameManager.hpp"
#include "GameManager.hpp"




void GameManager::rotatePlayer()
{
    if(this->currentPlayerIndex == this->playerAmount-1){ //kembali ke awal jika sudah di ujung akhir
        this->currentPlayerIndex = 0;
    } else {
        this->currentPlayerIndex++;
    }
}

GameManager::GameManager(ParserMisc PM)
{ 
    this->winningMoney = PM.getWinningMoney();
    this->winningWeight = PM.getWinningWeight();
    this->storageSize = PM.getStorageSize();
    this->farmSize = PM.getFarmSize();
    this->fieldSize = PM.getFieldSize();
    this->playerAmount = 0;
    this->Winner = nullptr;
    this->currentPlayerIndex = 0;
    cout<<"Data konfigurasi misc berhasil dimuat!\n";
}

void GameManager::Debug()
{
    cout<<this->winningMoney<<"\n";
    cout<<this->winningWeight<<"\n";
    cout<<this->storageSize.first<<" "<<this->storageSize.second<<"\n";
    cout<<this->farmSize.first<<" "<<this->farmSize.second<<"\n";
    cout<<this->fieldSize.first<<" "<<this->fieldSize.second<<"\n";
}

void GameManager::insertNewPlayer(Pemain * newPlayer)
{
    this->playerList.push_back(newPlayer);
    this->playerAmount++;

    if(this->playerAmount > 1){ //geser pemain yang baru dimasukkan supaya terurut otomatis
        Pemain* P1 = nullptr;
        Pemain* P2 = nullptr;
        int i = this->playerAmount-1;
        while(i-1>=0){
            P1 = this->playerList[i];
            P2 = this->playerList[i-1];

            if(*P1<*P2){
                this->playerList[i] = P2;
                this->playerList[i-1] = P1;
            } else {
                break;
            }
            i--;
        }
    }
}

void GameManager::PlayerDebug()
{
    for(int i = 0; i<this->playerList.size(); i++){
        cout<<this->playerList[i]->getUsername()<<"\n";
    }
}

void GameManager::Next()
{
    this->rotatePlayer();
    //TODO: aging semua tanaman
}

Pemain *GameManager::getWinner()
{
    return this->Winner;
}

string GameManager::getWinnerName()
{
    Pemain* winner = this->getWinner();
    return winner->getUsername();
}

//TODO: UNCOMMENT THIS METHOD BELOW AFTER MERGING
// bool GameManager::checkWinner()
// {

//     Pemain* currentPlayer = this->getCurrentPlayer();
//     if(currentPlayer->getWeight() >= this->winningWeight && currentPlayer->getGulden() >= this->winningMoney){
        //SYARAT MENANG: BERAT PEMAIN >= BERAT MINIMUM UNTUK MENANG DAN BANYAK GULDEN >= GULDEN UNTUK MENANG
//         this->Winner = currentPlayer;
//         return true;
//     }
//     return false;
// }

//TODO: UNCOMMENT THIS METHOD ABOVE AFTER MERGING


Pemain *GameManager::getCurrentPlayer()
{
    return this->playerList[this->currentPlayerIndex];
}

string GameManager::getCurrentPlayerName()
{
    Pemain* P = this->getCurrentPlayer();
    return P->getUsername();
}

void GameManager::clearPlayerList()
{
    for(auto it = this->playerList.begin(); it != this->playerList.end(); it++){
        delete *it;
    }
    this->playerList.clear();
}

vector<Pemain *> GameManager::getPlayerList()
{
    return this->playerList;
}
