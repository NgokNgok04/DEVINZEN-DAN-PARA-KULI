#include <iostream>
#include "parsers/ParserHewan.hpp"
#include "parsers/ParserMisc.hpp"
using namespace std;
int main(){
    ParserHewan PH;
    ParserMisc PM;
    string animalConfigDirectory = "../config/animal.txt";
    PH.ParseFile(animalConfigDirectory);
    PM.ParseFile(animalConfigDirectory);
    return 0;
}