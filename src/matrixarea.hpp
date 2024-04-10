#ifndef MATRIXAREA_HPP
#define MATRIXAREA_HPP

#include <iostream>
#include <vector>
#include "hewan.hpp"
#include "tumbuhan.hpp"
#include "GameObject.hpp"
using namespace std;
template <class T>
class MatrixArea
{
private:
    int rows;
    int cols;
    vector<vector<T>> matrix;

public:
    MatrixArea();
    MatrixArea(int, int);
    ~MatrixArea();
    MatrixArea(const MatrixArea<T> &);
    MatrixArea<T> &operator=(const MatrixArea<T> &);
    void setElement(int, int, T);
    T getElement(int, int);
    void displayMatrix();
    void displayObject();
    void displayDetail();
    void displayRemainderSlot();
};

#endif