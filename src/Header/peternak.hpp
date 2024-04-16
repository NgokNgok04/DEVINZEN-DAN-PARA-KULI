#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"
#define KTKP_PETERNAK 11
class Peternak : public Pemain
{
protected:
    MatrixArea<Hewan> ternakan;

public:
    Peternak();
    Peternak(string usn, float guld, int bb);
    Peternak(const Peternak &);
    ~Peternak();

    MatrixArea<Hewan>& getTernakan();
    void cetakTernak();
    void ternak();     // coords hewan yg ingin diternak, coords letak ternakan
    void kasihMakan(); // coords letak hewan, coords letak makanan yg ingin diberikan
    void panenTernak();
    void beli();
    void jual();
    int countKekayaanTernakan();
    float calculateTax();
    bool searchFood(bool);
    bool checkAllHerbiv();
    bool checkAllCarniv();
};

#endif