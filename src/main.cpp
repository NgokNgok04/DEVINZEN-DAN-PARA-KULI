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
    // MatrixArea<Hewan> testaja;
    // MatrixArea<GameObject> matrix(4, 2);
    // MatrixArea<Hewan> matrixcctor(matrix);
    // testaja = matrix;
    // cout << "test" << endl;
    // Hewan anjing(1);
    // Hewan kucing(2);
    // Hewan monyet(3);
    // matrix.setElement(1, 1, &anjing);
    // matrix.setElement(1, 2, &kucing);
    // matrix.setElement(2, 1, &monyet);
    // matrix.displayMatrix();
    // matrix.deleteElement(2, 1);
    // matrix.displayMatrix();

    Petani P2;
    Hewan met;
    Tanaman kiel;
    cout << typeid(kiel).name() << endl;

    // GameObject *kielObj = kiel;
    // cout << typeid(kielObj).name() << endl;
    // cout << typeid(*kielObj).name() << endl;

    P2.setInv(2, 2, kiel);
    P2.setInv(5, 2, met);

    cout << "BEFORE" << endl;
    cout << met.getName() << endl;
    cout << met.getKode() << endl;
    cout << met.getTipeObject() << endl;
    cout << met.getType() << endl;
    cout << met.getWeightHarvest() << endl;
    cout << met.getCurWeight() << endl;

    // Tanaman *temp = dynamic_cast<Tanaman *>(P2.inventory.getElement(2, 2));
    Hewan *temp = dynamic_cast<Hewan *>(P2.inventory.getElement(5, 2));
    if (temp)
    {
        cout << "Sukses" << endl;
    }
    else
    {
        cout << "Gagal" << endl;
    }

    cout << "AFTER" << endl;
    cout << temp->getName() << endl;
    cout << temp->getKode() << endl;
    cout << temp->getTipeObject() << endl;
    cout << temp->getType() << endl;
    cout << temp->getWeightHarvest() << endl;
    cout << temp->getCurWeight() << endl;

    // P2.cetakPenyimpanan();
    // P2.tanam();
    // P2.cetakPenyimpanan();
    // P2.cetakLadang();
    // P2.panenTani();

    // Peternak P2;
    // Hewan met;
    // Tanaman kiel;
    // cout << "helo222" << endl;
    // P2.setInv(2, 2, kiel);
    // P2.setInv(5, 2, met);
    // P2.cetakPenyimpanan();
    // P2.ternak();
    // P2.cetakPenyimpanan();
    // P2.cetakTernak();

    return 0;
}