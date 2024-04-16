#include <iostream>
#include <string>
#include <vector>
#include "../Header/matrixarea.hpp"

using namespace std;
template <class T>
MatrixArea<T>::MatrixArea()
{
    this->rows = 0;
    this->cols = 0;
    this->matrix.resize(this->rows, vector<T *>(this->cols, nullptr));
}

template <class T>
MatrixArea<T>::MatrixArea(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(this->rows, vector<T *>(this->cols, nullptr));
}
template <class T>
MatrixArea<T>::~MatrixArea()
{
    this->matrix.clear();
}

template <class T>
MatrixArea<T>::MatrixArea(const MatrixArea<T *> &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix = matrix.matrix;
}

template <class T>
MatrixArea<T *> MatrixArea<T>::operator=(const MatrixArea<T *> &matrix)
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
void MatrixArea<T>::operator+(T *&object)
{
    bool found = false;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr && !found)
            {
                this->matrix[i][j] = object;
                found = true;
            }
        }
    }
}

template <class T>
void MatrixArea<T>::setElement(int row, int col, T *object)
{
    this->matrix[row - 1][col - 1] = object;
}

template <class T>
T *MatrixArea<T>::getElement(int row, int col)
{
    return this->matrix[row - 1][col - 1];
}

template <class T>
int MatrixArea<T>::getRows()
{
    return this->rows;
}

template <class T>
int MatrixArea<T>::getCols()
{
    return this->cols;
}

template <class T>
void MatrixArea<T>::deleteElement(int row, int col)
{
    this->matrix[row - 1][col - 1] = nullptr;
}

template <class T>
pair<int, int> MatrixArea<T>::getPositionFromSlot(string slot)
{
    if (slot.size() > 3)
    {
        throw InvalidPositionMatrixArea();
    }
    int posCol = slot[0] - 'A' + 1;
    if (posCol < 0 || posCol > this->cols)
    {
        throw InvalidPositionMatrixArea();
    }
    int posRow = stoi(string(1, slot[1]) + string(1, slot[2]));
    if (posRow < 0 || posRow > this->rows)
    {
        throw InvalidPositionMatrixArea();
    }

    return make_pair(posRow, posCol);
}

// template <class T>
// void MatrixArea<T>::displayMatrix()
// {
//     std::cout << "    ";
//     for (int i = 0; i < this->cols; i++)
//     {
//         std::cout << "  " << static_cast<char>(static_cast<int>('A') + i) << "   ";
//     }
//     std::cout << endl;
//     string grid = "   +";
//     for (int i = 0; i < this->cols; i++)
//     {
//         grid += "-----+";
//     }

//     for (int i = 0; i < this->rows; i++)
//     {
//         std::cout << grid << endl;
//         std::cout << "0" << i + 1 << " ";
//         std::cout << "|";
//         for (int j = 0; j < this->cols; j++)
//         {
//             if (this->matrix[i][j] == nullptr)
//             {
//                 std::cout << "     ";
//             }
//             else
//             {
//                 std::cout << " " << this->matrix[i][j]->getKode() << " ";
//             }
//             std::cout << "|";
//         }
//         std::cout << endl;
//     }
//     std::cout << grid << endl;
// }

template <>
inline void MatrixArea<GameObject>::displayMatrix()
{
    std::cout << "    ";
    for (int i = 0; i < this->cols; i++)
    {
        std::cout << "  " << static_cast<char>(static_cast<int>('A') + i) << "   ";
    }
    std::cout << endl;
    string grid = "   +";
    for (int i = 0; i < this->cols; i++)
    {
        grid += "-----+";
    }

    for (int i = 0; i < this->rows; i++)
    {
        std::cout << grid << endl;
        if (i < 9){
            std::cout << "0" << i + 1 << " ";
        } else {
            std::cout << i + 1 << " ";
        }
        std::cout << "|";
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr)
            {
                std::cout << "     ";
            }
            else
            {
                std::cout << " " << this->matrix[i][j]->getKode() << " ";
            }
            std::cout << "|";
        }
        std::cout << endl;
    }
    std::cout << grid << endl;
}

template <> inline
void MatrixArea<Hewan>::displayMatrix()
{
    std::cout << "    ";
    for (int i = 0; i < this->cols; i++)
    {
        std::cout << "  " << static_cast<char>(static_cast<int>('A') + i) << "   ";
    }
    std::cout << endl;
    string grid = "   +";
    for (int i = 0; i < this->cols; i++)
    {
        grid += "-----+";
    }

    for (int i = 0; i < this->rows; i++)
    {
        std::cout << grid << endl;
        std::cout << "0" << i + 1 << " ";
        std::cout << "|";
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr)
            {
                std::cout << "     ";
            }
            else
            {
                std::cout << " ";
                for (int k = 0; k < 3; k++)
                {
                    if (this->matrix[i][j]->isHarvestable())
                    {
                        print_green(this->matrix[i][j]->getKode()[k]);
                    }
                    else
                    {
                        print_red(this->matrix[i][j]->getKode()[k]);
                    }
                }
                cout << " ";
            }
            std::cout << "|";
        }
        std::cout << endl;
    }
    std::cout << grid << endl;
}

