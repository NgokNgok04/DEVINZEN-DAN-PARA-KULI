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

MatrixArea<Hewan> Peternak::getTernakan()
{
    return this->ternakan;
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

    Hewan *temp = new Hewan;
    temp = dynamic_cast<Hewan *>(this->inventory.getElement(idx2, idx1));
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
        cout << "Petak Ternakan: ";
        cin >> slot;
        cout << endl;
        // Validasi
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        if (slot.length() < 3 || slot.length() > 3)
        {
            throw InvalidIndexMatrixArea();
        }
        else if (idx1 > this->ternakan.getRows() || idx2 > this->ternakan.getCols())
        {
            throw InvalidIndexMatrixArea();
        }
        else
        {
            if (this->ternakan.getElement(idx2, idx1) != nullptr)
            {
                isValid = true;
            }
            else
            {
                throw InvalidEmptySlot();
            }
        }
    }

    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));
    cout << "Kamu memilih " << this->ternakan.getElement(idx2, idx1)->getName() << " untuk diberi makan" << endl;
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
        if (slot2.length() < 3 || slot2.length() > 3)
        {
            throw InvalidIndexMatrixArea();
        }
        else if (idx3 > this->inventory.getRows() || idx4 > this->inventory.getCols())
        {
            throw InvalidIndexMatrixArea();
        }
        else
        {
            Product *temp = new Product;
            temp = dynamic_cast<Product *>(this->inventory.getElement(idx4, idx3));
            // if (temp->fromHewan())
            // {
            //     isValid = true;
            // }
            // else
            // {
            //     cout << "Itu bukanlah pangan yang dapat diberi pada hewan" << endl;
            // }
            if (this->ternakan.getElement(idx2, idx1)->getType() == "CARNIVORE")
            {
                if (temp->fromHewan())
                {
                    isValid = true;
                }
                else
                {
                    throw InvalidCarnivore();
                }
            }

            else if (this->ternakan.getElement(idx2, idx1)->getType() == "HERBIVORE")
            {
                if (!temp->fromHewan())
                {
                    isValid = true;
                }
                else
                {
                    throw InvalidHerbivore();
                }
            }

            else
            {
                isValid = true;
            }
        }
    }

    int idx3 = slot2[0] - 'A' + 1;
    int idx4 = std::stoi(slot2.substr(1));
    Product *temp = new Product;
    temp = dynamic_cast<Product *>(this->inventory.getElement(idx4, idx3));

    this->ternakan.getElement(idx2, idx1)->makan(*temp);
    this->inventory.deleteElement(idx4, idx3);
    cout << this->ternakan.getElement(idx2, idx1)->getName() << " sudah diberi makan dan beratnya menjadi " << this->ternakan.getElement(idx2, idx1)->getCurWeight() << endl;

    // Output Hasil
}

void Peternak::panenTernak()
{
    try
    {
        this->cetakTernak();
        vector<string> ownedHew;
        vector<string> ownedHewName;
        vector<string> readyPanen;
        vector<int> readyPanenAmt;

        for (int i = 1; i < this->ternakan.getRows() + 1; i++)
        {
            for (int j = 1; j < this->ternakan.getCols() + 1; j++)
            {
                if (this->ternakan.getElement(i, j) != nullptr)
                {
                    if (this->ternakan.getElement(i, j)->getTipeObject() == "HEWAN")
                    {
                        bool found = false;
                        size_t it = 0;
                        while (it < ownedHew.size())
                        {
                            if (ownedHew[it] == this->ternakan.getElement(i, j)->getKode())
                            {
                                found = true;
                                it = ownedHew.size() + 1;
                            }
                            it++;
                        }

                        if (!found)
                        {
                            ownedHew.push_back(this->ternakan.getElement(i, j)->getKode());
                            ownedHewName.push_back(this->ternakan.getElement(i, j)->getName());
                        }
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

            for (int j = 1; j < this->ternakan.getRows() + 1; j++)
            {
                for (int k = 1; k < this->ternakan.getCols() + 1; k++)
                {
                    if (this->ternakan.getElement(j, k) != nullptr)
                    {
                        if (this->ternakan.getElement(j, k)->getKode() == ownedHew[i])
                        {
                            if (this->ternakan.getElement(j, k)->isHarvestable())
                            {
                                count += 1;
                                bool found = false;
                                size_t it = 0;
                                while (it < readyPanen.size())
                                {
                                    if (readyPanen[it] == this->ternakan.getElement(i, j)->getKode())
                                    {
                                        found = true;
                                        it = readyPanen.size() + 1;
                                    }
                                    it++;
                                }
                                if (found)
                                {
                                    readyPanen.push_back(this->ternakan.getElement(j, k)->getKode());
                                }
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

        if (readyPanen.size() > 0)
        {
            while (!isValid)
            {
                cout << "Nomor hewan yang ingin dipanen: ";
                cin >> maupanen;
                cout << endl;
                // Validasi
                if (maupanen > readyPanen.size() || maupanen < 0)
                {
                    throw InvalidPanenIdx();
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
                    throw InvalidInventorySpace();
                }
                else if (brppanen > readyPanenAmt[maupanen - 1])
                {
                    throw InvalidPanenAmountOver();
                }
                else if (brppanen < 1)
                {
                    throw InvalidPanenAmount();
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
                        throw InvalidIndexMatrixArea();
                    }
                    else if (idx1 > this->ternakan.getRows() || idx2 > this->ternakan.getCols())
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else
                    {
                        if (this->ternakan.getElement(idx2, idx1) != nullptr)
                        {
                            if (this->ternakan.getElement(idx2, idx1)->getKode() != readyPanen[maupanen - 1])
                            {
                                throw InvalidAnimalChoice();
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
                    // Validasi want, kalau valid wants.push_back(want);
                }
                wants.push_back(want);
            }

            for (int i = 0; i < wants.size(); i++)
            {
                int idx1 = wants[i][0] - 'A' + 1;
                int idx2 = std::stoi(wants[i].substr(1));
                int j = 1;
                int k = 1;
                while (j < this->ternakan.getRows() + 1)
                {
                    while (k < this->ternakan.getCols() + 1)
                    {
                        if (this->inventory.getElement(j, k) == nullptr)
                        {
                            vector<Product *> temp = this->ternakan.getElement(idx2, idx1)->hasilPanen();
                            for (int n = 0; n < temp.size(); n++)
                            {
                                this->inventory.setElement(j, k, temp[i]);
                                if (n < temp.size() - 1)
                                {
                                    if (k == this->ternakan.getCols() - 1)
                                    {
                                        j++;
                                        k = 1;
                                    }
                                    else if (j == this->ternakan.getRows() - 1)
                                    {
                                        throw FullInv();
                                    }
                                    else
                                    {
                                        k++;
                                    }
                                }
                                // boleh kalau j dan k udah max exception ga ada slot lagi
                            }

                            this->ternakan.deleteElement(idx2, idx1);
                        }
                        k++;
                    }
                    j++;
                }
            }

            cout << "Panen Berhasil" << endl;
        }
        else
        {
            throw NoHarvestableAnimal();
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

int Peternak::calculateKKP()
{
    return 0;
}

int Peternak::calculateTax()
{
    return 0;
}