#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
#include "GameObject.hpp"
#include "helper.hpp"
#include "./Header/GameObject.hpp"
#include "./Header/Parser/ParserHewan.hpp"
#include "./Header/Parser/ParserTanaman.hpp"
#include "./Header/Parser/ParserProduk.hpp"
#include "./Header/Parser/ParserResep.hpp"
// #include "./"
extern Toko tokoGlobal;

class Toko {
    private:
        vector<pair<GameObject,int>> availableGameObject;
    public:
        Toko();
        void displayAvailableItemToBuy();
        void itemDibeli(); //handle keadaan toko setelah player membeli item
        void itemDijual(); //handle keadaan toko setelah player menjual item

};
#endif