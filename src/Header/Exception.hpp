#include <bits/stdc++.h>

using namespace std;

class BaseException
{

public:
    BaseException(){};
    ~BaseException(){};
    virtual string what() = 0;
};

class AnimalConfigMissingException : public BaseException
{
public:
    AnimalConfigMissingException(){};
    ~AnimalConfigMissingException(){};
    string what()
    {
        return "File config animal.txt hilang di folder config!";
    }
};

class MiscConfigMissingException : public BaseException
{
public:
    MiscConfigMissingException(){};
    ~MiscConfigMissingException(){};
    string what()
    {
        return "File config misc.txt hilang di folder config!";
    }
};

class PlantConfigMissingException : public BaseException
{
public:
    PlantConfigMissingException(){};
    ~PlantConfigMissingException(){};
    string what()
    {
        return "File config plant.txt hilang di folder config!";
    }
};

class ProductConfigMissingException : public BaseException
{
public:
    ProductConfigMissingException(){};
    ~ProductConfigMissingException(){};
    string what()
    {
        return "File config product.txt hilang di folder config!";
    }
};

class RecipeConfigMissingException : public BaseException
{
public:
    RecipeConfigMissingException(){};
    ~RecipeConfigMissingException(){};
    string what()
    {
        return "File config recipe.txt hilang di folder config!";
    }
};

class InvalidAnimalPriceConfigException : public BaseException
{
public:
    InvalidAnimalPriceConfigException(){};
    ~InvalidAnimalPriceConfigException(){};
    string what()
    {
        return "Ada harga hewan yang tidak valid di file config animal.txt!";
    }
};

class InvalidAnimalIDConfigException : public BaseException
{
public:
    InvalidAnimalIDConfigException(){};
    ~InvalidAnimalIDConfigException(){};
    string what()
    {
        return "Ada ID hewan yang tidak valid di file config animal.txt!";
    }
};

class InvalidAnimalWeightConfigException : public BaseException
{
public:
    InvalidAnimalWeightConfigException(){};
    ~InvalidAnimalWeightConfigException(){};
    string what()
    {
        return "Ada berat hewan yang tidak valid di file config animal.txt!";
    }
};

class InvalidAnimalTypeConfigException : public BaseException
{
public:
    InvalidAnimalTypeConfigException(){};
    ~InvalidAnimalTypeConfigException(){};
    string what()
    {
        return "Ada tipe hewan yang tidak valid di file config animal.txt!";
    }
};

class InvalidMiscMoneyConfigException : public BaseException
{
public:
    InvalidMiscMoneyConfigException(){};
    ~InvalidMiscMoneyConfigException(){};
    string what()
    {
        return "Nilai uang yang dibutuhkan untuk memenangkan permainan di misc.txt tidak valid!";
    }
};

class InvalidMiscWeightConfigException : public BaseException
{
public:
    InvalidMiscWeightConfigException(){};
    ~InvalidMiscWeightConfigException(){};
    string what()
    {
        return "Nilai berat badan yang dibutuhkan untuk memenangkan permainan di misc.txt tidak valid!";
    }
};

class InvalidStorageDimensionConfigException : public BaseException
{
public:
    InvalidStorageDimensionConfigException(){};
    ~InvalidStorageDimensionConfigException(){};
    string what()
    {
        return "Dimensi ukuran penyimpanan di misc.txt tidak valid!";
    }
};

class InvalidFarmDimensionConfigException : public BaseException
{
public:
    InvalidFarmDimensionConfigException(){};
    ~InvalidFarmDimensionConfigException(){};
    string what()
    {
        return "Dimensi ukuran peternakan di misc.txt tidak valid!";
    }
};

class InvalidFieldDimensionConfigException : public BaseException
{
public:
    InvalidFieldDimensionConfigException(){};
    ~InvalidFieldDimensionConfigException(){};
    string what()
    {
        return "Dimensi ukuran lahan di misc.txt tidak valid!";
    }
};

class InvalidPlantIDConfigException : public BaseException
{
public:
    InvalidPlantIDConfigException(){};
    ~InvalidPlantIDConfigException(){};
    string what()
    {
        return "Ada ID tanaman yang tidak valid di file config plant.txt!";
    }
};

class InvalidPlantTypeConfigException : public BaseException
{
public:
    InvalidPlantTypeConfigException(){};
    ~InvalidPlantTypeConfigException(){};
    string what()
    {
        return "Ada tipe tanaman yang tidak valid di file config plant.txt!";
    }
};

