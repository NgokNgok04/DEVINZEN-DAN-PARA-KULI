// #include <iostream>
// #include <vector>
// #include <string>
#include "./Implementation/GameManager.cpp"
#include "petani.cpp"
#include "peternak.cpp"
#include "walikota.cpp"
#include "pemain.cpp"
#include "Toko.cpp"
// #include "./Implementation/ParserMisc.cpp"
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
vector<Hewan> Toko::availableHewan = vector<Hewan>();
vector<Tanaman> Toko::availableTanaman = vector<Tanaman>();
vector<pair<Product, int>> Toko::availableProduct = vector<pair<Product, int>>();
vector<pair<Bangunan, int>> Toko::availableBangunan = vector<pair<Bangunan, int>>();

int main()
{
    ParserHewan PH;
    ParserMisc PM;
    ParserTanaman PT;
    ParserProduk PP;
    ParserResep PR;
    string animalConfigDirectory = "../config/animal.txt";
    string miscConfigDirectory = "../config/misc.txt";
    string plantConfigDirectory = "../config/plant.txt";
    string productConfigDirectory = "../config/product.txt";
    string recipeConfigDirectory = "../config/recipe.txt";

    PH.ParseFile(animalConfigDirectory);
    PM.ParseFile(miscConfigDirectory);
    PT.ParseFile(plantConfigDirectory);
    PP.ParseFile(productConfigDirectory);
    PR.ParseFile(recipeConfigDirectory);
    std::cout << PR << endl;
    Toko::initialize();
    std::cout << "Awal :" << endl
              << endl;
    Toko::printProduct();
    Petani mahew("MAHEW", 1000, 10, 1, 1, 1, 5, 5);
    Peternak gtg("WOIII", 10, 15, 1, 1, 1, 8, 8);
    Product test1(1, ParserProduk::isAnAnimalProduct(1));
    Product test2(2, ParserProduk::isAnAnimalProduct(2));
    Product test3(3, ParserProduk::isAnAnimalProduct(3));
    Product test4(4, ParserProduk::isAnAnimalProduct(4));
    Product test5(5, ParserProduk::isAnAnimalProduct(5));
    Product test6(6, ParserProduk::isAnAnimalProduct(6));
    Product test7(7, ParserProduk::isAnAnimalProduct(7));
    Product test8(8, ParserProduk::isAnAnimalProduct(8));
    // Bangunan tost1(1);
    // Bangunan tost2(2);
    // Bangunan tost3(3);
    // Bangunan tost4(4);
    gtg.setInv(2, 2, &test1);
    gtg.setInv(3, 3, &test2);
    gtg.setInv(4, 4, &test3);
    gtg.setInv(1, 4, &test4);
    gtg.setInv(4, 1, &test5);
    gtg.setInv(2, 7, &test6);
    gtg.setInv(3, 8, &test7);
    gtg.setInv(5, 6, &test8);
    gtg.cetakPenyimpanan();
    // try {
    //     gtg.jual();
    // } catch (ItemQuantityToSellNotEnough err){
    //     err.what();
    // }
    Toko::printProduct();
    gtg.cetakPenyimpanan();
    bool isValid = false;
    int respon;
    while (!isValid)
    {
        mahew.beli();
        cout << endl
             << "Masih mau beli lagi? (0/1)";
        cin >> respon;
        if (respon == 0)
        {
            isValid = true;
            cout << "OKE";
        }
    }

    try
    {
        gtg.jual();
    }
    catch (ItemQuantityToSellNotEnough err)
    {
        err.what();
    }

    mahew.beli();
    return 0;
}