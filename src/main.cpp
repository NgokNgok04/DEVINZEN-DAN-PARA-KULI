#include <iostream>

#include "./Header/GameManager.hpp"
#include "./Header/Hewan.hpp"
#include "./Header/Tanaman.hpp"
#include "./Header/Product.hpp"
#include "./Header/Bangunan.hpp"
#include "./Header/Toko.hpp"
using namespace std;

int main(){
    ParserHewan PH;
    ParserMisc PM;
    ParserTanaman PT;
    ParserProduk PP;
    ParserResep PR;
    string animalConfigDirectory = "./config/animal.txt";
    string miscConfigDirectory = "./config/misc.txt";
    string plantConfigDirectory = "./config/plant.txt";
    string productConfigDirectory = "./config/product.txt";
    string recipeConfigDirectory = "./config/recipe.txt";
    try{
        PH.ParseFile(animalConfigDirectory);
        PM.ParseFile(miscConfigDirectory);
        PT.ParseFile(plantConfigDirectory);
        PP.ParseFile(productConfigDirectory);
        PR.ParseFile(recipeConfigDirectory);
    } catch (BaseException &e){
        cout<<e.what()<<"\n";
        return 0;
    }

    GameManager gameManager(PM);

    // gameManager.Debug();

    cout<<"Selamat datang di permainan Mengelola Kerajaan! Silakan input pilihan angka di bawah ini untuk mulai bermain:\n";
    cout<<"1. Mulai dari permainan baru\n";
    cout<<"2. Mulai dari memuat file save\n";

    
    int choice;
    while(true){
        cout<<">";
        cin>>choice;
        if(choice == 1){
            cout<<"Membuat game baru...\n";
            //Inisialisasi pemain default
            Petani* petani1 = new Petani();
            Peternak* peternak1 = new Peternak();
            WaliKota* walikota = new WaliKota();
            Pemain* P1 = petani1;
            Pemain* P2 = peternak1;
            Pemain* P3 = walikota;
            gameManager.insertNewPlayer(P3);
            gameManager.insertNewPlayer(P2);
            gameManager.insertNewPlayer(P1);
            break;
        } else if(choice == 2){
            cout<<"Membuka Save file\n";
            break;
        } else {
            cout<<"Pilihan tidak valid! Silakan input ulang.\n";
        }
    }
    gameManager.PlayerDebug(); //untuk debug pemain
    cout<<"Setup permainan selesai, permainan dimulai!\n";
    string command;
    while(true){
        cout<<"Sekarang giliran "<<gameManager.getCurrentPlayerName()<<"!\n";
        
        Pemain* currentPlayer = gameManager.getCurrentPlayer();
        Petani* currentPetani = nullptr;
        Peternak* currentPeternak = nullptr;
        WaliKota* currentWalikota = nullptr;
        if(currentPlayer->getTipe() == "petani"){
            // cout<<"Ini adalah petani\n";
            currentPetani = dynamic_cast<Petani*>(currentPlayer);
            // currentPetani->cetakLadang();
        } else if(currentPlayer->getTipe() == "peternak"){
            // cout<<"Ini adalah peternak\n";
            currentPeternak = dynamic_cast<Peternak*>(currentPlayer);
            // currentPeternak->cetakTernak();
        } else if(currentPlayer->getTipe() == "walikota"){
            // cout<<"Ini adalah peternak\n";
            currentWalikota = dynamic_cast<WaliKota*>(currentPlayer);
            // currentWalikota->cetakPenyimpanan();
        }
        cout<<"Silakan input perintah:\n";
        cout<<"> ";

        cin>>command;
        if(command == "NEXT"){
            gameManager.Next();
        } else if(command == "CETAK_PENYIMPANAN"){
            //gamaManager.getCurrentPlayer().cetakPenyimpanan();
        } else if(command == "PUNGUT_PAJAK"){
            //Periksa apakah pemain yang sekarang bermain walikota atau bukan
            //kalau walikota
            //gameManager.getCurrentPlayer().pungutPajak();
            //kalau bukan walikota
            //throw exception "Anda bukan walikota, tidak bisa memungut pajak!"
        } else if(command == "CETAK_LADANG"){
            //Periksa apakah pemain yang sekarang bermain petani atau bukan
            //kalau petani
            //gameManager.getCurrentPlayer().cetakLadang();
            //kalau bukan petani
            //throw exception kayak "Anda bukan petani, tidak bisa cetak ladang!"
        } else if(command == "CETAK_PETERNAKAN"){
            //Periksa apakah pemain yang sekarang bermain peternak atau bukan
            //kalau peternak
            //gameManager.getCurrentPlayer().cetakPeternak();
            //kalau bukan peternak
            //throw exception kayak "Anda bukan peternak, tidak bisa cetak peternakan!"
        } else if(command == "TANAM"){
            //Periksa apakah pemain yang sekarang bermain petani atau bukan
            //kalau petani
            //gameManager.getCurrentPlayer().Tanam();
            //kalau bukan petani
            //throw exception kayak "Anda bukan petani, tidak bisa menanam!"
        } else if(command == "TERNAK"){
            //Periksa apakah pemain yang sekarang bermain peternak atau bukan
            //kalau peternak
            //gameManager.getCurrentPlayer().Ternak();
            //kalau bukan peternak
            //throw exception kayak "Anda bukan peternak, tidak bisa beternak!"
        } else if(command == "BANGUN_BANGUNAN"){
            //Periksa apakah pemain yang sekarang bermain walikota atau bukan
            //kalau walikota
            //gameManager.getCurrentPlayer().BangunBangunan();
            //kalau bukan walikota
            //throw exception "Anda bukan walikota, tidak bisa membangun bangunan!"
        } else if(command == "MAKAN"){
            //gameManager.getCurrentPlayer().Makan();
        } else if(command == "KASIH_MAKAN"){
            //Periksa apakah pemain yang sekarang bermain peternak atau bukan
            //kalau peternak
            //gameManager.getCurrentPlayer().KasihMakan();
            //kalau bukan peternak
            //throw exception kayak "Anda bukan peternak, tidak bisa kasih makan!"
        } else if(command == "BELI"){
            //gameManager.getCurrentPlayer().Beli();
        } else if(command == "JUAL"){
            //gameManager.getCurrentPlayer().Jual();
        } else if(command == "SIMPAN"){
            //gameManager.save();
        } else if(command == "TAMBAH_PEMAIN"){
            //Periksa apakah pemain yang sekarang bermain walikota atau bukan
            //kalau walikota
            //gameManager.getCurrentPlayer().TambahPemain();
            //kalau bukan walikota
            //throw exception "Anda bukan walikota, tidak bisa meNAMBAH PEMAIN!"
        } else {
            cout<<"Perintah tidak valid! Silakan input ulang. \n";
            continue;
        }
        //TODO: UNCOMMENT THESE COMMANDS BELOW AFTER MERGING
        /*if(gameManager.checkWinner()){
            cout<<"Selamat, "<<gameManager.getWinnerName()<<"! Anda yang telah memenangkan Bangun Kerajaan Bersama Labpro!\n Permainan berakhir.\n";
            gameManager.clearPlayerList();
            return 0;
        }*/
    }
    return 0;
}