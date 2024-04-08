#include <bits/stdc++.h>
#include "../parsers/ParserHewan.hpp"
#include "../parsers/ParserMisc.hpp"
#include "../parsers/ParserTanaman.hpp"
#include "../parsers/ParserProduk.hpp"
#include "../parsers/ParserResep.hpp"
using namespace std;

class GameManager{
    private:
        map<int,tuple<string,string,string,int,int> > AnimalConfig;
        map<int,tuple<string,string,string,int,int> > PlantConfig;
        map<int,tuple<string,string,string,string,int,int> > ProductConfig;
        map<int,tuple<string,string,int,vector<pair<string,int> > > > RecipeConfig;
        int winningMoney;
        int winningWeight;
        pair<int,int> storageSize;
        pair<int,int> fieldSize;
        pair<int,int> farmSize;

        //TODO:
        //1. QUEUE PEMAIN (giliran)
        //2. VOID NEXT
        //3. VOID UNTUK MENENTUKAN PEMENANG
        //4. LIST PEMAIN
    public:
        GameManager(){}
        ~GameManager(){}
        void getAnimalData(ParserHewan);
        void getPlantData(ParserTanaman);
        void getProductData(ParserProduk);
        void getRecipeData(ParserResep);
        void getMiscData(ParserMisc);
        void AnimalDataDebug();
};