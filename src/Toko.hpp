#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
#include "GameObject.hpp"
#include "helper.hpp"
extern Toko tokoGlobal;
class Toko {
    private:
        vector<pair<string,int>> availableItem;
    public:
        Toko();
        void displayAvailableItemToBuy();
        void itemDibeli(); //handle keadaan toko setelah player membeli item
        void itemDijual(); //handle keadaan toko setelah player menjual item

};
#endif