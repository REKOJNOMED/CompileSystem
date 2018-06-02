
//
//  lexical_analyis.cpp
//  Compile System
//
//  Created by JOKER on 22/3/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#include "lexical_analyis.hpp"

std::vector<std::string> specifier={"int","float","double","char","long","signed","short","unsigned"};
std::map<std::string,std::string> keyword={{"auto","AUTO"},{"break","BREAK"},{"case","CASE"},{"const","CONST"},{"continue","STRUCT"},{"default","DEFAULT"},{"do","DO"},
    {"else","ELSE"},{"enum","ENUM"},{"extern","EXTERN"},{"float","FLOAT"},{"for","FOR"},
    {"goto","GOTO"},{"if","IF"},{"register","REGISTER"},{"return","RETURN"},{"sizeof","SIZEOF"},
    {"static","STATIC"},{"struct","STRUCT"},{"switch","SWITCH"},{"typedef","TYPEDEF"},
    {"union","UNION"},{"void","VOID"},{"volatile","VOLATILE"},{"while","WHILE"}
};
std::map<std::string,std::string> symbol={{">>=","RIGHT_ASSIGN"},{"<<=","LEFT_ASSIGN"},{"+=","ADD_ASSIGN"},{"-=","SUB_ASSIGN"},{"*=","MUL_ASSIGN"},{"/=","DIV_ASSIGN"},{"%=","MOD_ASSIGN"},{"&=","AND_ASSIGN"},{"^=","XOR_ASSIGN"},{"|=","OR_ASSIGN"},{">>","RIGHT_OP"},
    {"<<","LEFT_OP"},{"++","INC_OP"},{"--","DEC_OP"},{"->","PTR_OP"},{"&&","AND_OP"},{"||","OR_OP"},{"<=","LE_OP"},{">=","GE_OP"},{"==","EQ_OP"},{"!=","NE_OP"},{";","';'"},{"{","'{'"},{"}","'}'"},{",","','"},{":","':'"}
    ,{"=","'='"},{"(","'('"},{")","')'"},{"[","'['"},{"]","']'"},{".","'.'"},{"&","'&'"},{"!","'!'"},{"~","'~'"},{"-","'-'"},{"+","'+'"},{"*","'*'"},{"/","'/'"},
    {"%","'%'"},{"<","'<'"},{">","'>'"},{"^","'^'"},{"|","'|'"},{"?","'?'"}
};
std::vector<std::string> varlist;
std::vector<std::string>funlist={"printf","scanf"};
void StructFamilyHandle(std::string word)
{
    for(int i=0;i!=word.size();i++){
        if(word[i]=='.')
        {
            std::cout<<"(IDENTIFIER,"+word.substr(0,i)+")"<<std::endl;
            std::cout<<"(.,.)"<<std::endl;
            std::cout<<"(IDENTIFIER,"+word.substr(i+1)+")"<<std::endl;
            break;
        }
    }
}

