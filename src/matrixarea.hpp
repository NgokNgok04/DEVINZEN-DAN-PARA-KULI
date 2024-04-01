#ifndef MATRIXAREA_HPP
#define MATRIXAREA_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MatrixArea {
    protected:
        int rows;
        int cols;
        vector<vector<string>> matrix;
    public:
        MatrixArea(int, int);
        ~MatrixArea();
        MatrixArea(const MatrixArea&);
        MatrixArea& operator=(const MatrixArea&);
        void setElement(int,int,string);
        string getElement(int,int);
        void displayMatrix();
};

#endif