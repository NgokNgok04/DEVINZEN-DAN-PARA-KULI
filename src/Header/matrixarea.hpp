#ifndef MATRIXAREA_HPP
#define MATRIXAREA_HPP

#include <iostream>
#include <vector>
#include <utility>
#include "Tanaman.hpp"
#include "Hewan.hpp"
#include "GameObject.hpp"
#include "ParserMisc.hpp"
#include "pcolor.hpp"
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
    MatrixArea<T *> operator=(const MatrixArea<T *> &);
    void operator+(T *&);
    void setElement(int, int, T *);
    void deleteElement(int, int);
    T *getElement(int, int);
    int getRows();
    int getCols();
    pair<int, int> getPositionFromSlot(string slot);
    void displayMatrix();
    void displayObject();
    void displayDetail();
    void displayRemainderSlot();
    bool isEmpty();
    int getEmptySlot();
    int countSameName(string);
    Tanaman *convertTanaman(int, int);
    Hewan *convertHewan(int, int);
};

#endif