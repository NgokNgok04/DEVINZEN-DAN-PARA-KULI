#include <iostream>
#include "parsers/ParserHewan.hpp"
#include "parsers/ParserMisc.hpp"
#include "parsers/ParserTanaman.hpp"
#include "parsers/ParserProduk.hpp"
#include "parsers/ParserResep.hpp"
#include "exceptions/Exceptions.hpp"
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
    }
    
    cout<<"test fileconfig\n";
    cout<<PH;
    cout<<PM;
    cout<<PT;
    cout<<PP;
    return 0;
}