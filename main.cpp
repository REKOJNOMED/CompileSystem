
#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include "syntax_analyis.hpp"
#include "lexical_analyis.hpp"
int main()
{
//    std::fstream f1("/Users/joker/Desktop/action.txt");
//    std::fstream f2("/Users/joker/Desktop/goto.txt");
//    std::string s1,s2;
//    pair p;
//    while(f1>>s1)
//    {
//        p.status=atoi(s1.c_str());
//        f1>>s1;
//        p.input_str=s1;
//        f1>>s1;
//        ACTION.insert({p,s1});
//    }
//    while(f2>>s2)
//    {
//        p.status=atoi(s2.c_str());
//        f2>>s2;
//        p.input_str=s2;
//        f2>>s2;
//        GOTO.insert({p,s2});
//    }
//    GRAMMER_INIT("/Users/joker/Desktop/grammer.txt");
//    std::vector<std::string> pc={"INT","IDENTIFIER","'('","')'","'{'","INT","IDENTIFIER","';'","'}'","#"};
//    parsing(pc);
    TOKEN_INIT("token.txt");
    std::fstream f("code.txt");
    std::string s;
    std::vector<word> pc;
    while(getline(f,s))
    {
        word w;
        int i=0;
        while(i!=s.size())
        {
            w=Lexical_analyis(s, i);
            if(w.a.size()!=0)
           {
               pc.push_back(w);
               std::cout<<w.a<<" "<<w.b<<std::endl;
           }
        }
    }
    pc.push_back({"#","#"});
        std::fstream f1("action.txt");
        std::fstream f2("goto.txt");
        std::string s1,s2;
        pair p;
        while(f1>>s1)
        {
            p.status=atoi(s1.c_str());
            f1>>s1;
            p.input_str=s1;
            f1>>s1;
            ACTION.insert({p,s1});
        }
        while(f2>>s2)
        {
            p.status=atoi(s2.c_str());
            f2>>s2;
            p.input_str=s2;
            f2>>s2;
            GOTO.insert({p,s2});
        }
        GRAMMER_INIT("grammer.txt");
        parsing(pc);
//    Syntax_analyis_init();
}
