#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "peternak.hpp"
using namespace std;

Peternak::Peternak() : Pemain()
{
    this->tipe = "peternak";
    MatrixArea<GameObject> n(8, 8);
    this->ternakan = n;
}

Peternak::Peternak(int guld, int bb, int smol, int med, int big, int terrows, int tercols) : Pemain(guld, bb, smol, med, big)
{
    this->tipe = "peternak";
    MatrixArea<GameObject> n(terrows, tercols);
    this->ternakan = n;
}

Peternak::Peternak(const Peternak &other) : Pemain(), ternakan(other.ternakan)
{
    this->tipe = "peternak";
    MatrixArea<GameObject> n(other.ternakan);
    this->ternakan = n;
}

Peternak::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}

void Peternak::beli()
{
    // Need toko
}

void Peternak::jual()
{
    //
}

void Peternak::cetakTernak()
{
    this->ternakan.displayObject();
    // this->ternakan.displayRemainderSlot();
}

void Peternak::ternak()
{
    cout << "Pilih hewan dari penyimpanan" << endl;
    this->cetakPenyimpanan();

    bool isValid = false;
    string slot;
    while (!isValid)
    {
        cout << "Slot: ";
        cin >> slot;
        cout << endl;
        // Validasi
        // if tidak valid print output
    }
    cout << "Kamu memilih " << endl; // Nama Objeknya
    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    this->cetakTernak();

    isValid = false;
    string petak;
    while (!isValid)
    {
        cout << "Petak Tanah: ";
        cin >> petak;
        cout << endl;
        // Validasi
        // if tidak valid print output
    }

    // Hapus dari Inv, Pindahkan ke ladang

    cout << "berhasil diternakkan" << endl;
}

void Peternak::kasihMakan()
{
    cout << "Pilih petak kandang yang akan diberi makan" << endl;
    this->cetakTernak();

    bool isValid = false;
    string slot;
    while (!isValid)
    {
        cout << "Petak Ladang: ";
        cin >> slot;
        cout << endl;
        // Validasi
    }

    cout << "Kamu memilih" << endl; // Nama Objek
    cout << "Pilih pangan untuk diberikan: " << endl;
    this->cetakPenyimpanan();

    isValid = false;
    string slot2;
    while (!isValid)
    {
        cout << "Slot: ";
        cin >> slot2;
        cout << endl;
        // Validasi
    }

    // Output Hasil
}

void Peternak::panenTernak()
{
    this->cetakTernak();

    // Output tanaman yang ada
    // Output pilihan tanaman berdasarkan siap panennnya

    bool isValid = false;
    int maupanen;

    while (!isValid)
    {
        cout << "Nomor hewan yang ingin dipanen: ";
        cin >> maupanen;
        cout << endl;
        // Validasi
        // if tidak valid ada output
    }

    isValid = false;
    int brppanen;
    while (!isValid)
    {
        cout << "Berapa petak yang ingin dipanen: ";
        cin >> brppanen;
        cout << endl;
        // Validasi
        // if tidak valid ada output
    }

    int i = 0;
    string want;
    vector<string> wants;
    cout << "Pilih petak yang ingin dipanen: " << endl;
    for (i; i < brppanen; i++)
    {
        isValid = false;
        while (!isValid)
        {
            cout << "Petak ke-" << i + 1 << ": ";
            cin >> want;
            // Validasi want, kalau valid wants.push_back(want);
        }
    }

    // Output berhasil
}

int Peternak::calculateKKP()
{
    return 0;
}

int Peternak::calculateTax()
{
    return 0;
}