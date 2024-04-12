#include "../Header/GameManager.hpp"

GameManager::GameManager(ParserMisc PM)
{ 
    this->winningMoney = PM.getWinningMoney();
    this->winningWeight = PM.getWinningWeight();
    this->storageSize = PM.getStorageSize();
    this->farmSize = PM.getFarmSize();
    this->fieldSize = PM.getFieldSize();
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
