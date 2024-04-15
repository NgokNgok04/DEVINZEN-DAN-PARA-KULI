#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
#include "./misc/helper.cpp"
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
        Toko();
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
};
#endif