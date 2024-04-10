#ifndef TOKO_HPP
#define TOKO_HPP
#include <vector>
#include <utility>
#include "GameObject.hpp"

class Toko {
    private:
        vector<pair<string,int,int>> availItem;
    public:
        Toko();
        
        void displayAvailableToBuy();

};
#endif