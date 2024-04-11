#include <iostream>
#include <string>
#include <vector>
#include "matrixarea.hpp"
using namespace std;
template <class T>
MatrixArea<T>::MatrixArea(){
    this->rows = 0;
    this->cols = 0;
    this->matrix.resize(this->rows,vector<T*>(this->cols,nullptr));
    cout << "success default ctor" << endl;
}
// template <>
// MatrixArea<GameObject>::MatrixArea(){
//     pair<int,int> = ParserMis
//     this->rows = ParserMisc::getStorageSize().
// }

template <class T>
MatrixArea<T>::MatrixArea(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(this->rows, vector<T*>(this->cols,nullptr));
    cout << "success user defined ctor" << endl;
}
template <class T>
MatrixArea<T>::~MatrixArea()
{
    this->matrix.clear();
    cout << "dtor success" << endl;
}
template <class T>
MatrixArea<T>::MatrixArea(const MatrixArea<T*> &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix = matrix.matrix;
    cout << "cctor success" << endl;
}

template <class T>
MatrixArea<T*> &MatrixArea<T>::operator=(const MatrixArea<T*> &matrix)
{
    if (this != &matrix)
    {
        this->rows = matrix.rows;
        this->cols = matrix.cols;
        this->matrix = matrix.matrix;
    }
    return *this;
}

template <class T>
void MatrixArea<T>::setElement(int row, int col, T* object)
{
    // asumsi row n col selalu benar
    this->matrix[row - 1][col - 1] = object;
    cout << "set Element success" << endl;
}

template <class T>
T* MatrixArea<T>::getElement(int row, int col)
{
    // asumsi row n col selalu benar
    cout << "get Element success" << endl;
    return this->matrix[row - 1][col - 1];
}

template <class T>
void MatrixArea<T>::deleteElement(int row, int col){
    this->matrix[row - 1][col - 1] = nullptr;
    cout << "delete Element success" << endl;
}

template <class T>
pair<int,int> MatrixArea<T>::getPositionFromSlot(string slot){
   int posCol = slot[0] - 'A' + 1;
   int posRow =  stoi(string(1,slot[1]) + string(1,slot[2]));
   return make_pair(posRow, posCol);
}

template <class T>
void MatrixArea<T>::displayMatrix()
{
    cout << "    ";
    for (int i = 0; i < this->cols; i++)
    {
        cout << "  " << static_cast<char>(static_cast<int>('A') + i) << "   ";
    }
    cout << endl;
    string grid = "   +";
    for (int i = 0; i < this->cols; i++)
    {
        grid += "-----+";
    }

    for (int i = 0; i < this->rows; i++)
    {
        cout << grid << endl;
        cout << "0" << i + 1 << " ";
        cout << "|";
        for(int j = 0; j < this->cols; j++){
            if (this->matrix[i][j] == nullptr){
                cout << "     ";
            } 
            else{
                cout << " " << this->matrix[i][j]->getKode() << " ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << grid << endl;
}

template <>
void MatrixArea<GameObject>::displayObject()
{
    int title = (this->cols * 6) + 4;
    cout << "   ";
    if (title > 15)
    {
        if ((title - 15) % 2 == 0)
        {
            for (int i = 0; i < (title - 15) / 2; i++)
            {
                cout << "=";
            };
            cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title - 15) / 2; i++)
            {
                cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 15) / 2 - 1; i++)
            {
                cout << "=";
            };
            cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title - 15) / 2 - 1; i++)
            {
                cout << "=";
            };
        }
        cout << endl;
    }
    else
    {
        cout << "[ Penyimpanan ]" << endl;
    }
    MatrixArea<GameObject>::displayMatrix(); 
}

template <>
void MatrixArea<Hewan>::displayObject()
{
    int title = (this->cols * 6) + 4;
    cout << "   ";
    if (title > 14)
    {
        if ((title - 14) % 2 == 0)
        {
            for (int i = 0; i < (title - 14) / 2; i++)
            {
                cout << "=";
            };
            cout << "[ Peternakan ]";
            for (int i = 0; i < (title - 14) / 2; i++)
            {
                cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 14) / 2 - 1; i++)
            {
                cout << "=";
            };
            cout << "[ Peternakan ]";
            for (int i = 0; i < (title - 14) / 2 - 1; i++)
            {
                cout << "=";
            };
        }
        cout << endl;
    }
    else
    {
        cout << "[ Peternakan ]" << endl;
    }
    MatrixArea<Hewan>::displayMatrix();
    // dummy Class di local mahew (ga dipush)
}

template <>
void MatrixArea<Tanaman>::displayObject()
{
    int title = (this->cols * 6) + 4;
    cout << "   ";
    if (title > 10)
    {
        if ((title - 10) % 2 == 0)
        {
            for (int i = 0; i < (title - 10) / 2; i++)
            {
                cout << "=";
            };
            cout << "[ Ladang ]";
            for (int i = 0; i < (title - 10) / 2; i++)
            {
                cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 10) / 2 - 1; i++)
            {
                cout << "=";
            };
            cout << "[ Ladang ]";
            for (int i = 0; i < (title - 10) / 2 - 1; i++)
            {
                cout << "=";
            };
        }
        cout << endl;
    }
    else
    {
        cout << "[ Ladang ]" << endl;
    }
    MatrixArea<Tanaman>::displayMatrix();
    // dummy Class di local mahew (ga dipush)
}

template <class T>
void MatrixArea<T>::displayDetail()
{
    cout << endl;
    vector<string> foundList;
    bool found;
    for (int i = 0; i < this->rows; i++)
    {
        found = false;
        for (int j = 0; j < this->rows; j++)
        {
            for (const string itr : foundList)
            {
                if (itr == this->matrix[i][j].getKodeHuruf())
                {
                    found = true;
                };
            };
            if (!found)
            {
                cout << "- " << this->matrix[i][j].getKodeHuruf() << ": " << this->matrix[i][j].getName() << endl;
            }
        }
    }
}

template <class T>
void MatrixArea<T>::displayRemainderSlot()
{
    cout << endl;
    int remainderSlot = this->rows * this->cols;
    for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->cols; j++){
            if ((this->matrix[i][j].getKodeHuruf()).length() == 3){
                remainderSlot --;
            }
        }
    }
    cout << "Total slot kosong: " << remainderSlot << endl;
}