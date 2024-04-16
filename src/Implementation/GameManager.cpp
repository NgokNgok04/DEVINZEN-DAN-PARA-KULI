// #include "../Header/GameManager.hpp"

// GameManager::GameManager(ParserMisc PM)
// {
//     this->winningMoney = PM.getWinningMoney();
//     this->winningWeight = PM.getWinningWeight();
//     this->storageSize = PM.getStorageSize();
//     this->farmSize = PM.getFarmSize();
//     this->fieldSize = PM.getFieldSize();
//     cout<<"Data konfigurasi misc berhasil dimuat!\n";
// }

// void GameManager::Debug()
// {
//     cout<<this->winningMoney<<"\n";
//     cout<<this->winningWeight<<"\n";
//     cout<<this->storageSize.first<<" "<<this->storageSize.second<<"\n";
//     cout<<this->farmSize.first<<" "<<this->farmSize.second<<"\n";
//     cout<<this->fieldSize.first<<" "<<this->fieldSize.second<<"\n";
// }

#include "../Header/GameManager.hpp"
// #include "GameManager.hpp"

void GameManager::rotatePlayer()
{
    if (this->currentPlayerIndex == this->playerAmount - 1)
    { // kembali ke awal jika sudah di ujung akhir
        this->currentPlayerIndex = 0;
    }
    else
    {
        this->currentPlayerIndex++;
    }
}

#include <filesystem>
#include <fstream>
#include <sstream>
#include "../Header/helper.hpp"
void GameManager::rotatePlayer()
{
    if(this->currentPlayerIndex == this->playerAmount-1){ //kembali ke awal jika sudah di ujung akhir
        this->currentPlayerIndex = 0;
    } else {
        this->currentPlayerIndex++;
    }
}

GameManager::GameManager(ParserMisc PM)
{
    this->winningMoney = PM.getWinningMoney();
    this->winningWeight = PM.getWinningWeight();
    this->storageSize = PM.getStorageSize();
    this->farmSize = PM.getFarmSize();
    this->fieldSize = PM.getFieldSize();
    this->playerAmount = 0;
    this->Winner = nullptr;
    this->currentPlayerIndex = 0;
    cout<<"Data konfigurasi misc berhasil dimuat!\n";
}

void GameManager::Debug()
{
    cout << this->winningMoney << "\n";
    cout << this->winningWeight << "\n";
    cout << this->storageSize.first << " " << this->storageSize.second << "\n";
    cout << this->farmSize.first << " " << this->farmSize.second << "\n";
    cout << this->fieldSize.first << " " << this->fieldSize.second << "\n";
}

void GameManager::insertNewPlayer(Pemain * newPlayer)
{
    this->playerList.push_back(newPlayer);
    this->playerAmount++;

    if(this->playerAmount > 1){ //geser pemain yang baru dimasukkan supaya terurut otomatis
        Pemain* P1 = nullptr;
        Pemain* P2 = nullptr;
        int i = this->playerAmount-1;
        while(i-1>=0){
            P1 = this->playerList[i];
            P2 = this->playerList[i-1];

            if(*P1<*P2){
                this->playerList[i] = P2;
                this->playerList[i-1] = P1;
            } else {
                break;
            }
            i--;
        }
    }
}

void GameManager::PlayerDebug()
{
    for(int i = 0; i<this->playerList.size(); i++){
        cout<<this->playerList[i]->getUsername()<<"\n";
    }
}

void GameManager::Next()
{
    this->rotatePlayer();
    //TODO: aging semua tanaman
}

Pemain *GameManager::getWinner()
{
    return this->Winner;
}

string GameManager::getWinnerName()
{
    Pemain* winner = this->getWinner();
    return winner->getUsername();
}

//TODO: UNCOMMENT THIS METHOD BELOW AFTER MERGING
// bool GameManager::checkWinner()
// {

//     Pemain* currentPlayer = this->getCurrentPlayer();
//     if(currentPlayer->getWeight() >= this->winningWeight && currentPlayer->getGulden() >= this->winningMoney){
        //SYARAT MENANG: BERAT PEMAIN >= BERAT MINIMUM UNTUK MENANG DAN BANYAK GULDEN >= GULDEN UNTUK MENANG
//         this->Winner = currentPlayer;
//         return true;
//     }
//     return false;
// }

//TODO: UNCOMMENT THIS METHOD ABOVE AFTER MERGING


Pemain *GameManager::getCurrentPlayer()
{
    return this->playerList[this->currentPlayerIndex];
}

string GameManager::getCurrentPlayerName()
{
    Pemain* P = this->getCurrentPlayer();
    return P->getUsername();
}

void GameManager::clearPlayerList()
{
    for(auto it = this->playerList.begin(); it != this->playerList.end(); it++){
        delete *it;
    }
    this->playerList.clear();
}