class InvalidPlantPriceConfigException : public BaseException
{
public:
    InvalidPlantPriceConfigException(){};
    ~InvalidPlantPriceConfigException(){};
    string what()
    {
        return "Ada harga tanaman yang tidak valid di file config plant.txt!";
    }
};

class InvalidPlantDurationConfigException : public BaseException
{
public:
    InvalidPlantDurationConfigException(){};
    ~InvalidPlantDurationConfigException(){};
    string what()
    {
        return "Ada durasi tanaman yang tidak valid di file config plant.txt!";
    }
};

class InvalidProductIDConfigException : public BaseException
{
public:
    InvalidProductIDConfigException(){};
    ~InvalidProductIDConfigException(){};
    string what()
    {
        return "Ada ID produk yang tidak valid di file config product.txt!";
    }
};

class InvalidProductWeightConfigException : public BaseException
{
public:
    InvalidProductWeightConfigException(){};
    ~InvalidProductWeightConfigException(){};
    string what()
    {
        return "Ada berat produk yang tidak valid di file config product.txt!";
    }
};

class InvalidProductTypeConfigException : public BaseException
{
public:
    InvalidProductTypeConfigException(){};
    ~InvalidProductTypeConfigException(){};
    string what()
    {
        return "Ada tipe produk yang tidak valid di file config product.txt!";
    }
};

class InvalidProductPriceConfigException : public BaseException
{
public:
    InvalidProductPriceConfigException(){};
    ~InvalidProductPriceConfigException(){};
    string what()
    {
        return "Ada harga produk yang tidak valid di file config product.txt!";
    }
};

class InvalidRecipeIDConfigException : public BaseException
{
public:
    InvalidRecipeIDConfigException(){};
    ~InvalidRecipeIDConfigException(){};
    string what()
    {
        return "Ada ID resep yang tidak valid di file config recipe.txt!";
    }
};

class InvalidRecipePriceConfigException : public BaseException
{
public:
    InvalidRecipePriceConfigException(){};
    ~InvalidRecipePriceConfigException(){};
    string what()
    {
        return "Ada harga resep yang tidak valid di file config recipe.txt!";
    }
};

class InvalidRecipeQuantityConfigException : public BaseException
{
public:
    InvalidRecipeQuantityConfigException(){};
    ~InvalidRecipeQuantityConfigException(){};
    string what()
    {
        return "Ada kuantitas bahan resep yang tidak valid di file config recipe.txt!";
    }
};

class InvalidIndexMatrixArea : public BaseException
{
public:
    InvalidIndexMatrixArea(){};
    ~InvalidIndexMatrixArea(){};
    string what()
    {
        return "Slot yang diakses tidak valid!";
    }
};

class InvalidEmptySlot : public BaseException
{
public:
    InvalidEmptySlot(){};
    ~InvalidEmptySlot(){};
    string what()
    {
        return "Slot yang diakses kosong!";
    }
};

class InvalidFilledSlot : public BaseException
{
public:
    InvalidFilledSlot(){};
    ~InvalidFilledSlot(){};
    string what()
    {
        return "Slot yang diakses bukanlah petak kosong!";
    }
};

class InvalidNotTanaman : public BaseException
{
public:
    InvalidNotTanaman(){};
    ~InvalidNotTanaman(){};
    string what()
    {
        return "Pilihan itu bukanlah tanaman!";
    }
};

class InvalidNotHewan : public BaseException
{
public:
    InvalidNotHewan(){};
    ~InvalidNotHewan(){};
    string what()
    {
        return "Pilihan itu bukanlah hewan!";
    }
};

class InvalidPanenIdx : public BaseException
{
public:
    InvalidPanenIdx(){};
    ~InvalidPanenIdx(){};
    string what()
    {
        return "Tidak terdapat pilihan tersebut!";
    }
};

class InvalidPanenAmount : public BaseException
{
public:
    InvalidPanenAmount(){};
    ~InvalidPanenAmount(){};
    string what()
    {
        return "Jumlah petak pilihan tidak valid!";
    }
};

class InvalidPanenAmountOver : public BaseException
{
public:
    InvalidPanenAmountOver(){};
    ~InvalidPanenAmountOver(){};
    string what()
    {
        return "Jumlah petak pilihan melebihi ketersediaan!";
    }
};

class InvalidInventorySpace : public BaseException
{
public:
    InvalidInventorySpace(){};
    ~InvalidInventorySpace(){};
    string what()
    {
        return "Jumlah petak pilihan melebihi slot inventory!";
    }
};

class InvalidPlantChoice : public BaseException
{
public:
    InvalidPlantChoice(){};
    ~InvalidPlantChoice(){};
    string what()
    {
        return "Pilihan itu bukanlah tanaman yang ingin dipanen!";
    }
};