bool isInt(std::string word)
{
    
    for(int i=0;i!=word.size();i++)
    {
        if((word[i]>='0'&&word[i]<='9')) continue;
        else
            return false;
    }
    return true;
}
bool isDecimal(std::string word)
{
    int flag=0;
    for(int i=0;i!=word.size();i++)
    {
        if((word[i]>='0'&&word[i]<='9')) continue;
        else if (word[i]=='.') {flag=1;continue;}
        else
            return false;
    }
    if(flag==1)
        return true;
    else
        return false;
}
bool isID(std::string word)
{
    if(!((word[0]>='a'&&word[0]<='z')||(word[0]>='A'&&word[0]<='Z')))
        return false;
    for(int i=1;i!=word.size();i++)
    {
        if((word[i]>='0'&&word[i]<='9')||(word[i]>='a'||word[i]<='z')||(word[i]>='A'&&word[i]<='Z')||word[i]=='_')
            continue;
        else
            return false;
    }
    return true;
}
bool isString(std::string word)
{
    if(word[0]=='"')
        return true;
    else
        return false;
}
std::string getToken(std::string const& line, int& i)
{
    if(i<line.size()){
            int j=i;
    switch (line[j]) {
        case ';':
            j=j+1;
            break;
        case '{':
            j=j+1;
            break;
        case '}':
            j=j+1;
            break;
        case ',':
            j=j+1;
            break;
        case ':':
            j=j+1;
            break;
        case '=':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '(':
            j=j+1;
            break;
        case ')':
            j=j+1;
            break;
        case '[':
            j=j+1;
            break;
        case ']':
            j=j+1;
            break;
        case  '.':
            j=j+1;
            break;
        case '&':
            j=j+1;
            if(line[j]=='&')
                j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '~':
            j=j+1;
            break;
        case '-':
            j=j+1;
            if(line[j]=='>')
                j=j+1;
            if(line[j]=='-')
                j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '+':
            j=j+1;
            if(line[j]=='+')
                j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '*':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '/':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '%':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '<':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            if(line[j]=='<')
            {
                j=j+1;
                if(line[j]=='=')
                    j=j+1;
            }
            break;
        case '>':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            if(line[j]=='>')
            {
                j=j+1;
                if(line[j]=='=')
                    j=j+1;
            }
            break;
        case '^':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '!':
            j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '|':
            j=j+1;
            if(line[j]=='|')
                j=j+1;
            if(line[j]=='=')
                j=j+1;
            break;
        case '?':
            j=j+1;
            break;
        case '"':
            j=j+1;
            while(line[j]!='"')
                j++;
            j++;
            break;
        default:
            if((line[j]>='a'&&line[j]<'z')||(line[j]>='A'&&line[j]<'Z')||line[j]=='_')
            {
                while((line[j]>='a'&&line[j]<'z')||(line[j]>='0'&&line[j]<='9')||(line[j]>='A'&&line[j]<='Z')||line[j]=='_')
                {
                    j++;
                }
            }
            else
            {
                while((line[j]>='0'&&line[j]<='9')||line[j]=='.')
                {
                    j++;
                }
            }
            break;
    }

    std::string substr=line.substr(i,j-i);
    while(line[j]==' ')
        j++;
    i=j;
    return substr;
    }
    else
        return "";
}
void ParamHandle(std::string&line,int &i)
{
    std::string token1;
    std::string token2;
    do
    {
        token1=getToken(line, i);
        if(token1==")")
        {
            std::cout<<"("+symbol[token1]+","+token1+")"<<std::endl;
            break;
        }
        for(int k=0;k!=specifier.size();k++)
        {
            if(token1==specifier[k])
            {
                std::string upper;
                std::transform(token1.begin(), token1.end(), upper.begin(), ::toupper);
                std::cout<<"("+upper+","+specifier[k]+")"<<std::endl;
                token1=getToken(line,i);
                if(token1=="*")
                {
                    std::cout<<"(PTR_OP,"+token1+")"<<std::endl;
                    token1=getToken(line, i);
                }
                 token2=getToken(line,i);
                varlist.push_back(token1);
                std::cout<<"(IDENTIFIER,"+token1+")"<<std::endl;
                std::cout<<"("+symbol[token2]+","+token2+")"<<std::endl;
                break;
            }
        }
    }while(token2!=")");
}

 word Lexical_analyis(std::string& line,int&i)
{
    int flag=0;
    struct word w;
        while(line[i]==' ')
            i++;
    if(line.substr(i,2)=="//"||!(i<line.size()))
    {
        i=line.size();
        return w;
    }
    else
    {
            std::string token=getToken(line, i);

                for(std::vector<std::string>::iterator it=specifier.begin();it!=specifier.end();it++)
                {
                    if(token==*it)
                    {
                        std::transform(token.begin(), token.end(), back_inserter(w.a), ::toupper);
                        w.b=token;
                        return w;
                    }
                }


                for(std::map<std::string,std::string>::iterator it=keyword.begin();it!=keyword.end();it++)
                {
                    if(token==it->first)
                    {
                        
                        w.a=it->second;
                        w.b=it->first;
                        return w;
                        
                    }
                }

                for(std::map<std::string,std::string>::iterator it=symbol.begin();it!=symbol.end();it++)
                {
                    if(token==it->first)
                    {
                        w.a=it->second;
                        w.b=it->first;
                        return w;
                    }
                }

            if(isInt(token))
            {
                w.a="CONSTANT";
                w.b=token;
                return w;
            }
            if(isDecimal(token))
            {
                w.a="CONSTANT";
                w.b=token;
                return w;
            }
            if(isID(token))
            {
                w.a="IDENTIFIER";
                w.b=token;
                return w;
            }
            if(isString(token))
            {
                w.a="STRING_LITERAL";
                w.b=token;
                return w;
            }
        return w;
        }
    return w;
}









