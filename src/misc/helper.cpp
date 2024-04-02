#include "helper.hpp"
#include <bits/stdc++.h>
using namespace std;
vector<string> StringToStringList(string inputString){
    vector<string> StringList;
    string tempString;
    tempString = "";

    for(int i = 0; i<inputString.length(); i++){
        if(i == inputString.length()-1){
            tempString = tempString + inputString[i];
            StringList.push_back(tempString);
            tempString = "";
        }
        else if(inputString[i] !=' '){
            tempString = tempString + inputString[i];
        } else {
            StringList.push_back(tempString);
            tempString = "";
        }
    }
    return StringList;
}