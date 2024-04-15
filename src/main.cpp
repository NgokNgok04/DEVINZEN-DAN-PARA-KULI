// #include <iostream>
// #include <vector>
// #include <string>
#include "pemain.cpp"
#include "petani.cpp"
#include "peternak.cpp"
#include "./Implementation/Tanaman.cpp"
#include "./Implementation/Hewan.cpp"
#include "./Implementation/Product.cpp"
#include "./Implementation/ParserTanaman.cpp"
#include "./Implementation/ParserProduk.cpp"
#include "./Implementation/ParserHewan.cpp"
#include "./Implementation/ParserResep.cpp"
// #include "./Implementation/ParserMisc.cpp"
// #include "./Implementation/ParserMisc.cpp"
#include "./misc/helper.cpp"
// #include "walikota.cpp"
// #include "./Implementation/Hewan.cpp"
#include <iostream>
// #include "./Header/Exception.hpp"
// #include "./Header/GameManager.hpp"
using namespace std;

// inisialisasi atribut static di semua parser
vector<string> ParserHewan::validAnimalTypes = {"HERBIVORE", "CARNIVORE", "OMNIVORE"};
vector<int> ParserHewan::animalID = vector<int>();
vector<string> ParserHewan::animalCode = vector<string>();
vector<string> ParserHewan::animalName = vector<string>();
vector<string> ParserHewan::animalType = vector<string>();
vector<int> ParserHewan::harvestWeight = vector<int>();
vector<int> ParserHewan::price = vector<int>();
map<int, int> ParserHewan::IndexToIDMap = map<int, int>();
map<int, int> ParserHewan::IDToIndexMap = map<int, int>();
int ParserMisc::winningMoney = 0;
int ParserMisc::winningWeight = 0;
pair<int, int> ParserMisc::storageSize = pair<int, int>();
pair<int, int> ParserMisc::fieldSize = pair<int, int>();
pair<int, int> ParserMisc::farmSize = pair<int, int>();
vector<int> ParserProduk::productID = vector<int>();
vector<string> ParserProduk::productCode = vector<string>();
vector<string> ParserProduk::productName = vector<string>();
vector<string> ParserProduk::productType = vector<string>();
vector<string> ParserProduk::productOrigin = vector<string>();
vector<int> ParserProduk::addedWeight = vector<int>();
vector<int> ParserProduk::price = vector<int>();
vector<string> ParserProduk::validProductTypes = vector<string>();
map<int, int> ParserProduk::IndexToIDMap = map<int, int>();
map<int, int> ParserProduk::IDToIndexMap = map<int, int>();
vector<int> ParserResep::recipeID = vector<int>();
vector<string> ParserResep::recipeCode = vector<string>();
vector<string> ParserResep::recipeName = vector<string>();
vector<int> ParserResep::recipePrice = vector<int>();
vector<vector<pair<string, int>>> ParserResep::recipeMaterialQuantity = vector<vector<pair<string, int>>>();
map<int, int> ParserResep::IndexToIDMap = map<int, int>();
map<int, int> ParserResep::IDToIndexMap = map<int, int>();
vector<int> ParserTanaman::plantID = vector<int>();
vector<string> ParserTanaman::plantCode = vector<string>();
vector<string> ParserTanaman::plantName = vector<string>();
vector<string> ParserTanaman::plantType = vector<string>();
vector<int> ParserTanaman::harvestDuration = vector<int>();
vector<int> ParserTanaman::price = vector<int>();
vector<string> ParserTanaman::validPlantTypes = vector<string>();
map<int, int> ParserTanaman::IndexToIDMap = map<int, int>();
map<int, int> ParserTanaman::IDToIndexMap = map<int, int>();

int main()
{
    ParserHewan PH;
    // ParserMisc PM;
    ParserTanaman PT;
    ParserProduk PP;
    ParserResep PR;
    string animalConfigDirectory = "../config/animal.txt";
    string miscConfigDirectory = "../config/misc.txt";
    string plantConfigDirectory = "../config/plant.txt";
    string productConfigDirectory = "../config/product.txt";
    string recipeConfigDirectory = "../config/recipe.txt";

    PH.ParseFile(animalConfigDirectory);
    // PM.ParseFile(miscConfigDirectory);
    PT.ParseFile(plantConfigDirectory);
    PP.ParseFile(productConfigDirectory);
    PR.ParseFile(recipeConfigDirectory);

    Petani p;
    

    return 0;
}