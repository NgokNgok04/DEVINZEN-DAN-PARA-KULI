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
#include <filesystem>
#include <fstream>
#include <sstream>
#include "../Header/helper.hpp"

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
}

void GameManager::Debug()
{
    cout << this->winningMoney << "\n";
    cout << this->winningWeight << "\n";
    cout << this->storageSize.first << " " << this->storageSize.second << "\n";
    cout << this->farmSize.first << " " << this->farmSize.second << "\n";
    cout << this->fieldSize.first << " " << this->fieldSize.second << "\n";
}

void GameManager::insertNewPlayer(Pemain *newPlayer)
{
    this->playerList.push_back(newPlayer);

    this->playerAmount++;

    if (this->playerAmount > 1)
    { // geser pemain yang baru dimasukkan supaya terurut otomatis
        Pemain *P1 = nullptr;
        Pemain *P2 = nullptr;
        int i = this->playerAmount - 1;
        while (i - 1 >= 0)
        {
            P1 = this->playerList[i];
            P2 = this->playerList[i - 1];

            if (*P1 < *P2)
            {
                this->playerList[i] = P2;
                this->playerList[i - 1] = P1;
            }
            else
            {
                break;
            }
            i--;
        }
    }
    // cout<<"22"<<endl;
}

void GameManager::PlayerDebug()
{
    for (int i = 0; i < this->playerList.size(); i++)
    {
        cout << this->playerList[i]->getUsername() << "\n";
    }
}

void GameManager::Next()
{
    if(checkWinner()){
        return;
    }
    for(int i=0;i<playerAmount;i++){
        if(playerList[i]->getTipe()=="Petani"){
            Petani* temp = dynamic_cast<Petani*>(playerList[i]);
            temp->tambahUmurTanaman();
        }
    }
    this->rotatePlayer();
    cout<<"Sekarang giliran "<<getCurrentPlayer()->getUsername()<<" - "<<getCurrentPlayer()->getTipe()<<"!\n";
}

Pemain *GameManager::getWinner()
{
    return this->Winner;
}

string GameManager::getWinnerName()
{
    Pemain *winner = this->getWinner();
    return winner->getUsername();
}

// TODO: UNCOMMENT THIS METHOD BELOW AFTER MERGING
bool GameManager::checkWinner()
{

    Pemain *currentPlayer = this->getCurrentPlayer();
    if (currentPlayer->getBeratBadan() >= this->winningWeight && currentPlayer->getGulden() >= this->winningMoney)
    {
        // SYARAT MENANG: BERAT PEMAIN >= BERAT MINIMUM UNTUK MENANG DAN BANYAK GULDEN >= GULDEN UNTUK MENANG
        this->Winner = currentPlayer;
        return true;
    }
    return false;
}

// TODO: UNCOMMENT THIS METHOD ABOVE AFTER MERGING

Pemain *GameManager::getCurrentPlayer()
{
    return this->playerList[this->currentPlayerIndex];
}

string GameManager::getCurrentPlayerName()
{
    Pemain *P = this->getCurrentPlayer();
    return P->getUsername();
}

void GameManager::clearPlayerList()
{
    for (auto it = this->playerList.begin(); it != this->playerList.end(); it++)
    {
        delete *it;
    }
    this->playerList.clear();
}

vector<Pemain *> GameManager::getPlayerList()
{
    return this->playerList;
}

string intToLetter(int num)
{
    std::string result;
    while (num > 0)
    {
        int remainder = (num - 1) % 26;
        char letter = 'A' + remainder;
        result = letter + result;
        num = (num - 1) / 26;
    }
    return result;
}

string convertCoorToCode(int row, int col)
{
    string res = "";
    res += intToLetter(col);
    if (row < 10)
    {
        res += "0";
    }
    res += to_string(row);
    return res;
}

void simpanHewan(ofstream &out, Hewan &h, int row, int col)
{
    out << convertCoorToCode(row, col) << " " << h.getName() << " " << h.getCurWeight() << endl;
}

void simpanTanaman(ofstream &out, Tanaman &t, int row, int col)
{
    out << convertCoorToCode(row, col) << " " << t.getName() << " " << t.getCurAge() << endl;
}


void simpanMatrixArea(ofstream &out, MatrixArea<GameObject> &mtrx)
{
    int jmlhItem = mtrx.getRows() * mtrx.getCols() - mtrx.getEmptySlot();
    out << jmlhItem << endl;
    for (int i = 1; i <= mtrx.getRows(); i++)
    {
        for (int j = 1; j <= mtrx.getCols(); j++)
        {
            GameObject *item = mtrx.getElement(i, j);
            if (item != nullptr)
            {
                out << item->getName() << endl;
            }
        }
    }
}

