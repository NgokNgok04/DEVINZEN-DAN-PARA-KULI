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