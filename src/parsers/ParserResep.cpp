#include "ParserResep.hpp"
#include "../exceptions/Exceptions.hpp"
#include <bits/stdc++.h>
void ParserResep::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw RecipeConfigMissingException();
        return;
    }
    cout<<"file recipe kebaca\n";
}

void ParserResep::ClearParserData()
{
        this->recipeID.clear();
        this->recipeCode.clear();
        this->recipeName.clear();
        this->recipePrice.clear();
        this->recipeMaterials.clear();
}
