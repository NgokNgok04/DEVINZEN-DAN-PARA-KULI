// #include <iostream>
// #include <vector>
// #include <string>
// #include "./Implementation/GameManager.cpp"
// #include "./Implementation/ParserMisc.cpp"
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
    Toko::initialize();

    gameManager.setupGame();
    gameManager.PlayerDebug();
    cout<<"Setup permainan selesai, permainan dimulai!\n";
    while(gameManager.getWinner()==nullptr){
        cout<<"Sekarang giliran "<<gameManager.getCurrentPlayerName()<<"!\n";
        string command;
        cout<<"> ";
        cin>>command;
        cout<<endl;
        gameManager.prosesInput(command);
    }
    cout<<"Selamat, "<<gameManager.getWinnerName()<<" Menang!"<<endl;
    return 0;
}