class InvalidAnimalChoice : public BaseException
{
public:
    InvalidAnimalChoice(){};
    ~InvalidAnimalChoice(){};
    string what()
    {
        return "Pilihan itu bukanlah hewan yang ingin dipanen!";
    }
};

class NoHarvestablePlant : public BaseException
{
public:
    NoHarvestablePlant(){};
    ~NoHarvestablePlant(){};
    string what()
    {
        return "Tidak terdapat tanaman untuk dipanen!";
    }
};

class NoHarvestableAnimal : public BaseException
{
public:
    NoHarvestableAnimal(){};
    ~NoHarvestableAnimal(){};
    string what()
    {
        return "Tidak terdapat hewan untuk dipanen!";
    }
};

class FullInv : public BaseException
{
public:
    FullInv(){};
    ~FullInv(){};
    string what()
    {
        return "Slot inventory tidak mencukupi!";
    }
};

class InvalidCarnivore : public BaseException
{
public:
    InvalidCarnivore(){};
    ~InvalidCarnivore(){};
    string what()
    {
        return "Bukan bahan pangan untuk binatang karnivora!";
    }
};

class InvalidHerbivore : public BaseException
{
public:
    InvalidHerbivore(){};
    ~InvalidHerbivore(){};
    string what()
    {
        return "Bukan bahan pangan untuk binatang herbivora!";
    }
};

class InvalidNotProduct : public BaseException
{
public:
    InvalidNotProduct(){};
    ~InvalidNotProduct(){};
    string what()
    {
        return "Barang pada slot tersebut bukanlah produk!";
    }
};

class InvalidPositionMatrixArea : public BaseException
{
public:
    InvalidPositionMatrixArea(){};
    ~InvalidPositionMatrixArea(){};
    string what()
    {
        return "Slot Matrix tidak valid";
    }
};

class InvalidResponseToko : public BaseException
{
public:
    InvalidResponseToko(){};
    ~InvalidResponseToko(){};
    string what()
    {
        return "Input tidak valid. Silahkan masukkan Input sesuai kesediaan Toko";
    }
};

class NotEatableSlot : public BaseException
{
public:
    NotEatableSlot(){};
    ~NotEatableSlot(){};
    string what()
    {
        return "Slot yang dipilih bukan Makanan";
    }
};

class EmptyFoodSlot : public BaseException
{
public:
    EmptyFoodSlot(){};
    ~EmptyFoodSlot(){};
    string what()
    {
        return "Slot yang dipilih tidak mempunyai Makanan";
    }
};

class EmptyInventory : public BaseException
{
public:
    EmptyInventory(){};
    ~EmptyInventory(){};
    string what()
    {
        return "Inventory Kosong!";
    }
};

class NoFoodInInventory : public BaseException
{
public:
    NoFoodInInventory(){};
    ~NoFoodInInventory(){};
    string what()
    {
        return "Tidak ada Makanan di Inventory!";
    }
};

class CantSellBangunan : public BaseException
{
public:
    CantSellBangunan(){};
    ~CantSellBangunan(){};
    string what()
    {
        return "Tidak bisa Menjual Bangunan!";
    }
};

class ItemQuantityToSellNotEnough : public BaseException
{
public:
    ItemQuantityToSellNotEnough(){};
    ~ItemQuantityToSellNotEnough(){};
    string what()
    {
        return "Tidak bisa Menjual. Kuantitas barang tidak cukup!";
    }
};

class CantFindNamaBangunan : public BaseException
{
public:
    CantFindNamaBangunan(){};
    ~CantFindNamaBangunan(){};
    string what()
    {
        return "Tidak ada Bangunan dengan nama tersebut!";
    }
};

class MaterialNotEnough : public BaseException
{
private:
    vector<pair<string,int>> materialKurang;
public:
    MaterialNotEnough(vector<pair<string,int>> kurang){
        for(int i=0;i<kurang.size();i++){
            materialKurang.push_back(kurang[i]);
        }
    };
    ~MaterialNotEnough(){};
    string what()
    {
        string kalimat = "Material tidak cukup! Kurang ";
        for(int i=0;i<materialKurang.size();i++){
            kalimat += materialKurang[i].first +" "+to_string(materialKurang[i].second)+" buah";
            if(i!=materialKurang.size()-1){
                kalimat+=", ";
            }
        }
        kalimat+=".";
        return kalimat;
    }
};

class InvalidSubResponse : public BaseException
{
public:
    InvalidSubResponse(){};
    ~InvalidSubResponse(){};
    string what()
    {
        return "Input tidak valid!";
    }
};

