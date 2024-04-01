#include "helper.hpp"
#include <bits/stdc++.h>
using namespace std;
vector<string> StringToStringList(string inputString){
    vector<string> StringList;
    string tempString;
    tempString = "";

    for(int i = 0; i<inputString.length(); i++){

        if(i == 0){
            if(inputString[i] != ' '){
                tempString = tempString + inputString[i];
                if(inputString.length() == 1){
                    StringList.push_back(tempString);
                }
            }
            
        } else {
            if(i == inputString.length()-1){
                if(inputString[i] != ' '){
                    tempString = tempString + inputString[i];
                }
                StringList.push_back(tempString);
                tempString = "";
            } else {
                if(inputString[i] == ' '){
                    if(inputString[i-1] !=' '){
                        StringList.push_back(tempString);
                        tempString = "";
                    }
                } else {
                    tempString = tempString + inputString[i];
                }
            }
        }
    }
    return StringList;
}