//
//  lexical_analyis.hpp
//  Compile System
//
//  Created by JOKER on 22/3/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#ifndef lexical_analyis_hpp
#define lexical_analyis_hpp

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#define KEYWORD_SIZE 100
#define SYMBOL_SIZE 100
struct word
{
    std::string a;
    std::string b;
};
word Lexical_analyis(std::string& line,int &i);
bool isDigital(std::string word);
bool isID(std::string word);



#endif /* lexical_analyis_hpp */
