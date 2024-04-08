#include "GameManager.hpp"

void GameManager::getAnimalData(ParserHewan PH)
{
    for(int i = 0; i<PH.getConfigSize(); i++){
        tuple<string,string,string,int,int> newTuple(PH.getCode(i),PH.getName(i),PH.getType(i),PH.getHarvestWeight(i),PH.getPrice(i));
        cout<<get<0>(newTuple)<<"\n";
        AnimalConfig.insert(pair<int,tuple<string,string,string,int,int> > (PH.getID(i),newTuple));
    }
    cout<<"Data konfigurasi hewan berhasil disimpan!\n";
}

void GameManager::AnimalDataDebug()
{
}