vector<Pemain *> GameManager::getPlayerList()
{
    return this->playerList;
}

string intToLetter(int num){
    std::string result;
    while (num > 0) {
        int remainder = (num - 1) % 26;
        char letter = 'A' + remainder;
        result = letter + result;
        num = (num - 1) / 26;
    }
    return result;
}

string convertCoorToCode(int row,int col){
    string res = "";
    res += intToLetter(col);
    if(row<10){
        res+="0";
    }
    res+=to_string(row);
    return res;
}

void simpanHewan(ofstream &out,Hewan &h,int row,int col){
    out<<convertCoorToCode(row,col)<<" "<<h.getName()<<" "<<h.getCurWeight()<<endl;
}

void simpanTanaman(ofstream &out,Tanaman &t,int row,int col){
    out<<convertCoorToCode(row,col)<<" "<<t.getName()<<" "<<t.getCurAge()<<endl;
}

void simpanMatrixArea(ofstream &out,MatrixArea<GameObject> &mtrx){
    int jmlhItem = mtrx.getRows()*mtrx.getCols()-mtrx.getEmptySlot();
    out<<jmlhItem<<endl;
    for(int i=1;i<=mtrx.getRows();i++){
        for(int j=1;j<=mtrx.getCols();j++){
            GameObject* item = mtrx.getElement(i,j);
            if(item!=nullptr){
                out<<item->getName()<<endl;
            }
        }
    }
}

void simpanMatrixArea(ofstream &out,MatrixArea<Hewan> &ternakan){
    int jmlhItem = ternakan.getRows()*ternakan.getCols()-ternakan.getEmptySlot();
    out<<jmlhItem<<endl;
    for(int i=1;i<=ternakan.getRows();i++){
        for(int j=1;j<=ternakan.getCols();j++){
            Hewan* hewan=ternakan.getElement(i,j);
            if(hewan!=nullptr){
                simpanHewan(out,*hewan,i,j);
            }
        }
    }
}

void simpanMatrixArea(ofstream &out,MatrixArea<Tanaman> &ladang){
    int jmlhItem = ladang.getRows()*ladang.getCols()-ladang.getEmptySlot();
    out<<jmlhItem<<endl;
    for(int i=1;i<=ladang.getRows();i++){
        for(int j=1;j<=ladang.getCols();j++){
            Tanaman* tanaman=ladang.getElement(i,j);
            if(tanaman!=nullptr){
                simpanTanaman(out,*tanaman,i,j);
            }
        }
    }
}

void simpanPemain(ofstream &out,Pemain &p){
    out <<p.getUsername()<<" "<<p.getTipe()<<" "<<p.getBeratBadan()
        <<" "<<p.getGulden()<<endl;
    simpanMatrixArea(out,p.getInventory());
    if(p.getTipe()=="petani"){
        Petani& petani = dynamic_cast<Petani&>(p);
        simpanMatrixArea(out,petani.getLadang());
    }else if(p.getTipe()=="peternak"){
        Peternak& peternak = dynamic_cast<Peternak&>(p);
        simpanMatrixArea(out,peternak.getTernakan());
    }
}

void simpanToko(ofstream &out){
    int jmlhItem = Toko::getAvailableProductSize()+Toko::getAvailableBangunanSize();
    out<<jmlhItem<<endl;
    for(int i=0;i<Toko::getAvailableProductSize();i++){
        pair<Product,int> produk = *Toko::getPairProductInt(i);
        out<<produk.first.getName()<<" "<<produk.second<<endl;
    }
    for(int i=0;i<Toko::getAvailableBangunanSize();i++){
        pair<Bangunan,int> bangunan = *Toko::getPairBangunanInt(i);
        out<<bangunan.first.getName()<<" "<<bangunan.second<<endl;
    }
}

