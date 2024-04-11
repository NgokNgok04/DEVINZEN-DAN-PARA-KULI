#include <iostream>
#include <vector>
#include "petani.hpp"
using namespace std;

Petani::Petani() : Pemain()
{
    this->tipe = "petani";
    MatrixArea<GameObject> n(8, 8);
    this->ladang = n;
}

Petani::Petani(int guld, int bb, int smol, int med, int big, int ladrows, int ladcols) : Pemain(guld, bb, smol, med, big)
{
    this->tipe = "petani";
    MatrixArea<GameObject> n(ladrows, ladcols);
    this->ladang = n;
}

Petani::Petani(const Petani &other) : Pemain(other)
{
    this->tipe = "petani";
    MatrixArea<GameObject> n(other.ladang);
    this->ladang = n;
}

Petani::~Petani()
{
    this->inventory.~MatrixArea();
    this->ladang.~MatrixArea();
}

void Petani::beli()
{
    // Need toko
}

void Petani::jual()
{
    // Need toko
}

void Petani::cetakLadang()
{
    this->ladang.displayObject();
    // this->ladang.displayRemainderSlot();
}

void Petani::tanam()
{
    cout << "Pilih Tanaman dari penyimpanan" << endl;
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
    cout << "Pilih petak tanah yang akan ditanami" << endl;
    this->cetakLadang();

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

    cout << "berhasil ditanam" << endl;
}

void Petani::panenTani()
{
    this->cetakLadang();

    // Output tanaman yang ada
    // Output pilihan tanaman berdasarkan siap panennnya

    bool isValid = false;
    int maupanen;

    while (!isValid)
    {
        cout << "Nomor tanaman yang ingin dipanen: ";
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

int Petani::calculateKKP()
{
    return 0;
}

int Petani::calculateTax()
{
    return 0;
}