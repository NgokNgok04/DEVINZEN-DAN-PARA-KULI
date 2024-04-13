#ifndef MATRIXAREA_HPP
#define MATRIXAREA_HPP

#include <iostream>
#include <vector>
#include <utility>
#include "./Header/Tanaman.hpp"
#include "./Header/Hewan.hpp"
#include "./Header/GameObject.hpp"
#include "./Header/ParserMisc.hpp"
using namespace std;
template <class T>
class MatrixArea
{
private:
    int rows;
    int cols;
    vector<vector<T *>> matrix;

public:
    MatrixArea();
    MatrixArea(int, int);
    ~MatrixArea();
    MatrixArea(const MatrixArea<T *> &);
    int getRows();
    int getCols();
    MatrixArea<T *> &operator=(const MatrixArea<T *> &);
    void setElement(int, int, T *);
    void deleteElement(int, int);
    T *getElement(int, int);
    pair<int, int> getPositionFromSlot(string slot);
    void displayMatrix();
    void displayObject();
    void displayDetail();
    void displayRemainderSlot();
    bool isEmpty();
    int getEmptySlot();
};

#endif