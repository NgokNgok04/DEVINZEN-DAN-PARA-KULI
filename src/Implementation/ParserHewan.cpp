#include "../Header/ParserHewan.hpp"
vector<string> ParserHewan::validAnimalTypes = {"HERBIVORE","CARNIVORE","OMNIVORE"};
vector<int> ParserHewan::animalID = vector<int>();
vector<string> ParserHewan::animalCode = vector<string>();
vector<string> ParserHewan::animalName = vector<string>();
vector<string> ParserHewan::animalType = vector<string>();
vector<int> ParserHewan::harvestWeight = vector<int>();
vector<int> ParserHewan::price = vector<int>();
map<int,int> ParserHewan::IndexToIDMap = map<int,int>();
map<int,int> ParserHewan::IDToIndexMap = map<int,int>();
void ParserHewan::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); // buka file

    if (!InputFile.is_open())
    { // jika gagal dibuka lempar exception
        throw AnimalConfigMissingException();
        return;
    }
    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    bool flagAnimalType;
    while (getline(InputFile, LineFile))
    {
        flagAnimalType = false;
        SpaceStrippedLine = StringToStringList(LineFile); // parse spasi
        // validasi dan input data id hewan
        numValue = stoi(SpaceStrippedLine[0]);
        if (numValue <= 0)
        { // ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalIDConfigException();
            return;
        }
        this->animalID.push_back(numValue);

        this->animalCode.push_back(SpaceStrippedLine[1]); // input code
        this->animalName.push_back(SpaceStrippedLine[2]); // input nama hewan

        for (int i = 0; i < this->validAnimalTypes.size(); i++)
        { // validasi tipe hewan
            if (SpaceStrippedLine[3] == this->validAnimalTypes[i])
            { // hanya tipe data yang valid yang bisa diinput
                flagAnimalType = true;
                break;
            }
        }
        if (flagAnimalType)
        {
            this->animalType.push_back(SpaceStrippedLine[3]); // input tipe hewan
        }
        else
        {
            this->ClearParserData();
            throw InvalidAnimalTypeConfigException();
            return;
        }
        numValue = stoi(SpaceStrippedLine[4]); // VALIDASI DAN INPUT BERAT HEWAN
        if (numValue < 0)
        { // berat tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalWeightConfigException();
            return;
        }
        this->harvestWeight.push_back(numValue);
        // VALIDASI DAN INPUT HARGA HEWAN
        numValue = stoi(SpaceStrippedLine[5]);
        if (numValue <= 0)
        { // harga tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }

    for (int i = 0; i < animalID.size(); i++)
    {
        IndexToIDMap.insert({i, animalID[i]});
        IDToIndexMap.insert({animalID[i], i});
    }
}

void ParserHewan::ClearParserData()
{
    this->animalID.clear();
    this->animalName.clear();
    this->animalCode.clear();
    this->animalType.clear();
    this->harvestWeight.clear();
    this->price.clear();
}

int ParserHewan::getID(int index)
{
    return animalID[index];
}

string ParserHewan::getCode(int ID)
{
    int index = IDToIndex(ID);
    return animalCode[index];
}

string ParserHewan::getName(int ID)
{
    int index = IDToIndex(ID);
    return animalName[index];
}

string ParserHewan::getType(int ID)
{
    int index = IDToIndex(ID);
    return animalType[index];
}

int ParserHewan::getHarvestWeight(int ID)
{
    int index = IDToIndex(ID);
    return harvestWeight[index];
}

int ParserHewan::getPrice(int ID)
{
    int index = IDToIndex(ID);
    return price[index];
}

int ParserHewan::getConfigSize()
{
    return animalID.size();
}

int ParserHewan::convertCodeToID(string Code)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (animalCode[i] == Code)
        {
            return animalID[i];
        }
    }

    return -1;
}

int ParserHewan::convertNameToID(string Name)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (animalName[i] == Name)
        {
            return animalID[i];
        }
    }

    return -1;
}

int ParserHewan::indexToID(int index)
{
    return IndexToIDMap[index];
}
int ParserHewan::IDToIndex(int ID)
{
    return IDToIndexMap[ID];
}
ostream &operator<<(ostream &os, ParserHewan &PH)
{
    for (int i = 0; i < PH.animalID.size(); i++)
    {
        os << PH.animalID[i] << " " << PH.animalCode[i] << " " << PH.animalName[i] << " " << PH.animalType[i] << " " << PH.harvestWeight[i] << " " << PH.price[i] << "\n";
    }

    return os;
}