void GameManager::simpan(){
    namespace fs = filesystem;
    bool isValid = false;
    while(!isValid){
        try{
            string path;
            cout<<"Masukkan lokasi berkas state: ";
            cin>>path;
            string dir = path.substr(0,path.find_last_of("/\\"));
            if(fs::exists(dir) && fs::is_directory(dir)){
                //throw exception
            }
            isValid = true;
            ofstream outf(path);
            if(outf.is_open()){
                outf<<playerList.size()<<endl;
                for(int i=0;i<playerList.size();i++){
                    simpanPemain(outf,*playerList[i]);
                }
                simpanToko(outf);
            }
        }catch(BaseException &b){
            b.what();
            cout<<endl;
        }
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<GameObject> inven){
    string fullLine;
    getline(infile,fullLine,'\n');
    int jmlhItem = stoi(fullLine);
    for(int i=0;i<jmlhItem;i++){
        getline(infile,fullLine,'\n');
        int id = -1;
        GameObject* temp = nullptr;
        if(ParserHewan::convertNameToID(fullLine)!=-1){
            id = ParserHewan::convertNameToID(fullLine);
            temp = dynamic_cast<GameObject*>(new Hewan(id));
        }else if(ParserTanaman::convertNameToID(fullLine)!=-1){
            id = ParserTanaman::convertNameToID(fullLine);
            temp = dynamic_cast<GameObject*>(new Tanaman(id));
        }else if(ParserProduk::convertNameToID(fullLine)!=-1){
            id = ParserProduk::convertNameToID(fullLine);
            bool isFromHewan=true;
            if(ParserHewan::convertNameToID(ParserProduk::getOrigin(id))==-1){
                isFromHewan = false;
            }
            temp = dynamic_cast<GameObject*>(new Product(id,isFromHewan));
        }else{
            id = ParserResep::convertNameToID(fullLine);
            temp = dynamic_cast<GameObject*>(new Bangunan(id));
        }
        inven+temp;
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<Hewan> ternakan){
    string fullLine;
    getline(infile,fullLine,'\n');
    int jmlhItem = stoi(fullLine);
    for(int i=0;i<jmlhItem;i++){
        getline(infile,fullLine);
        vector<string> line = StringToStringList(fullLine);
        pair<int,int> coor = ternakan.getPositionFromSlot(line[0]);
        Hewan* temp = new Hewan(ParserHewan::convertNameToID(line[1]));
        temp->setWeight(stoi(line[2]));
        ternakan.setElement(coor.first,coor.second,temp);
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<Tanaman> ladang){
    string fullLine;
    getline(infile,fullLine,'\n');
    int jmlhItem = stoi(fullLine);
    for(int i=0;i<jmlhItem;i++){
        getline(infile,fullLine);
        vector<string> line = StringToStringList(fullLine);
        pair<int,int> coor = ladang.getPositionFromSlot(line[0]);
        Tanaman* temp = new Tanaman(ParserTanaman::convertNameToID(line[1]));
        temp->setAge(stoi(line[2]));
        ladang.setElement(coor.first,coor.second,temp);
    }
}

void muatToko(ifstream& infile){
    string fullLine;
    getline(infile,fullLine,'\n');
    int jmlhItem = stoi(fullLine);
    for(int i=0;i<jmlhItem;i++){
        getline(infile,fullLine);
        vector<string> line = StringToStringList(fullLine);
        if(ParserProduk::convertNameToID(line[0])!=-1){
            int id = ParserProduk::convertNameToID(line[0]);
            bool isFromHewan = true;
            if(ParserHewan::convertNameToID(ParserProduk::getOrigin(id))==-1){
                isFromHewan = false;
            }
            Product temp(ParserProduk::convertNameToID(line[0]),isFromHewan);
            Toko::pushProduct(make_pair(temp,stoi(line[1])));
        }else{
            int id = ParserProduk::convertNameToID(line[0]);
            Bangunan temp(id);
            Toko::pushBangunan(make_pair(temp,stoi(line[1])));
        }
    }
}

void GameManager::muat(){
    string pathstr;
    bool isValid = false;
    namespace fs = std::filesystem;
    while(!isValid){
        try{
            cout<<"Masukkan lokasi berkas state: ";
            cin>>pathstr;
            fs::path pathObj(pathstr);
            if(!fs::exists(pathObj)){
                //throw exc
            }
            isValid = true;
        }catch(BaseException &e){
            e.what();
        }
    }
    ifstream infile(pathstr);
    if(infile.is_open()){
        string fullLine;
        vector<string> line;
        getline(infile,fullLine,'\n');
        playerAmount = stoi(fullLine);
        for(int i=0;i<playerAmount;i++){
            getline(infile,fullLine);
            line = StringToStringList(fullLine);
            if(line[1]=="peternak"){
                Peternak* temp = new Peternak(line[0],stoi(line[3]),stoi(line[2]),
                1,1,1,storageSize.first,storageSize.second);
                playerList.push_back(temp);
                muatMatrixArea(infile,temp->getInventory());
                muatMatrixArea(infile,temp->getTernakan());
            }else if(line[1]=="petani"){
                Petani* temp = new Petani(line[0],stoi(line[3]),stoi(line[2]),
                1,1,1,storageSize.first,storageSize.second);
                playerList.push_back(temp);
                muatMatrixArea(infile,temp->getInventory());
                muatMatrixArea(infile,temp->getLadang());
            }else{
                WaliKota* temp = new WaliKota(line[0],stoi(line[3]),stoi(line[2]),1,1,1);
                playerList.push_back(temp);
                muatMatrixArea(infile,temp->getInventory());
            }
        }
        muatToko(infile);
    }
}