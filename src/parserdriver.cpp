#include <iostream>
#include "Header/Exception.hpp"
#include "Header/GameManager.hpp"
using namespace std;
//inisialisasi atribut static di semua parser
vector<string> ParserHewan::validAnimalTypes = {"HERBIVORE","CARNIVORE","OMNIVORE"};
vector<int> ParserHewan::animalID = vector<int>();
vector<string> ParserHewan::animalCode = vector<string>();
vector<string> ParserHewan::animalName = vector<string>();
vector<string> ParserHewan::animalType = vector<string>();
vector<int> ParserHewan::harvestWeight = vector<int>();
vector<int> ParserHewan::price = vector<int>();
map<int,int> ParserHewan::IndexToIDMap = map<int,int>();
map<int,int> ParserHewan::IDToIndexMap = map<int,int>();
int ParserMisc::winningMoney = 0;
int ParserMisc::winningWeight = 0;
pair<int,int> ParserMisc::storageSize = pair<int,int>();
pair<int,int> ParserMisc::fieldSize= pair<int,int>();
pair<int,int> ParserMisc::farmSize= pair<int,int>();
vector<int> ParserProduk::productID = vector<int>();
vector<string> ParserProduk::productCode = vector<string>();
vector<string> ParserProduk::productName = vector<string>();
vector<string> ParserProduk::productType = vector<string>();
vector<string> ParserProduk::productOrigin = vector<string>();
vector<int> ParserProduk::addedWeight= vector<int>();
vector<int> ParserProduk::price= vector<int>();
vector<string> ParserProduk::validProductTypes = vector<string>();
map<int,int> ParserProduk::IndexToIDMap = map<int,int>();
map<int,int> ParserProduk::IDToIndexMap = map<int,int>();
vector<int> ParserResep::recipeID = vector<int>() ;
vector<string> ParserResep::recipeCode= vector<string>();
vector<string> ParserResep::recipeName= vector<string>();
vector<int> ParserResep::recipePrice = vector<int>();
vector<vector<pair<string,int> > > ParserResep::recipeMaterialQuantity = vector<vector<pair<string,int> > > ();
map<int,int> ParserResep::IndexToIDMap = map<int,int>();
map<int,int> ParserResep::IDToIndexMap= map<int,int>();
vector<int> ParserTanaman::plantID = vector<int>();
vector<string> ParserTanaman::plantCode = vector<string>();
vector<string> ParserTanaman::plantName= vector<string>();
vector<string> ParserTanaman::plantType= vector<string>();
vector<int> ParserTanaman::harvestDuration = vector<int>();
vector<int> ParserTanaman::price = vector<int>();
vector<string> ParserTanaman::validPlantTypes= vector<string>();
map<int,int> ParserTanaman::IndexToIDMap = map<int,int>();
map<int,int> ParserTanaman::IDToIndexMap = map<int,int>();
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
    
    cout<<PH;
    cout<<PP;
    cout<<PM;
    cout<<PT;
    cout<<PR;
    return 0;
}