void simpanMatrixArea(ofstream &out, MatrixArea<Hewan> &ternakan)
{
    int jmlhItem = ternakan.getRows() * ternakan.getCols() - ternakan.getEmptySlot();
    out << jmlhItem << endl;
    for (int i = 1; i <= ternakan.getRows(); i++)
    {
        for (int j = 1; j <= ternakan.getCols(); j++)
        {
            Hewan *hewan = ternakan.getElement(i, j);
            if (hewan != nullptr)
            {
                simpanHewan(out, *hewan, i, j);
            }
        }
    }
}

void simpanMatrixArea(ofstream &out, MatrixArea<Tanaman> &ladang)
{
    int jmlhItem = ladang.getRows() * ladang.getCols() - ladang.getEmptySlot();
    out << jmlhItem << endl;
    for (int i = 1; i <= ladang.getRows(); i++)
    {
        for (int j = 1; j <= ladang.getCols(); j++)
        {
            Tanaman *tanaman = ladang.getElement(i, j);
            if (tanaman != nullptr)
            {
                simpanTanaman(out, *tanaman, i, j);
            }
        }
    }
}

void simpanPemain(ofstream &out,Pemain &p){
    out <<p.getUsername()<<" "<<p.getTipe()<<" "<<p.getBeratBadan()
        <<" "<<p.getGulden()<<endl;
    simpanMatrixArea(out,p.getInventory());
    if(p.getTipe()=="Petani"){
        Petani& petani = dynamic_cast<Petani&>(p);
        simpanMatrixArea(out,petani.getLadang());
    }else if(p.getTipe()=="Peternak"){
        Peternak& peternak = dynamic_cast<Peternak&>(p);
        simpanMatrixArea(out,peternak.getTernakan());
    }
}

void simpanToko(ofstream &out){
    int jmlhItem = Toko::getTotalReady();
    out<<jmlhItem<<endl;
    for(int i=0;i<Toko::getAvailableProductSize();i++){
        pair<Product,int> produk = *Toko::getPairProductInt(i);
        if(produk.second!=0){
            out<<produk.first.getName()<<" "<<produk.second<<endl;
        }
    }
    for(int i=0;i<Toko::getAvailableBangunanSize();i++){
        pair<Bangunan,int> bangunan = *Toko::getPairBangunanInt(i);
        if(bangunan.second !=0){
            out<<bangunan.first.getName()<<" "<<bangunan.second<<endl;
        }
    }
}

void GameManager::simpan()
{
    namespace fs = filesystem;
    bool isValid = false;
    while (!isValid)
    {
        try
        {
            string path;
            cout<<"Masukkan lokasi berkas state: ";
            cin>>path;
            string dir = path.substr(0,path.find_last_of("/\\"));
            if(!fs::exists(dir) || !fs::is_directory(dir)){
                throw InvalidDirSimpan();
            }
            isValid = true;
            ofstream outf(path);
            if (outf.is_open())
            {
                outf << playerList.size() << endl;
                for (int i = 0; i < playerList.size(); i++)
                {
                    simpanPemain(outf, *playerList[i]);
                }
                simpanToko(outf);
            }
        }catch(BaseException &b){
            cout<<b.what()<<endl;
        }
    }
}

