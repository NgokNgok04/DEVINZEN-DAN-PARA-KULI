#ifndef PETERNAKAN_HPP
#define PETERNAKAN_HPP
#include <iostream>
#include "matrixarea.hpp"
class Peternakan : public MatrixArea {
    public:
        Peternakan(int, int);
        ~Peternakan();
        Peternakan(const Peternakan&);
        Peternakan& operator=(const Peternakan&);
};
#endif