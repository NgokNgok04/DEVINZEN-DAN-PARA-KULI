#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
#include "helper.hpp"
#include "GameObject.hpp"
#include "Hewan.hpp"
#include "Tanaman.hpp"
#include "Product.hpp"
#include "Bangunan.hpp"
#include "ParserHewan.hpp"
#include "ParserTanaman.hpp"
#include "ParserProduk.hpp"
#include "ParserResep.hpp"
using namespace std;
class Toko {
    public:
        static vector<Hewan> availableHewan;
        static vector<Tanaman> availableTanaman;
        static vector<pair<Product,int>> availableProduct;
        static vector<pair<Bangunan,int>> availableBangunan;
        static void printProduct();
        static void printBangunan();
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