void removeNewline(string &str) {
    size_t pos = str.find('\n');

    while (pos != string::npos) {
        str.erase(pos, 1);
        pos = str.find('\n', pos);
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<GameObject> &inven){
    string fullLine;
    getline(infile, fullLine);
    int jmlhItem = stoi(fullLine);
    for(int i=0;i<jmlhItem;i++){
        getline(infile,fullLine);
        removeNewline(fullLine);
        cout<<fullLine<<" "<<fullLine.length()<<endl;
        int id;
        GameObject* temp = nullptr;
        if(ParserHewan::convertNameToID(fullLine)!=-1){
            id = ParserHewan::convertNameToID(fullLine);
            // cout<<fullLine<<" HEWAN"<<endl;
            temp = new Hewan(id);
        }
        else if (ParserTanaman::convertNameToID(fullLine) != -1)
        {
            id = ParserTanaman::convertNameToID(fullLine);
            // cout<<fullLine<<" TANAMAN"<<endl;
            temp = new Tanaman(id);
        }
        else if (ParserProduk::convertNameToID(fullLine) != -1)
        {
            id = ParserProduk::convertNameToID(fullLine);
            // cout<<fullLine<<" PRODUK"<<endl;
            bool isFromHewan=true;
            if(ParserHewan::convertNameToID(ParserProduk::getOrigin(id))==-1){
                isFromHewan = false;
            }
            temp = new Product(id, isFromHewan);
        }
        else
        {
            id = ParserResep::convertNameToID(fullLine);
            // cout<<fullLine<<" BANGUNAN"<<endl;
            temp = new Bangunan(id);
        }
        inven + temp;
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<Hewan> &ternakan){
    string fullLine;
    getline(infile, fullLine, '\n');
    int jmlhItem = stoi(fullLine);
    for (int i = 0; i < jmlhItem; i++)
    {
        getline(infile, fullLine);
        vector<string> line = StringToStringList(fullLine);
        pair<int, int> coor = ternakan.getPositionFromSlot(line[0]);
        Hewan *temp = new Hewan(ParserHewan::convertNameToID(line[1]));
        temp->setWeight(stoi(line[2]));
        ternakan.setElement(coor.first, coor.second, temp);
    }
}

void muatMatrixArea(ifstream& infile,MatrixArea<Tanaman> &ladang,vector<Tanaman*> &dt){
    string fullLine;
    getline(infile, fullLine, '\n');
    int jmlhItem = stoi(fullLine);
    for (int i = 0; i < jmlhItem; i++)
    {
        getline(infile, fullLine);
        vector<string> line = StringToStringList(fullLine);
        pair<int, int> coor = ladang.getPositionFromSlot(line[0]);
        Tanaman *temp = new Tanaman(ParserTanaman::convertNameToID(line[1]));
        temp->setAge(stoi(line[2]));
        dt.push_back(temp);
        ladang.setElement(coor.first, coor.second, temp);
    }
}

void muatToko(ifstream &infile)
{
    string fullLine;
    getline(infile, fullLine, '\n');
    int jmlhItem = stoi(fullLine);
    for (int i = 0; i < jmlhItem; i++)
    {
        getline(infile, fullLine);
        vector<string> line = StringToStringList(fullLine);
        if (ParserProduk::convertNameToID(line[0]) != -1)
        {
            int id = ParserProduk::convertNameToID(line[0]);
            bool isFromHewan = true;
            if (ParserHewan::convertNameToID(ParserProduk::getOrigin(id)) == -1)
            {
                isFromHewan = false;
            }
            Product temp(ParserProduk::convertNameToID(line[0]),isFromHewan);
            Toko::itemDijual(&temp,stoi(line[1]));
        }else{
            int id = ParserResep::convertNameToID(line[0]);
            Bangunan temp(id);
            Toko::itemDijual(&temp,stoi(line[1]));
        }
    }
}

void GameManager::muat()
{
    string pathstr;
    bool isValid = false;
    namespace fs = std::filesystem;
    while (!isValid)
    {
        try
        {
            cout << "Masukkan lokasi berkas state: ";
            cin >> pathstr;
            fs::path pathObj(pathstr);
            if (!fs::exists(pathObj))
            {
                throw InvalidPathMuat();
            }
            isValid = true;
        }
        catch (BaseException &e)
        {
            cout << e.what() << endl;
        }
    }
    ifstream infile(pathstr);
    if (infile.is_open())
    {
        string fullLine;
        vector<string> line;
        getline(infile,fullLine,'\n');
        // cout<<fullLine<<endl;
        int nPlayer = stoi(fullLine);
        // cout<<playerAmount<<endl;
        for(int i=0;i<nPlayer;i++){
            getline(infile,fullLine);
            line = StringToStringList(fullLine);
            
            if(line[1]=="Peternak"){
                Peternak* temp = new Peternak(line[0],stoi(line[3]),stoi(line[2]));
                insertNewPlayer(temp);
                muatMatrixArea(infile,temp->getInventory());
                muatMatrixArea(infile,temp->getTernakan());
                // cout<<temp->getUsername()<<endl;
            }else if(line[1]=="Petani"){
                Petani* temp = new Petani(line[0],stoi(line[3]),stoi(line[2]));
                insertNewPlayer(temp);
                muatMatrixArea(infile,temp->getInventory());
                muatMatrixArea(infile,temp->getLadang(),temp->getDaftarTanaman());
            }else{
                WaliKota* temp = new WaliKota(line[0],stoi(line[3]),stoi(line[2]));
                insertNewPlayer(temp);
                muatMatrixArea(infile,temp->getInventory());
            }
        }
        muatToko(infile);
    }
}

void GameManager::setupGame()
{
     cout << "\n▓█████▄ ▓█████ ██▒   █▓ ██▓ ███▄    █ ▒███████▒▓█████  ███▄    █" << endl;
    cout << "▒██▀ ██▌▓█   ▀▓██░   █▒▓██▒ ██ ▀█   █ ▒ ▒ ▒ ▄▀░▓█   ▀  ██ ▀█   █" << endl;
    cout << "░██   █▌▒███   ▓██  █▒░▒██▒▓██  ▀█ ██▒░ ▒ ▄▀▒░ ▒███   ▓██  ▀█ ██▒" << endl;
    cout << "░▓█▄   ▌▒▓█  ▄  ▒██ █░░░██░▓██▒  ▐▌██▒  ▄▀▒   ░▒▓█  ▄ ▓██▒  ▐▌██▒" << endl;
    cout << "░▒████▓ ░▒████▒  ▒▀█░  ░██░▒██░   ▓██░▒███████▒░▒████▒▒██░   ▓██░" << endl;
    cout << "▒▒▓  ▒ ░░ ▒░ ░  ░ ▐░  ░▓  ░ ▒░   ▒ ▒ ░▒▒ ▓░▒░▒░░ ▒░ ░░ ▒░   ▒ ▒"  << endl;
    cout << "░ ▒  ▒  ░ ░  ░  ░ ░░   ▒ ░░ ░░   ░ ▒░░░▒ ▒ ░ ▒ ░ ░  ░░ ░░   ░ ▒░" << endl;
    cout << "░ ░  ░    ░       ░░   ▒ ░   ░   ░ ░ ░ ░ ░ ░ ░   ░      ░   ░ ░" << endl;
    cout << "░       ░  ░     ░   ░           ░   ░ ░       ░  ░         ░" << endl;
    cout << "░                 ░                  ░                        DAN PARA KULI" << endl;
    cout << "Selamat datang di permainan Mengelola Kerajaan! Silakan input pilihan angka di bawah ini untuk mulai bermain:\n";
    cout << "1. Mulai dari permainan baru\n";
    cout << "2. Mulai dari memuat file save\n";

    string choice;
    while (true)
    {
        cout << "> ";
        cin >> choice;
        if (choice == "1")
        {
            cout << "Membuat game baru...\n";
            Petani *petani1 = new Petani();
            Peternak *peternak1 = new Peternak();
            WaliKota *walikota = new WaliKota();
            Pemain *P1 = petani1;
            Pemain *P2 = peternak1;
            Pemain *P3 = walikota;
            insertNewPlayer(P3);
            insertNewPlayer(P2);
            insertNewPlayer(P1);
            playerAmount = 3;
            break;
        }
        else if (choice == "2")
        {
            cout << "Membuka Save file\n";
            muat();
            break;
        }
        else
        {
            cout << "Pilihan tidak valid! Silakan input ulang.\n";
        }
    }
    currentPlayerIndex = 0;
}

void GameManager::prosesInput(string command){
    Pemain* curPlayer = getCurrentPlayer();
    if(command=="NEXT"){
        Next();
    }
    else if (command == "CETAK_PENYIMPANAN")
    {
        curPlayer->cetakPenyimpanan();
    }
    else if (command == "MAKAN")
    {
        curPlayer->makan();
    }
    else if (command == "BELI")
    {
        curPlayer->beli();
    }
    else if (command == "JUAL")
    {
        curPlayer->jual();
    }else if(command=="SIMPAN"){
        simpan();
    }else{
        try{
            if(curPlayer->getTipe()=="Petani"){
                Petani* temp = dynamic_cast<Petani*>(curPlayer);
                if(command=="CETAK_LADANG"){
                    temp->cetakLadang();
                }
                else if (command == "TANAM")
                {
                    temp->tanam();
                }
                else if (command == "PANEN")
                {
                    temp->panenTani();
                }
                else
                {
                    throw InvalidCommand();
                }
            }else if(curPlayer->getTipe()=="Peternak"){
                Peternak* temp = dynamic_cast<Peternak*>(curPlayer);
                if(command=="CETAK_PETERNAKAN"){
                    temp->cetakTernak();
                }
                else if (command == "TERNAK")
                {
                    temp->ternak();
                }
                else if (command == "KASIH_MAKAN")
                {
                    temp->kasihMakan();
                }
                else if (command == "PANEN")
                {
                    temp->panenTernak();
                }
                else
                {
                    throw InvalidCommand();
                }
            }else{
                WaliKota *temp = dynamic_cast<WaliKota *>(curPlayer);
                if (command == "PUNGUT_PAJAK")
                {
                    temp->pungutPajak(this->playerList);
                }
                else if (command == "BANGUN")
                {
                    temp->bangunBangunan();
                }
                else if (command == "TAMBAH_PEMAIN")
                {
                    temp->tambahPemain(this->playerList,this->playerAmount,this->currentPlayerIndex,this->getCurrentPlayer());
                }
                else
                {
                    throw InvalidCommand();
                }
        }
        }catch(BaseException &e){
            cout<<e.what()<<endl;
        }
    }
}