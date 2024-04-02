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
    } catch (MiscConfigMissingException ME){
        cout<<ME.what()<<"\n";
    } catch (PlantConfigMissingException TE){
        cout<<TE.what()<<"\n";
    } catch (ProductConfigMissingException PE){
        cout<<PE.what()<<"\n";
    } catch (RecipeConfigMissingException RE){
        cout<<RE.what()<<"\n";
    } catch (InvalidAnimalIDConfigException IAIC){
        cout<<IAIC.what()<<"\n";
    } catch (InvalidAnimalWeightConfigException IAWC){
        cout<<IAWC.what()<<"\n";
    } catch(InvalidAnimalPriceConfigException IAPC){
        cout<<IAPC.what()<<"\n";
    } catch(InvalidAnimalTypeConfigException IATC){
        cout<<IATC.what()<<"\n";
    }
    
    cout<<"test fileconfig\n";
    cout<<PH;
    
    return 0;
}