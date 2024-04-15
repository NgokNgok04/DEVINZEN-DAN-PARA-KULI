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
    cout << endl << endl;
    int wantToBuy = Toko::buyProcess();
    int subResponse;
    int counterAvailableItem;
    GameObject* itemToBuy = nullptr;
    if (wantToBuy == 1){
        Toko::displayAvailableHewan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableHewan.size() + 1){
            if (subResponse >= 1 && subResponse<= Toko::availableHewan.size()){
                itemToBuy = &Toko::availableHewan[subResponse - 1];
            } else {
                throw InvalidSubResponse();
            }
        }
    } else if (wantToBuy == 2){
        Toko::displayAvailableTanaman();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableTanaman.size() + 1){
            if (subResponse >= 1 && subResponse<= Toko::availableTanaman.size()){
                itemToBuy = &Toko::availableTanaman[subResponse - 1];
            } else {
                throw InvalidSubResponse();
            }
        }
    } else if (wantToBuy == 3 && !Toko::isProductEmptyStock()){
        counterAvailableItem = Toko::displayAvailableProduct();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                for(int i = 0; i < Toko::availableProduct.size(); i++){
                    if (Toko::availableProduct[i].second != 0){
                        count++;
                    }
                    if (subResponse == count){
                        itemToBuy = &Toko::availableProduct[count].first;
                    }
                }
            } else {
                throw InvalidSubResponse();
            }
        }
    } else if (wantToBuy == 3 && !Toko::isBangunanEmptyStock() && Toko::isProductEmptyStock()){
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                bool found = false;
                for(int i = 0; i < Toko::availableBangunan.size(); i++){
                    if (Toko::availableBangunan[i].second != 0){
                        count++;
                    }
                    if (subResponse == count && !found){
                        itemToBuy = &Toko::availableBangunan[count].first;
                        this->ownedBangunan.push_back(Toko::availableBangunan[count].first);
                        found = true;
                    }
                }

            } else {
                throw InvalidSubResponse();
            }
        }
    } else if (wantToBuy == 4 && !Toko::isBangunanEmptyStock){
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                bool found = false;
                for(int i = 0; i < Toko::availableBangunan.size(); i++){
                    if (Toko::availableBangunan[i].second != 0){
                        count++;
                    }
                    if (subResponse == count && !found){
                        itemToBuy = &Toko::availableBangunan[count].first;
                        this->ownedBangunan.push_back(Toko::availableBangunan[count].first);
                        found = true;
                    }
                }
            } else {
                throw InvalidSubResponse();
            }
        }
    }

    if (itemToBuy != nullptr){
        cout << endl;
        cout << "Uang Anda : " << this->gulden << endl;
        this->inventory.displayRemainderSlot();
        cout << endl;

        int quantity;
        cout << "Kuantitas : ";
        cin >> quantity;

        this->gulden -= itemToBuy->getPrice()*quantity;
        try{
            if (quantity > this->inventory.getEmptySlot()){
                this->gulden += itemToBuy->getPrice()*quantity;
                throw InventoryNotEnough();
            }
            int stock = Toko::getStock(itemToBuy->getName());
            if (stock != -1 && stock < quantity){
                this->gulden += itemToBuy->getPrice()*quantity;
                throw StockTokoNotEnough();
            }
            if (this->gulden < 0){
                this->gulden += itemToBuy->getPrice()*quantity;
                throw NotEnoughGulden();
            }
            cout << endl;
            cout << "Selamat Anda berhasil membeli " << quantity <<" " << itemToBuy->getName();
            cout << ". Uang yang tersisa " << this->gulden << "." << endl << endl;

            cout << "Pilih slot untuk menyimpan barang yang anda beli!" << endl;
            this->inventory.displayObject();
            string slot;
            for(int i = 0; i < quantity; i++){
                cout << "Petak slot " << i + 1 <<": ";
                cin >> slot;
                pair<int,int> position;
                try {
                    position = this->inventory.getPositionFromSlot(slot);
                    if (this->inventory.getElement(position.first,position.second) != nullptr){
                        throw SlotFilled();
                    }
                    this->inventory.setElement(position.first,position.second, itemToBuy);
                } catch (InvalidPositionMatrixArea err){
                    err.what();
                    cout << endl;
                } catch (SlotFilled err){
                    err.what();
                    cout << endl;
                }
            }
            cout << itemToBuy->getName() << "berhasil disimpan dalam penyimpanan!" << endl;
            Toko::itemDibeli(itemToBuy,quantity);
        }catch (InventoryNotEnough err){
            err.what();
            cout << endl;
        }catch (StockTokoNotEnough err){
            err.what();
            cout << endl;
        }catch(NotEnoughGulden err){
            err.what();
            cout << endl;
        }
    }
}

