#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include "matrixarea.hpp"
class Inventory : public MatrixArea {
    public:
        Inventory(int, int);
        ~Inventory();
        Inventory(const Inventory&);
        Inventory& operator=(const Inventory&);
        void displayMatrix();
};
#endif