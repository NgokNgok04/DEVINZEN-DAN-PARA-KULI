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