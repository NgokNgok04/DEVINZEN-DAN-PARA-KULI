#include "GameManager.hpp"

GameManager::GameManager(ParserHewan PH, ParserTanaman PT, ParserProduk PP, ParserResep PR, ParserMisc PM)
{
    for(int i = 0; i<PH.getConfigSize(); i++){
        tuple<string,string,string,int,int> newTuple(PH.getCode(i),PH.getName(i),PH.getType(i),PH.getHarvestWeight(i),PH.getPrice(i));
        this->AnimalConfig.push_back(newTuple);
    }
    cout<<"Data konfigurasi hewan berhasil dimuat!\n";
    for(int i = 0; i<PT.getConfigSize(); i++){
        tuple<string,string,string,int,int> newTuple(PT.getCode(i),PT.getName(i),PT.getType(i),PT.getHarvestDuration(i),PT.getPrice(i));
        this->PlantConfig.push_back(newTuple);
    }
    cout<<"Data konfigurasi tanaman berhasil dimuat!\n";
    for(int i = 0; i<PP.getConfigSize(); i++){
        tuple<string,string,string,string,int,int> newTuple(PP.getCode(i),PP.getName(i),PP.getType(i),PP.getOrigin(i),PP.getAddedWeight(i),PP.getPrice(i));
        this->ProductConfig.push_back(newTuple);
    }
    cout<<"Data konfigurasi produk berhasil dimuat!\n";
    for(int i = 0; i<PR.getConfigSize(); i++){
        tuple<string,string,int,vector<pair<string,int> > >  newTuple(PR.getCode(i),PR.getName(i),PR.getPrice(i),PR.getRecipeMaterialQuantity(i));
        this->RecipeConfig.push_back(newTuple);
    }
    cout<<"Data konfigurasi resep berhasil dimuat!\n";    
    this->winningMoney = PM.getWinningMoney();
    this->winningWeight = PM.getWinningWeight();
    this->storageSize = PM.getStorageSize();
    this->farmSize = PM.getFarmSize();
    this->fieldSize = PM.getFieldSize();
    cout<<"Data konfigurasi misc berhasil dimuat!\n";
}

void GameManager::Debug()
{
    for(int i = 0; i<this->AnimalConfig.size(); i++){ //output semua data animal config
        cout<<get<0>(this->AnimalConfig[i])<<" ";
        cout<<get<1>(this->AnimalConfig[i])<<" ";
        cout<<get<2>(this->AnimalConfig[i])<<" ";
        cout<<get<3>(this->AnimalConfig[i])<<" ";
        cout<<get<4>(this->AnimalConfig[i])<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0; i<this->PlantConfig.size(); i++){ //output semua data animal config
        cout<<get<0>(this->PlantConfig[i])<<" ";
        cout<<get<1>(this->PlantConfig[i])<<" ";
        cout<<get<2>(this->PlantConfig[i])<<" ";
        cout<<get<3>(this->PlantConfig[i])<<" ";
        cout<<get<4>(this->PlantConfig[i])<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0; i<this->ProductConfig.size(); i++){ //output semua data animal config
        cout<<get<0>(this->ProductConfig[i])<<" ";
        cout<<get<1>(this->ProductConfig[i])<<" ";
        cout<<get<2>(this->ProductConfig[i])<<" ";
        cout<<get<3>(this->ProductConfig[i])<<" ";
        cout<<get<4>(this->ProductConfig[i])<<" ";
        cout<<get<5>(this->ProductConfig[i])<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0; i<this->RecipeConfig.size(); i++){ //output semua data animal config
        cout<<get<0>(this->RecipeConfig[i])<<" ";
        cout<<get<1>(this->RecipeConfig[i])<<" ";
        cout<<get<2>(this->RecipeConfig[i])<<" ";
        vector< pair<string,int> > pairVector = get<3>(this->RecipeConfig[i]);
        for(int j = 0; j< pairVector.size(); j++){
            cout<<pairVector[j].first<<" "<<pairVector[j].second<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<this->winningMoney<<"\n";
    cout<<this->winningWeight<<"\n";
    cout<<this->storageSize.first<<" "<<this->storageSize.second<<"\n";
    cout<<this->farmSize.first<<" "<<this->farmSize.second<<"\n";
    cout<<this->fieldSize.first<<" "<<this->fieldSize.second<<"\n";
}
