#include "../Header/helper.hpp"
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
// EXTRA FUNCTIONS
bool isAllDigits(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