void Petani::jual() //perlu catch ItemQuantityToSellNotEnough
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    this->inventory.displayObject();
    int quantity;
    cout << "Masukkan kuantitas barang yang ingin dijual :";
    cin >> quantity;

    if ((quantity - this->ownedBangunan.size()) > ((this->inventory.getCols() * this->inventory.getRows()) - this->inventory.getEmptySlot())){
        throw ItemQuantityToSellNotEnough();
    }

    cout << endl << "Silahkan pilih petak yang ingin anda jual!";
    string slot;
    pair<int,int> position;
    int profit = 0;
    GameObject* itemToSell;
    
    bool isValid;
    for(int i = 0; i < quantity; i++){
        isValid = false;
        while(!isValid){
            cout << "Petak slot " << i + 1 << ": ";
            cin >> slot;

            try{
                position = this->inventory.getPositionFromSlot(slot);
                itemToSell = this->inventory.getElement(position.first, position.second);
                if (itemToSell->getTipeObject() == "BANGUNAN"){
                    throw CantSellBangunan();
                }
                isValid = true;
            } catch (InvalidPositionMatrixArea err){
                err.what();
                cout << endl;
            } catch (CantSellBangunan err){
                err.what();
                cout << endl;
            }
        }

            profit += itemToSell->getPrice();
            this->inventory.deleteElement(position.first, position.second);
    }
    this->gulden += profit;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    Toko::itemDijual(itemToSell,quantity);
}

MatrixArea<Tanaman> Petani::getLadang()
{
    return this->ladang;
}

void Petani::cetakLadang()
{
    this->ladang.displayObject();
    this->ladang.displayRemainderSlot();
}