template <>
inline void MatrixArea<Tanaman>::displayMatrix()
{
    std::cout << "    ";
    for (int i = 0; i < this->cols; i++)
    {
        std::cout << "  " << static_cast<char>(static_cast<int>('A') + i) << "   ";
    }
    std::cout << endl;
    string grid = "   +";
    for (int i = 0; i < this->cols; i++)
    {
        grid += "-----+";
    }

    for (int i = 0; i < this->rows; i++)
    {
        std::cout << grid << endl;
        std::cout << "0" << i + 1 << " ";
        std::cout << "|";
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr)
            {
                std::cout << "     ";
            }
            else
            {
                std::cout << " ";
                for (int k = 0; k < 3; k++)
                {
                    if (this->matrix[i][j]->isHarvestable())
                    {
                        print_green(this->matrix[i][j]->getKode()[k]);
                    }
                    else
                    {
                        print_red(this->matrix[i][j]->getKode()[k]);
                    }
                }
                cout << " ";
            }
            std::cout << "|";
        }
        std::cout << endl;
    }
    std::cout << grid << endl;
}

template <>
inline void MatrixArea<GameObject>::displayObject()
{
    int title = (this->cols * 6) + 4;
    std::cout << "   ";
    if (title > 15)
    {
        if ((title - 15) % 2 == 0)
        {
            for (int i = 0; i < (title - 15) / 2; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title - 15) / 2; i++)
            {
                std::cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 15) / 2 - 1; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title - 15) / 2 - 1; i++)
            {
                std::cout << "=";
            };
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "[ Penyimpanan ]" << endl;
    }
    MatrixArea<GameObject>::displayMatrix();
}

template <>
inline void MatrixArea<Hewan>::displayObject()
{
    int title = (this->cols * 6) + 4;
    std::cout << "   ";
    if (title > 14)
    {
        if ((title - 14) % 2 == 0)
        {
            for (int i = 0; i < (title - 14) / 2; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Peternakan ]";
            for (int i = 0; i < (title - 14) / 2; i++)
            {
                std::cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 14) / 2 - 1; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Peternakan ]";
            for (int i = 0; i < (title - 14) / 2 - 1; i++)
            {
                std::cout << "=";
            };
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "[ Peternakan ]" << endl;
    }
    MatrixArea<Hewan>::displayMatrix();
    // dummy Class di local mahew (ga dipush)
}

template <>
inline void MatrixArea<Tanaman>::displayObject()
{
    int title = (this->cols * 6) + 4;
    std::cout << "   ";
    if (title > 10)
    {
        if ((title - 10) % 2 == 0)
        {
            for (int i = 0; i < (title - 10) / 2; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Ladang ]";
            for (int i = 0; i < (title - 10) / 2; i++)
            {
                std::cout << "=";
            };
        }
        else
        {
            for (int i = 0; i < (title - 10) / 2 - 1; i++)
            {
                std::cout << "=";
            };
            std::cout << "[ Ladang ]";
            for (int i = 0; i < (title - 10) / 2 - 1; i++)
            {
                std::cout << "=";
            };
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "[ Ladang ]" << endl;
    }
    MatrixArea<Tanaman>::displayMatrix();
    // dummy Class di local mahew (ga dipush)
}

template <class T>
void MatrixArea<T>::displayDetail()
{
    std::cout << endl;
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
                std::cout << "- " << this->matrix[i][j].getKodeHuruf() << ": " << this->matrix[i][j].getName() << endl;
            }
        }
    }
}

template <class T>
void MatrixArea<T>::displayRemainderSlot()
{
    std::cout << endl;
    int remainderSlot = 0;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr)
            {
                remainderSlot++;
            }
        }
    }
    std::cout << "Total slot kosong: " << remainderSlot << endl;
}

template <class T>
bool MatrixArea<T>::isEmpty()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

template <class T>
int MatrixArea<T>::getEmptySlot()
{
    int count = 0;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] == nullptr)
            {
                count++;
            }
        }
    }
    return count;
}

template <>
inline Tanaman *MatrixArea<GameObject>::convertTanaman(int row, int col)
{
    Tanaman *temp = dynamic_cast<Tanaman *>(this->getElement(row, col));
    return temp;
}

template <>
inline Hewan *MatrixArea<GameObject>::convertHewan(int row, int col)
{
    Hewan *temp = dynamic_cast<Hewan *>(this->getElement(row, col));
    return temp;
}

template <class T>
int MatrixArea<T>::countSameName(string name)
{
    int count = 0;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] != nullptr && this->matrix[i][j]->getName() == name)
            {
                count++;
            }
        }
    }
    return count;
}