class InventoryNotEnough : public BaseException
{
public:
    InventoryNotEnough(){};
    ~InventoryNotEnough(){};
    string what()
    {
        return "Inventory yang tersisa tidak cukup!";
    }
};

class StockTokoNotEnough : public BaseException
{
public:
    StockTokoNotEnough(){};
    ~StockTokoNotEnough(){};
    string what()
    {
        return "Stock Toko tidak cukup!";
    }
};

class NotEnoughGulden : public BaseException
{
public:
    NotEnoughGulden(){};
    ~NotEnoughGulden(){};
    string what()
    {
        return "Gulden pemain tidak cukup!";
    }
};

class SlotFilled : public BaseException
{
public:
    SlotFilled(){};
    ~SlotFilled(){};
    string what()
    {
        return "Slot Sudah diisi! Silahkan pilih slot lain!";
    }
};

class NoAnimalInCage : public BaseException
{
public:
    NoAnimalInCage(){};
    ~NoAnimalInCage(){};
    string what()
    {
        return "Tidak terdapat hewan dalam ternakan!";
    }
};

class CannotPrintFieldException : public BaseException{
public:
    CannotPrintFieldException(){};
    ~CannotPrintFieldException(){};
    string what()
    {
        return "Anda bukan petani, tidak bisa cetak ladang!";
    }
};

class CannotPrintFarmException : public BaseException{
public:
    CannotPrintFarmException(){};
    ~CannotPrintFarmException(){};
    string what()
    {
        return "Anda bukan peternak, tidak bisa cetak peternakan!";
    }
};

class CannotPlantException : public BaseException{
public:
    CannotPlantException(){};
    ~CannotPlantException(){};
    string what()
    {
        return "Anda bukan petani, tidak bisa menanam!";
    }
};

class CannotFarmException : public BaseException{
public:
    CannotFarmException(){};
    ~CannotFarmException(){};
    string what()
    {
        return "Anda bukan peternak, tidak bisa beternak!";
    }
};

class CannotFeedException : public BaseException{
public:
    CannotFeedException(){};
    ~CannotFeedException(){};
    string what()
    {
        return "Anda bukan peternak, tidak bisa kasih makan!";
    }
};

class CantBuyBangunan : public BaseException
{
public:
    CantBuyBangunan(){};
    ~CantBuyBangunan(){};
    string what()
    {
        return "Walikota tidak bisa membeli bangunan!";
    }
};

class InvalidPathMuat : public BaseException{
public:
    string what(){
        return "Path yang dimasukkan tidak valid!";
    }
};

class InvalidDirSimpan : public BaseException{
    public:
        string what(){
            return "Lokasi berkas directory tidak valid!";
        }
};

class InvalidTypePemain : public BaseException{
public:
    InvalidTypePemain(){};
    ~InvalidTypePemain(){};
    string what(){
        return "Tipe pemain tidak valid!";
    }
    
};

class UserNamePemainTidakUnik: public BaseException{
public:
    UserNamePemainTidakUnik(){};
    ~UserNamePemainTidakUnik(){};
    string what(){
        return "Username sudah ada yang pakai!";
    }
};

class AllCarnivNoFood: public BaseException{
public:
    string what(){
        return "Semua Hewan kamu karnivora dan kamu tidak ada makanan untuk mereka!";
    }
};

class AllHerbivNoFood: public BaseException{
public:
    string what(){
        return "Semua Hewan kamu herbivora dan kamu tidak ada makanan untuk mereka!";
    }
};

class NoFoodForHerbiv: public BaseException{
public:
    string what(){
        return "Hewan yang kamu pilih adalah herbivora dan tidak ada makanan untuknya!";
    }
};

class NoFoodForCarniv: public BaseException{
public:
    string what(){
        return "Hewan yang kamu pilih adalah karnivora dan tidak ada makanan untuknya!";
    }
};

class InvalidCommand: public BaseException{
public:
    string what(){
        return "Command Anda Tidak Valid!";
    }
};

class NoPlant: public BaseException{
public:
    NoPlant(){};
    ~NoPlant(){};
    string what(){
        return "Tidak terdapat tanaman dalam inventory";
    }
};

class NoAnimal: public BaseException{
public:
    NoAnimal(){};
    ~NoAnimal(){};
    string what(){
        return "Tidak terdapat hewan dalam inventory";
    }
};

class NoEmptySlot: public BaseException{
public:
    NoEmptySlot(){};
    ~NoEmptySlot(){};
    string what(){
        return "Tidak terdapat slot kosong";
    }
};