// EXTRA FUNCTIONS
bool isAllDigits(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
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
        try
        {
            if (slot.length() < 3 || slot.length() > 3)
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx2 > this->inventory.getRows() || idx1 > this->inventory.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->inventory.getElement(idx2, idx1) != nullptr)
                {
                    if (this->inventory.getElement(idx2, idx1)->getTipeObject() != "TANAMAN")
                    {
                        throw InvalidNotTanaman();
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
        try
        {
            if (petak.length() < 3 || petak.length() > 3)
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx4 > this->ladang.getRows() || idx3 > this->ladang.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->ladang.getElement(idx4, idx3) == nullptr)
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
    // Entah kenapa butuh ini
    int idx3 = petak[0] - 'A' + 1;
    int idx4 = std::stoi(petak.substr(1));

    Tanaman *temp = new Tanaman;
    temp = dynamic_cast<Tanaman *>(this->inventory.getElement(idx2, idx1));
    // Hewan *temp2 = static_cast<Hewan *>(this->inventory.getElement(5, 2));
    // cout << typeid(this->inventory.getElement(idx2, idx1)).name() << endl;
    // cout << typeid(temp).name() << endl;
    // cout << typeid(temp2).name() << endl;
    // Tanaman *temp = (Tanaman *)this->inventory.getElement(idx2, idx1);
    if (temp)
    {
        cout << "SUCCC" << endl;
        cout << temp->getKode() << endl;
    }
    else
    {
        cout << "GAGGG" << endl;
    }
    // if (temp2)
    // {
    //     cout << " AAAAAAAAWDDDDDDDDDDDDDDDDDDDD" << endl;
    // }
    // else
    // {
    //     cout << "kok" << endl;
    // }

    this->ladang.setElement(idx4, idx3, temp); // karna tanaman
    this->inventory.deleteElement(idx2, idx1);
    cout << this->ladang.getElement(idx4, idx3)->getKode() << endl;

    cout << "Berhasil ditanam" << endl;
    // this->cetakPenyimpanan();
    // this->cetakLadang();
}

void Petani::panenTani()
{
    if (this->ladang.isEmpty())
    {
        throw NoHarvestablePlant();
    }
    cout << "AWDAWD" << endl;
    try
    {

        if (!this->ladang.isEmpty())
        {
            this->cetakLadang();
            vector<string> ownedTan = {};
            vector<string> ownedTanName = {};
            vector<string> readyPanen = {};
            vector<int> readyPanenAmt = {};

            for (int i = 1; i < this->ladang.getRows() + 1; i++)
            {
                for (int j = 1; j < this->ladang.getCols() + 1; j++)
                {
                    if (this->ladang.getElement(i, j) != nullptr)
                    {

                        cout << this->ladang.getElement(i, j)->getKode() << endl;
                        if (this->ladang.getElement(i, j)->getTipeObject() == "TANAMAN")
                        {

                            bool found = false;
                            int it = 0;
                            while (it < ownedTan.size())
                            {

                                if (ownedTan[it] == this->ladang.getElement(i, j)->getKode())
                                {
                                    found = true;
                                    it = ownedTan.size() + 1;
                                }
                                it++;
                            }

                            if (!found)
                            {
                                string temp1 = this->ladang.getElement(i, j)->getKode();
                                string temp2 = this->ladang.getElement(i, j)->getName();

                                ownedTan.push_back(temp1);
                                ownedTanName.push_back(temp2);

                                // cout << "awdasdwdasdawd" << endl;
                                // this->cetakLadang();
                            }
                        }
                    }
                }
            }
            cout << " BATAS " << endl;
            // this->cetakLadang();
            cout << this->ladang.getElement(5, 4)->getKode() << endl;

            // Output tanaman yang ada
            for (size_t i = 0; i < ownedTan.size(); ++i)
            {
                cout << ownedTan[i] << " - " << ownedTanName[i] << endl;
            }

            // Output pilihan tanaman berdasarkan siap panennnya
            for (size_t i = 0; i < ownedTan.size(); ++i)
            {
                int count = 0;
                int num = 1;

                for (int j = 1; j < this->ladang.getRows(); j++)
                {
                    for (int k = 1; k < this->ladang.getCols(); k++)
                    {
                        if (this->ladang.getElement(j, k) != nullptr)
                        {
                            cout << this->ladang.getElement(j, k)->getKode() << endl;
                            if (this->ladang.getElement(j, k)->getKode() == ownedTan[i])
                            {
                                if (this->ladang.getElement(j, k)->isHarvestable())
                                {
                                    count += 1;
                                    bool found = false;
                                    size_t it = 0;

                                    while (it < readyPanen.size())
                                    {
                                        if (readyPanen[it] == this->ladang.getElement(i, j)->getKode())
                                        {
                                            found = true;
                                            it = readyPanen.size() + 1;
                                        }
                                        it++;
                                    }
                                    if (!found)
                                    {
                                        cout << this->ladang.getElement(j, k)->getKode() << endl;
                                        cout << "-----------------" << endl;
                                        string temp = this->ladang.getElement(j, k)->getKode();
                                        readyPanen.push_back(temp);
                                        cout << this->ladang.getElement(j, k)->getKode() << endl;
                                    }
                                    cout << "-------adwada----------" << endl;
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
                cout << i + 1 << ". " << readyPanen[i] << " (" << readyPanenAmt[i] << ")" << endl;
            }

            bool isValid = false;
            string maupanen;
            int maupanenint;

            if (readyPanen.size() > 0)
            {
                cout << this->ladang.getElement(5, 4)->getKode() << endl;

                while (!isValid)
                {
                    try
                    {
                        cout << "Nomor tanaman yang ingin dipanen: ";
                        cin >> maupanen;
                        cout << endl;

                        if (!isAllDigits(maupanen))
                        {
                            throw InvalidPanenIdx();
                        }
                        else
                        {
                            maupanenint = std::stoi(maupanen);

                            if (maupanenint > readyPanen.size() || maupanenint < 0)
                            {
                                throw InvalidPanenIdx();
                            }
                            else
                            {
                                isValid = true;
                            }
                        }
                    }
                    catch (BaseException &e)
                    {
                        cout << e.what() << endl;
                    }
                }

                isValid = false;
                string brppanen;
                int brppanenint;
                while (!isValid)
                {
                    try
                    {
                        cout << "Berapa petak yang ingin dipanen: ";
                        cin >> brppanen;
                        cout << endl;
                        if (!isAllDigits(brppanen))
                        {
                            throw InvalidPanenIdx();
                        }
                        else
                        {
                            brppanenint = std::stoi(brppanen);
                            if (brppanenint > this->inventory.getEmptySlot())
                            {
                                throw InvalidInventorySpace();
                            }
                            else if (brppanenint > readyPanenAmt[maupanenint - 1])
                            {
                                throw InvalidPanenAmountOver();
                            }
                            else if (brppanenint < 1)
                            {
                                throw InvalidPanenAmount();
                            }
                            else
                            {
                                isValid = true;
                            }
                        }
                        // Validasi
                        // if tidak valid ada output
                    }
                    catch (BaseException &e)
                    {
                        cout << e.what() << endl;
                    }
                }

                int i = 0;
                string want;
                vector<string> wants;
                cout << "Pilih petak yang ingin dipanen: " << endl;
                for (i; i < brppanenint; i++)
                {
                    isValid = false;
                    while (!isValid)
                    {
                        try
                        {
                            cout << "Petak ke-" << i + 1 << ": ";
                            cin >> want;
                            int idx1 = want[0] - 'A' + 1;
                            int idx2 = std::stoi(want.substr(1));
                            cout << idx2 << idx1 << endl;
                            if (want.length() < 3 || want.length() > 3)
                            {
                                throw InvalidIndexMatrixArea();
                            }
                            else if (idx2 > this->ladang.getRows() || idx1 > this->ladang.getCols())
                            {
                                throw InvalidIndexMatrixArea();
                            }
                            else
                            {
                                if (this->ladang.getElement(idx2, idx1) != nullptr)
                                {
                                    cout << "a" << endl;
                                    cout << this->ladang.getElement(idx2, idx1)->getKode() << endl;
                                    if (this->ladang.getElement(idx2, idx1)->getKode() != readyPanen[maupanenint - 1])
                                    {
                                        cout << "b" << endl;
                                        throw InvalidPlantChoice();
                                    }
                                    else
                                    {
                                        cout << "c" << endl;
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
                        // Validasi want, kalau valid wants.push_back(want);
                    }
                    wants.push_back(want);
                }

                cout << "WS" << wants.size() << endl;
                for (int i = 0; i < wants.size(); i++)
                {

                    bool foundslot = false;

                    int idx1 = wants[i][0] - 'A' + 1;
                    int idx2 = std::stoi(wants[i].substr(1));
                    for (int j = 1; j < this->inventory.getRows() + 1; j++)
                    {
                        for (int k = 1; k < this->inventory.getCols() + 1; k++)
                        {
                            if (this->inventory.getElement(j, k) == nullptr)
                            {
                                // cout << this->ladang.getElement(idx2, idx1)->hasilPanen()->getName() << endl;
                                // cout<<"PEPEK"<<endl;
                                // cout << this->ladang.getElement(idx2, idx1)->hasilPanen()->getName() << endl;
                                this->inventory.setElement(j, k, this->ladang.getElement(idx2, idx1)->hasilPanen());
                                // this->setInv(j, k, this->ladang.getElement(idx2, idx1)->hasilPanen());
                                cout << this->inventory.getElement(j, k)->getName() << endl;
                                cout<<"KONTOL"<<endl;
                                cout << this->inventory.getElement(1, 1)->getName() << endl;

                                this->ladang.deleteElement(idx2, idx1);
                                foundslot = true;
                                break;
                            }
                        }
                        if (foundslot)
                        {
                            cout<<"TESKTN"<<endl;
                            break;
                        }
                    }
                }
                cout << this->inventory.getElement(1, 1)->getName() << endl;
                cout << "Panen Berhasil" << endl;
                this->cetakPenyimpanan();
            }
        }

        else
        {
            throw NoHarvestablePlant();
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

int Petani::countKekayaanLadang(){
    int sum=0;
    for(int i=1;i<ladang.getRows();i++){
        for(int j=1;j<ladang.getCols();j++){
            Tanaman* ptr = ladang.getElement(i,j);
            if(ptr!=nullptr){
                sum+=ptr->getPrice();
            }
        }
    }
    return sum;
}

float Petani::calculateTax()
{   
    int KKP = countKekayaanInven()+countKekayaanLadang()-KTKP_PETANI;
    cout<<KKP<<endl;
    return getTaxRate(KKP)*KKP;
}