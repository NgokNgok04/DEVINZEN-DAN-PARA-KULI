#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
// #include "./misc/helper.cpp"
#include "./Implementation/GameObject.cpp"
#include "./Implementation/Hewan.cpp"
#include "./Implementation/Tanaman.cpp"
#include "./Implementation/Product.cpp"
#include "./Implementation/Bangunan.cpp"
#include "./Implementation/ParserHewan.cpp"
#include "./Implementation/ParserTanaman.cpp"
#include "./Implementation/ParserProduk.cpp"
#include "./Implementation/ParserResep.cpp"
using namespace std;
class Toko {
    public:
        static vector<Hewan> availableHewan;
        static vector<Tanaman> availableTanaman;
        static vector<pair<Product,int>> availableProduct;
        static vector<pair<Bangunan,int>> availableBangunan;
        static void initialize();
        static int buyProcess();
        static void itemDibeli(GameObject*, int); //handle keadaan toko setelah player membeli item
        static void itemDijual(GameObject*, int); //handle keadaan toko setelah player menjual item
        static bool isProductEmptyStock();
        static bool isBangunanEmptyStock();
        static void displayAvailableHewan();
        static void displayAvailableTanaman();
        static int displayAvailableProduct();
        static int displayAvailableBangunan();
        static void displayResepBangunan();
        static int getStock(string);
        static void pushProduct(pair<Product,int>);
        static void pushBangunan(pair<Bangunan,int>);
        static Bangunan getBangunan(int);
};
#endif

// 4
// Budi Peternak 20 100
// 5
// COW
// COW_MEAT
// COW
// ALOE_TREE
// SMALL_HOUSE
// 3
// A01 CHICKEN 1
// E02 DUCK 1
// C01 SHEEP 2
// Jongrang Peternak 10 100
// 2
// CHICKEN_EGG
// ALOE_WOOD
// 0
// Roro Petani 5 1000
// 5
// APPLE_TREE
// APPLE
// COW
// ALOE_TREE
// MEDIUM_HOUSE
// 2
// B01 ORANGE_TREE 0
// F02 BANANA_TREE 2
// Bondowoso Walikota 70 100
// 3
// SANDALWOOD_WOOD
// BANANA
// HOTEL
// 5
// BANANA 2
// APPLE 5
// MEDIUM_HOUSE 1
// CHICKEN_MEAT 2
// DUCK_EGG 3