#include "helper.hpp"
#include <bits/stdc++.h>
using namespace std;
vector<string> StringToStringList(string inputString){
    vector<string> StringList;
    string tempString;
    tempString = "";

    for(int i = 0; i<inputString.length(); i++){
        if(inputString[i] != ' '){
            tempString = tempString + inputString[i];

        } else {
            if(tempString != ""){
                StringList.push_back(tempString);
                tempString = "";
            } else {
                continue;
            }
        }
    }

    if(tempString != " "){
        StringList.push_back(tempString);
    }
    return StringList;
}

string KodeHurufToNama(string Kode)
{
    map<string,string> KodeToNamaTable;
    KodeToNamaTable.insert({"COW","COW"});
    KodeToNamaTable.insert({"SHP","SHEEP"});
    KodeToNamaTable.insert({"HRS","HORSE"});
    KodeToNamaTable.insert({"RBT","RABBIT"});
    KodeToNamaTable.insert({"SNK","SNAKE"});
    KodeToNamaTable.insert({"CHK","CHICKEN"});
    KodeToNamaTable.insert({"DCK","DUCK"});
    KodeToNamaTable.insert({"TEK","TEAK_TREE"});
    KodeToNamaTable.insert({"SDT","SANDALWOOD_TREE"});
    KodeToNamaTable.insert({"ALT","ALOE_TREE"});
    KodeToNamaTable.insert({"IRN","IRONWOOD_TREE"});
    KodeToNamaTable.insert({"APL","APPLE_TREE"});
    KodeToNamaTable.insert({"ORG","ORANGE_TREE"});
    KodeToNamaTable.insert({"BNT","BANANA_TREE"});
    KodeToNamaTable.insert({"GAV","GUAVA_TREE"});
    KodeToNamaTable.insert({"TAW","TEAK_WOOD"});
    KodeToNamaTable.insert({"SAW","SANDALWOOD_WOOD"});
    KodeToNamaTable.insert({"ALW","ALOE_WOOD"});
    KodeToNamaTable.insert({"IRW","IRONWOOD_WOOD"});
    KodeToNamaTable.insert({"APP","APPLE"});
    KodeToNamaTable.insert({"ORP","ORANGE"});
    KodeToNamaTable.insert({"BNP","BANANA"});
    KodeToNamaTable.insert({"GAP","GUAVA"});
    KodeToNamaTable.insert({"COM","COW_MEAT"});
    KodeToNamaTable.insert({"SHM","SHEEP_MEAT"});
    KodeToNamaTable.insert({"HRM","HORSE_MEAT"});
    KodeToNamaTable.insert({"RBM","RABBIT_MEAT"});
    KodeToNamaTable.insert({"SNM","SNAKE_MEAT"});
    KodeToNamaTable.insert({"CHM","CHICKEN_MEAT"});
    KodeToNamaTable.insert({"DCM","DUCK_MEAT"});
    KodeToNamaTable.insert({"CHE","CHICKEN_EGG"});
    KodeToNamaTable.insert({"DCE","DUCK_EGG"});
    KodeToNamaTable.insert({"SMH","SMALL_HOUSE"});
    KodeToNamaTable.insert({"MDH","MEDIUM_HOUSE"});
    KodeToNamaTable.insert({"LRH","LARGE_HOUSE"});
    KodeToNamaTable.insert({"HTL","HOTEL"});
    return KodeToNamaTable[Kode];
}
