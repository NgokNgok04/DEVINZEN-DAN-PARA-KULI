#include <bits/stdc++.h>

using namespace std;

class BaseException {

    public:
        BaseException(){};
        ~BaseException(){};
        virtual string what() = 0;
};

class AnimalConfigMissingException : public BaseException{
    public:
        AnimalConfigMissingException(){};
        ~AnimalConfigMissingException(){};
        string what(){
            return "File config animal.txt hilang di folder config!";
        }
};

class MiscConfigMissingException : public BaseException{
    public:
        MiscConfigMissingException(){};
        ~MiscConfigMissingException(){};
        string what(){
            return "File config misc.txt hilang di folder config!";
        }
};

class PlantConfigMissingException : public BaseException{
    public:
        PlantConfigMissingException(){};
        ~PlantConfigMissingException(){};
        string what(){
            return "File config plant.txt hilang di folder config!";
        }
};

class ProductConfigMissingException : public BaseException{
    public:
        ProductConfigMissingException(){};
        ~ProductConfigMissingException(){};
        string what(){
            return "File config product.txt hilang di folder config!";
        }
};

class RecipeConfigMissingException : public BaseException{
    public:
        RecipeConfigMissingException(){};
        ~RecipeConfigMissingException(){};
        string what(){
            return "File config recipe.txt hilang di folder config!";
        }
};

class InvalidAnimalPriceConfigException : public BaseException{
    public:
        InvalidAnimalPriceConfigException(){};
        ~InvalidAnimalPriceConfigException(){};
        string what(){
            return "Ada harga hewan yang tidak valid di file config animal.txt!";
        }
};

class InvalidAnimalIDConfigException : public BaseException{
    public:
        InvalidAnimalIDConfigException(){};
        ~InvalidAnimalIDConfigException(){};
        string what(){
            return "Ada ID hewan yang tidak valid di file config animal.txt!";
        }
};

class InvalidAnimalWeightConfigException : public BaseException{
    public:
        InvalidAnimalWeightConfigException(){};
        ~InvalidAnimalWeightConfigException(){};
        string what(){
            return "Ada berat hewan yang tidak valid di file config animal.txt!";
        }
};

class InvalidAnimalTypeConfigException : public BaseException{
    public:
        InvalidAnimalTypeConfigException(){};
        ~InvalidAnimalTypeConfigException(){};
        string what(){
            return "Ada tipe hewan yang tidak valid di file config animal.txt!";
        }
};

class InvalidMiscMoneyConfigException : public BaseException{
    public:
        InvalidMiscMoneyConfigException(){};
        ~InvalidMiscMoneyConfigException(){};
        string what(){
            return "Nilai uang yang dibutuhkan untuk memenangkan permainan di misc.txt tidak valid!";
        }
};

class InvalidMiscWeightConfigException : public BaseException{
    public:
        InvalidMiscWeightConfigException(){};
        ~InvalidMiscWeightConfigException(){};
        string what(){
            return "Nilai berat badan yang dibutuhkan untuk memenangkan permainan di misc.txt tidak valid!";
        }
};

class InvalidStorageDimensionConfigException : public BaseException{
    public:
        InvalidStorageDimensionConfigException(){};
        ~InvalidStorageDimensionConfigException(){};
        string what(){
            return "Dimensi ukuran penyimpanan di misc.txt tidak valid!";
        }
};

class InvalidFarmDimensionConfigException : public BaseException{
    public:
        InvalidFarmDimensionConfigException(){};
        ~InvalidFarmDimensionConfigException(){};
        string what(){
            return "Dimensi ukuran peternakan di misc.txt tidak valid!";
        }
};

class InvalidFieldDimensionConfigException : public BaseException{
    public:
        InvalidFieldDimensionConfigException(){};
        ~InvalidFieldDimensionConfigException(){};
        string what(){
            return "Dimensi ukuran lahan di misc.txt tidak valid!";
        }
};

class InvalidPlantIDConfigException : public BaseException{
    public:
        InvalidPlantIDConfigException(){};
        ~InvalidPlantIDConfigException(){};
        string what(){
            return "Ada ID tanaman yang tidak valid di file config plant.txt!";
        }
};

class InvalidPlantTypeConfigException : public BaseException{
    public:
        InvalidPlantTypeConfigException(){};
        ~InvalidPlantTypeConfigException(){};
        string what(){
            return "Ada tipe tanaman yang tidak valid di file config plant.txt!";
        }
};

class InvalidPlantPriceConfigException : public BaseException{
    public:
        InvalidPlantPriceConfigException(){};
        ~InvalidPlantPriceConfigException(){};
        string what(){
            return "Ada harga tanaman yang tidak valid di file config plant.txt!";
        }
};

class InvalidPlantDurationConfigException : public BaseException{
    public:
        InvalidPlantDurationConfigException(){};
        ~InvalidPlantDurationConfigException(){};
        string what(){
            return "Ada durasi tanaman yang tidak valid di file config plant.txt!";
        }
};

class InvalidProductIDConfigException : public BaseException{
    public:
        InvalidProductIDConfigException(){};
        ~InvalidProductIDConfigException(){};
        string what(){
            return "Ada ID produk yang tidak valid di file config product.txt!";
        }
};

class InvalidProductWeightConfigException : public BaseException{
    public:
        InvalidProductWeightConfigException(){};
        ~InvalidProductWeightConfigException(){};
        string what(){
            return "Ada berat produk yang tidak valid di file config product.txt!";
        }
};

class InvalidProductTypeConfigException : public BaseException{
    public:
        InvalidProductTypeConfigException(){};
        ~InvalidProductTypeConfigException(){};
        string what(){
            return "Ada tipe produk yang tidak valid di file config product.txt!";
        }
};

class InvalidProductPriceConfigException : public BaseException{
    public:
        InvalidProductPriceConfigException(){};
        ~InvalidProductPriceConfigException(){};
        string what(){
            return "Ada harga produk yang tidak valid di file config product.txt!";
        }
};

class InvalidRecipeIDConfigException : public BaseException{
    public:
        InvalidRecipeIDConfigException(){};
        ~InvalidRecipeIDConfigException(){};
        string what(){
            return "Ada ID resep yang tidak valid di file config recipe.txt!";
        }
};

class InvalidRecipePriceConfigException : public BaseException{
    public:
        InvalidRecipePriceConfigException(){};
        ~InvalidRecipePriceConfigException(){};
        string what(){
            return "Ada harga resep yang tidak valid di file config recipe.txt!";
        }
};

class InvalidRecipeQuantityConfigException : public BaseException{
    public:
        InvalidRecipeQuantityConfigException(){};
        ~InvalidRecipeQuantityConfigException(){};
        string what(){
            return "Ada kuantitas bahan resep yang tidak valid di file config recipe.txt!";
        }
};

class InvalidSlotIndexException : public BaseException{
    public:
        InvalidSlotIndexException(){};
        ~InvalidSlotIndexException(){};
        string what(){
            return "Slot yang dipilih tidak valid!";
        }
};

class InventoryEmptySlotException : public BaseException{
    public:
        InventoryEmptySlotException(){};
        ~InventoryEmptySlotException(){};
        string what(){
            return "Slot inventori yang dipilih kosong!";
        }
};

class InventoryInedibleSlotException : public BaseException{
    public:
        InventoryInedibleSlotException(){};
        ~InventoryInedibleSlotException(){};
        string what(){
            return "Barang di slot inventori yang dipilih tidak bisa dimakan!";
        }
};