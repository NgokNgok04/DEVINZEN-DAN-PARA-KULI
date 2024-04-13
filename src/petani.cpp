#include <iostream>
#include <vector>
#include "petani.hpp"
using namespace std;

Petani::Petani() : Pemain()
{
    this->tipe = "petani";
    MatrixArea<Tanaman> n(8, 8);
    this->ladang = n;
}

Petani::Petani(int guld, int bb, int smol, int med, int big, int ladrows, int ladcols) : Pemain(guld, bb, smol, med, big)
{
    this->tipe = "petani";
    MatrixArea<Tanaman> n(ladrows, ladcols);
    this->ladang = n;
}

Petani::Petani(const Petani &other) : Pemain(other)
{
    this->tipe = "petani";
    MatrixArea<Tanaman> n(other.ladang);
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
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        // cout << idx1 << idx2 << endl;
        if (slot.length() < 3 || slot.length() > 3)
        {
            cout << "Pilihan slot tidak valid!" << endl;
        }
        else
        {
            if (this->inventory.getElement(idx1, idx2) != nullptr)
            {
                cout << "1" << endl;
                if (this->inventory.getElement(idx1, idx2)->getTipeObject() != "TANAMAN")
                {
                    cout << "2" << endl;

                    cout << "Pilihan itu bukanlah tanaman" << endl;
                }
                else
                {
                    cout << "3" << endl;

                    isValid = true;
                }
            }
            else
            {
                cout << "Pilihan itu bukanlah tanaman" << endl;
            }
        }
    }

    // Entah kenapa butuh ini
    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));

    cout << "Kamu memilih " << this->inventory.getElement(idx1, idx2)->getName() << endl; // Nama Objeknya
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
        int idx3 = petak[0] - 'A' + 1;
        int idx4 = std::stoi(petak.substr(1));
        if (petak.length() < 3 || petak.length() > 3)
        {
            cout << "Pilihan petak tidak valid!" << endl;
        }
        else
        {
            if (this->ladang.getElement(idx3 - 1, idx4 - 1) != nullptr)
            {
                if (this->ladang.getElement(idx3 - 1, idx4 - 1) != nullptr)
                {
                    cout << "Pilihan itu bukanlah petak kosong" << endl;
                }
                else
                {
                    isValid = true;
                }
            }
            else
            {
                cout << "pilihan itu bukanlah petak kosong" << endl;
            }
        }
    }
    // Entah kenapa butuh ini
    int idx3 = petak[0] - 'A' + 1;
    int idx4 = std::stoi(petak.substr(1));

    Tanaman *temp = static_cast<Tanaman *>(this->inventory.getElement(idx1 - 1, idx2 - 1));
    this->ladang.setElement(idx3 - 1, idx4 - 1, temp); // karna tanaman
    this->inventory.deleteElement(idx1 - 1, idx2 - 1);
    cout << "berhasil ditanam" << endl;
}

void Petani::panenTani()
{
    this->cetakLadang();
    vector<string> ownedTan;
    vector<string> ownedTanName;
    vector<string> readyPanen;
    vector<int> readyPanenAmt;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->ladang.getElement(i, j)->getTipeObject() == "TANAMAN")
            {
                auto it = find(ownedTan.begin(), ownedTan.end(), this->ladang.getElement(i, j)->getKode());

                bool found = (it != ownedTan.end());

                if (found)
                {
                    ownedTan.push_back(this->ladang.getElement(i, j)->getKode());
                    ownedTanName.push_back(this->ladang.getElement(i, j)->getName());
                }
            }
        }
    }

    // Output tanaman yang ada
    for (size_t i = 0; i < ownedTan.size(); ++i)
    {
        cout << ownedTan[i] << " " << ownedTanName[i] << endl;
    }

    // Output pilihan tanaman berdasarkan siap panennnya
    for (size_t i = 0; i < ownedTan.size(); ++i)
    {
        int count = 0;
        int num = 1;

        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (this->ladang.getElement(j, k)->getKode() == ownedTan[i])
                {
                    if (this->ladang.getElement(j, k)->isHarvestable())
                    {
                        count += 1;
                        auto it = find(readyPanen.begin(), readyPanen.end(), this->ladang.getElement(j, k)->getKode());
                        bool found = (it != readyPanen.end());
                        if (found)
                        {
                            readyPanen.push_back(this->ladang.getElement(j, k)->getKode());
                        }
                    }
                }
            }
        }
        if (count > 0)
        {
            readyPanenAmt.push_back(count);
        }
        count = 0;
    }

    for (int i = 0; i < readyPanen.size(); i++)
    {
        cout << i + 1 << ". " << readyPanen[i] << " " << readyPanenAmt[i] << endl;
    }

    bool isValid = false;
    int maupanen;

    while (!isValid)
    {
        cout << "Nomor tanaman yang ingin dipanen: ";
        cin >> maupanen;
        cout << endl;

        // Validasi

        if (maupanen > readyPanen.size() || maupanen < 0)
        {
            cout << "Nomor masukan tidak valid" << endl;
        }
        else
        {
            isValid = true;
        }
        // int idx1 = slot[0] - 'A' + 1;
        // int idx2 = std::stoi(slot.substr(1));
        // if tidak valid ada output
    }

    isValid = false;
    int brppanen;
    while (!isValid)
    {
        cout << "Berapa petak yang ingin dipanen: ";
        cin >> brppanen;
        cout << endl;
        if (brppanen > this->inventory.getEmptySlot())
        {
            cout << "Jumlah petak pilihan melebihi slot inventory" << endl;
        }
        if (brppanen > readyPanenAmt[maupanen - 1])
        {
            cout << "Jumlah petak pilihan melebihi yang tersedia" << endl;
        }
        else
        {
            isValid = true;
        }
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
            int idx1 = want[0] - 'A' + 1;
            int idx2 = std::stoi(want.substr(1));
            if (want.length() < 3 || want.length() > 3)
            {
                cout << "Pilihan slot tidak valid!" << endl;
            }
            else
            {
                if (this->ladang.getElement(idx1 - 1, idx2 - 1) != nullptr)
                {
                    if (this->ladang.getElement(idx1 - 1, idx2 - 1)->getKode() != readyPanen[maupanen - 1])
                    {
                        cout << "Pilihan itu bukanlah tanaman yang ingin dipanen" << endl;
                    }
                    else
                    {
                        isValid = true;
                    }
                }
                else
                {
                    cout << "Pilihan itu bukanlah tanaman yang ingin dipanen" << endl;
                }
            }
            // Validasi want, kalau valid wants.push_back(want);
        }
        wants.push_back(want);
    }

    for (int i = 0; i < wants.size(); i++)
    {
        int idx1 = want[0] - 'A' + 1;
        int idx2 = std::stoi(want.substr(1));
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (this->inventory.getElement(j, k) == nullptr)
                {
                    this->inventory.setElement(j, k, this->ladang.getElement(idx1 - 1, idx2 - 1)->hasilPanen());
                    this->ladang.deleteElement(idx1 - 1, idx2 - 1);
                }
            }
        }
    }

    cout << "Panen Berhasil" << endl;
}

int Petani::calculateKKP()
{
    return 0;
}

int Petani::calculateTax()
{
    return 0;
}