#include <iostream>
#include <vector>
#include "peternak.hpp"
#include "./Header/Product.hpp"
using namespace std;

Peternak::Peternak() : Pemain()
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(8, 8);
    this->ternakan = n;
}

Peternak::Peternak(int guld, int bb, int smol, int med, int big, int terrows, int tercols) : Pemain(guld, bb, smol, med, big)
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(terrows, tercols);
    this->ternakan = n;
}

Peternak::Peternak(const Peternak &other) : Pemain()
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(other.ternakan);
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
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        try
        {
            if (slot.length() < 3 || slot.length() > 3)
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx1 > this->inventory.getRows() || idx2 > this->inventory.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->inventory.getElement(idx2, idx1) != nullptr)
                {
                    cout << "here2" << endl;

                    if (this->inventory.getElement(idx2, idx1)->getTipeObject() != "HEWAN")
                    {
                        throw InvalidNotHewan();
                    }
                    else
                    {
                        isValid = true;
                    }
                }
                else
                {
                    throw InvalidEmptySlot();
                }
            }
        }
        catch (BaseException &e)
        {
            cout << e.what() << endl;
        }
    }

    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));

    cout << "Kamu memilih " << this->inventory.getElement(idx2, idx1)->getName() << endl; // Nama Objeknya
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
        int idx3 = petak[0] - 'A' + 1;
        int idx4 = std::stoi(petak.substr(1));
        try
        {
            if (petak.length() < 3 || petak.length() > 3)
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx3 > this->ternakan.getRows() || idx4 > this->ternakan.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->ternakan.getElement(idx4, idx3) == nullptr)
                {

                    isValid = true;
                }
                else
                {
                    InvalidFilledSlot();
                }
            }
        }
        catch (BaseException &e)
        {
            cout << e.what() << endl;
        }
    }

    int idx3 = petak[0] - 'A' + 1;
    int idx4 = std::stoi(petak.substr(1));

    Hewan *temp = static_cast<Hewan *>(this->inventory.getElement(idx2, idx1));
    this->ternakan.setElement(idx4, idx3, temp);
    this->inventory.deleteElement(idx2, idx1);
    cout << "Berhasil diternakkan" << endl;
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
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        if (this->ternakan.getElement(idx1 - 1, idx2 - 1) != nullptr)
        {
            isValid = true;
        }
        else
        {
            cout << "Petak tersebut kosong" << endl;
        }
    }

    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));
    cout << "Kamu memilih " << this->ternakan.getElement(idx1 - 1, idx2 - 1)->getName() << " untuk diberi makan" << endl;
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
        int idx3 = slot2[0] - 'A' + 1;
        int idx4 = std::stoi(slot2.substr(1));

        Product *temp = static_cast<Product *>(this->inventory.getElement(idx3 - 1, idx4 - 1));
        if (temp->fromHewan())
        {
            isValid = true;
        }
        else
        {
            cout << "Itu bukanlah pangan yang dapat diberi pada hewan" << endl;
        }
    }

    int idx3 = slot2[0] - 'A' + 1;
    int idx4 = std::stoi(slot2.substr(1));
    Product *temp = static_cast<Product *>(this->inventory.getElement(idx3 - 1, idx4 - 1));

    this->ternakan.getElement(idx1 - 1, idx2 - 1)->setWeight(this->ternakan.getElement(idx1 - 1, idx2 - 1)->getCurWeight() + temp->getAddedWeight());
    this->inventory.deleteElement(idx3 - 1, idx4 - 1);
    cout << this->ternakan.getElement(idx1 - 1, idx2 - 1)->getName() << " sudah diberi makan dan beratnya menjadi" << endl;

    // Output Hasil
}

void Peternak::panenTernak()
{
    this->cetakTernak();
    vector<string> ownedHew;
    vector<string> ownedHewName;
    vector<string> readyPanen;
    vector<int> readyPanenAmt;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->ternakan.getElement(i, j)->getTipeObject() == "HEWAN")
            {
                auto it = find(ownedHew.begin(), ownedHew.end(), this->ternakan.getElement(i, j)->getKode());

                bool found = (it != ownedHew.end());

                if (found)
                {
                    ownedHew.push_back(this->ternakan.getElement(i, j)->getKode());
                    ownedHewName.push_back(this->ternakan.getElement(i, j)->getName());
                }
            }
        }
    }

    // Output hewan yang ada
    for (size_t i = 0; i < ownedHew.size(); ++i)
    {
        cout << ownedHew[i] << " " << ownedHewName[i] << endl;
    }

    // Output pilihan hewan berdasarkan siap panennnya
    for (size_t i = 0; i < ownedHew.size(); ++i)
    {
        int count = 0;
        int num = 1;

        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (this->ternakan.getElement(j, k)->getKode() == ownedHew[i])
                {
                    if (this->ternakan.getElement(j, k)->isHarvestable())
                    {
                        count += 1;
                        auto it = find(readyPanen.begin(), readyPanen.end(), this->ternakan.getElement(j, k)->getKode());
                        bool found = (it != readyPanen.end());
                        if (found)
                        {
                            readyPanen.push_back(this->ternakan.getElement(j, k)->getKode());
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
        cout << "Nomor hewan yang ingin dipanen: ";
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
                if (this->ternakan.getElement(idx1 - 1, idx2 - 1) != nullptr)
                {
                    if (this->ternakan.getElement(idx1 - 1, idx2 - 1)->getKode() != readyPanen[maupanen - 1])
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
        int idx1 = wants[i][0] - 'A' + 1;
        int idx2 = std::stoi(wants[i].substr(1));
        int j = 0;
        int k = 0;
        while (j < 8)
        {
            while (k < 8)
            {
                if (this->inventory.getElement(j, k) == nullptr)
                {
                    vector<Product *> temp = this->ternakan.getElement(idx1 - 1, idx2 - 1)->hasilPanen();
                    for (int n = 0; n < temp.size(); n++)
                    {
                        this->inventory.setElement(j, k, temp[i]);
                        if (n < temp.size() - 1)
                        {
                            if (k == 7)
                            {
                                j++;
                                k = 0;
                            }
                            else
                            {
                                k++;
                            }
                        }
                        // boleh kalau j dan k udah max exception ga ada slot lagi
                    }

                    this->ternakan.deleteElement(idx1 - 1, idx2 - 1);
                }
                k++;
            }
            j++;
        }
    }

    cout << "Panen Berhasil" << endl;
}

int Peternak::calculateKKP()
{
    return 0;
}

int Peternak::calculateTax()
{
    return 0;
}