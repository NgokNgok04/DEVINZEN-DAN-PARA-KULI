#include <iostream>
#include "exceptions/Exceptions.hpp"
#include "gamemanager/GameManager.hpp"
using namespace std;
int main(){
    ParserHewan PH;
    ParserMisc PM;
    ParserTanaman PT;
    ParserProduk PP;
    ParserResep PR;
    string animalConfigDirectory = "../config/animal.txt";
    string miscConfigDirectory = "../config/misc.txt";
    string plantConfigDirectory = "../config/plant.txt";
    string productConfigDirectory = "../config/product.txt";
    string recipeConfigDirectory = "../config/recipe.txt";
    try{
        PH.ParseFile(animalConfigDirectory);
        PM.ParseFile(miscConfigDirectory);
        PT.ParseFile(plantConfigDirectory);
        PP.ParseFile(productConfigDirectory);
        PR.ParseFile(recipeConfigDirectory);
    } catch (AnimalConfigMissingException AE){
        cout<<AE.what()<<"\n";
        return 0;
    } catch (MiscConfigMissingException ME){
        cout<<ME.what()<<"\n";
        return 0;
    } catch (PlantConfigMissingException TE){
        cout<<TE.what()<<"\n";
        return 0;
    } catch (ProductConfigMissingException PE){
        cout<<PE.what()<<"\n";
        return 0;
    } catch (RecipeConfigMissingException RE){
        cout<<RE.what()<<"\n";
        return 0;
    } catch (InvalidAnimalIDConfigException IAIC){
        cout<<IAIC.what()<<"\n";
        return 0;
    } catch (InvalidAnimalWeightConfigException IAWC){
        cout<<IAWC.what()<<"\n";
        return 0;
    } catch(InvalidAnimalPriceConfigException IAPC){
        cout<<IAPC.what()<<"\n";
        return 0;
    } catch(InvalidAnimalTypeConfigException IATC){
        cout<<IATC.what()<<"\n";
        return 0;
    } catch(InvalidMiscMoneyConfigException IMMC){
        cout<<IMMC.what()<<"\n";
        return 0;
    } catch(InvalidMiscWeightConfigException IMWC){
        cout<<IMWC.what()<<"\n";
        return 0;
    } catch(InvalidStorageDimensionConfigException ISDC){
        cout<<ISDC.what()<<"\n";
        return 0;
    } catch(InvalidFieldDimensionConfigException IFiDC){
        cout<<IFiDC.what()<<"\n";
        return 0;
    } catch(InvalidFarmDimensionConfigException IFaDC){
        cout<<IFaDC.what()<<"\n";
        return 0;
    } catch(InvalidPlantIDConfigException IPIC){
        cout<<IPIC.what()<<"\n";
        return 0;
    } catch(InvalidPlantTypeConfigException IPTC){
        cout<<IPTC.what()<<"\n";
        return 0;
    } catch(InvalidPlantDurationConfigException IPDC){
        cout<<IPDC.what()<<"\n";
        return 0;
    } catch(InvalidPlantPriceConfigException IPPC){
        cout<<IPPC.what()<<"\n";
        return 0;
    } catch(InvalidProductIDConfigException IPrIC){
        cout<<IPrIC.what()<<"\n";
        return 0;
    } catch(InvalidProductPriceConfigException IPrPC){
        cout<<IPrPC.what()<<"\n";
        return 0;
    } catch(InvalidProductTypeConfigException IPrTC){
        cout<<IPrTC.what()<<"\n";
        return 0;
    } catch(InvalidProductWeightConfigException IPrWC){
        cout<<IPrWC.what()<<"\n";
        return 0;
    } catch(InvalidRecipeIDConfigException IRIC){
        cout<<IRIC.what()<<"\n";
        return 0;
    } catch(InvalidRecipePriceConfigException IRPC){
        cout<<IRPC.what()<<"\n";
        return 0;
    } catch(InvalidRecipeQuantityConfigException IRQC){
        cout<<IRQC.what()<<"\n";
        return 0;
    }
    
    GameManager gameManager(PH,PT,PP,PR,PM);

    gameManager.Debug();

    cout<<"Selamat datang di permainan Mengelola Kerajaan! Silakan input pilihan angka di bawah ini untuk mulai bermain:\n";
    cout<<"1. Mulai dari permainan baru\n";
    cout<<"2. Mulai dari memuat file save\n";

    
    int choice;
    while(true){
        cout<<">";
        cin>>choice;
        if(choice == 1){
            cout<<"Membuat game baru\n";
            break;
        } else if(choice == 2){
            cout<<"Membuka Save file\n";
            break;
        }
    }

    cout<<"Setup permainan selesai, permainan dimulai!\n";
    string command;
    while(true){
        //cout<<"Sekarang giliran "<<gameManager.getCurrentPlayerName()<<"!\n";

        cout<<">";
        cin>>command;
        if(command == "NEXT"){
            cout<<"Ini command Next. Yang harus dilakukan adalah: 1. Ganti ke pemain berikutnya 2. Tambah umur SEMUA tanaman menjadi 1 satuan lebih tua\n";
            //gameManager.Next();
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
        /*if(gameManager.isThereAWinner()){
            cout<<"Selamat, "<<gameManager.getWinnerName()<<"! Anda yang telah memenangkan permainan ini!\n Permainan berakhir.\n";
            return 0;
        }*/
    }
    return 0;
}