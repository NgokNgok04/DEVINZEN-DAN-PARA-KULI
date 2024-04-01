#ifndef LADANG_HPP
#define LADANG_HPP
#include <iostream>
#include "matrixarea.hpp"
class Ladang : public MatrixArea {
    public:
        Ladang(int, int);
        ~Ladang();
        Ladang(const Ladang&);
        Ladang& operator=(const Ladang&);

};
#endif