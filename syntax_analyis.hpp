//
//  syntax_analyis.hpp
//  Compile
//
//  Created by JOKER on 29/3/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#ifndef syntax_analyis_hpp
#define syntax_analyis_hpp

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "lexical_analyis.hpp"
#include "syntax_directed.hpp"
struct pair
{
    int status;
    std::string input_str;
    bool operator<(const pair &other)const
    {
        if(this->status<other.status)
              return true;
        else if(this->status==other.status)
        {
            if(this->input_str<other.input_str)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
struct production
{
    std::string left;
    std::vector<std::string> right;
};
template <class T>
struct copy_pair
{
    T from;
    T to;
};
struct status_event
{
public:
    std::string left;
    std::vector<std::string> right;
    int pos;
    std::string except_symbol;
    bool operator <(const status_event&other)const
    {
        if(this->left<other.left)
            return true;
        else if(this->left==other.left)
        {
            if(this->right<other.right)
                return true;
            else if(this->right==other.right)
            {
                if(this->pos<other.pos)
                    return true;
                else if(this->pos==other.pos)
                {
                    if(this->except_symbol<other.except_symbol)
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }
    bool operator==(const status_event&other)const
    {
        if(this->left==other.left&&this->right==other.right&&this->pos==other.pos&&this->except_symbol==other.except_symbol)
            return true;
        else
            return false;
    }
};
std::set<status_event> Closure(std::set<status_event>I);
void parsing(std::vector<word> s);
std::set<status_event> Goto(std::set<status_event>I,std::string s);
void Syntax_analyis_init();
void TOKEN_INIT(std::string filename);
void GRAMMER_INIT(std::string filename);
extern std::map<pair,std::string>ACTION;
extern std::map<pair,std::string>GOTO;
#endif /* syntax_analyis_hpp */
