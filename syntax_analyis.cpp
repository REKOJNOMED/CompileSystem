//
//  syntax_analyis.cpp
//  Compile
//
//  Created by JOKER on 29/3/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#include "syntax_analyis.hpp"
#include "assembler.hpp"
#include <algorithm>
extern std::vector<std::string> val_stack;
std::map<pair,std::string>ACTION={};
std::map<pair,std::string>GOTO={};
std::vector<production>PRODUCTION={};
std::map<std::string,std::set<std::string>> V_FIRST={};
std::set<std::string>V={};
std::set<std::string>T={"#"};
std::map<std::set<status_event>,int> Collection;
std::string char2str(char c)
{
    std::string s;
    s="0";
    s[0]=c;
    return s;
}
std::string num2str(int num)
{
    std::string s;
    while(num!=0)
    {
        s.insert(s.begin(), '0'+num%10);
        num=num/10;
    }
    return s;
}
void Collenction_init(std::string s_init)
{
    status_event se;
    se.left="Z";
    se.right.push_back(s_init);
    se.pos=0;
    se.except_symbol="#";
    int count=0;
    Collection.insert({Closure({se}),count++});
    unsigned long last_size=-1;
    unsigned long size=0;
    while(last_size!=size)
    {
        last_size=size;
        for(auto it=Collection.begin();it!=Collection.end();it++)
        {
            for(auto ita=V.begin();ita!=V.end();ita++)
            {
                std::set<status_event>c=Goto(it->first, *ita);
                if(!c.empty())
                {
                    auto f=Collection.begin();
                    for(;f!=Collection.end();f++)
                    {
                        if(c==f->first)
                            break;
                    }
                    if(f==Collection.end())
                    {
                        Collection.insert({c,count++});
                    }
                    pair p={it->second,*ita};
                    GOTO.insert({p,num2str(Collection[c])});
                    
                    for(auto it=c.begin();it!=c.end();it++)
                    {
                        if(it->pos==it->right.size())
                        {
                            int i;
                            for(i=0;i!=PRODUCTION.size();i++)
                            {
                                if(PRODUCTION[i].left==it->left&&PRODUCTION[i].right==it->right)
                                    break;
                            }
                            if(PRODUCTION[i].left=="Z"&&(PRODUCTION[i].right.size()==1&&PRODUCTION[i].right[0]==s_init))
                                ACTION.insert({{Collection[c],it->except_symbol},"acc"});
                            else
                                ACTION.insert({{Collection[c],it->except_symbol},"r"+num2str(i+1)});
                        }
                    }
                }
            }
            for(auto ita=T.begin();ita!=T.end();ita++)
            {
                std::set<status_event>c=Goto(it->first, *ita);
                if(!c.empty())
                {
                    auto f=Collection.begin();
                    for(;f!=Collection.end();f++)
                    {
                        if(c==f->first)
                            break;
                    }
                    if(f==Collection.end())
                    {
                        Collection.insert({c,count++});
                    }
                    pair p={it->second,*ita};
                    ACTION.insert({p,"S"+num2str(Collection[c])});
                    for(auto it=c.begin();it!=c.end();it++)
                    {
                        if(it->pos==it->right.size())
                        {
                            int i;
                            for(i=0;i!=PRODUCTION.size();i++)
                            {
                                if(PRODUCTION[i].left==it->left&&PRODUCTION[i].right==it->right)
                                    break;
                            }
                            if(PRODUCTION[i].left=="Z"&&(PRODUCTION[i].right.size()==1&&PRODUCTION[i].right[0]==s_init))
                                ACTION.insert({{Collection[c],it->except_symbol},"acc"});
                            else
                                ACTION.insert({{Collection[c],it->except_symbol},"r"+num2str(i+1)});
                        }
                    }
                }
            }
            
        }
        size=Collection.size();
    }
}
void FIRST_INIT()
{
    int count=0;
    int last_count=-1;
    while(last_count!=count)
    {
        last_count=count;
        for(auto it=PRODUCTION.begin();it!=PRODUCTION.end();it++)
        {
            std::string v=it->left;
            std::vector<std::string> right=it->right;
            if(right.size()==1&&right[0]=="\0")
            {
                V_FIRST[v].insert("\0");
            }
         \
            auto ita=find(T.begin(),T.end(),it->right[0]);
            if(!(ita==T.end()))
            {
                V_FIRST[v].insert(it->right[0]);
            }
            else
            {
              
                for(auto itb=V_FIRST[right[0]].begin();itb!=V_FIRST[right[0]].end();itb++)
                {
                    V_FIRST[v].insert(*itb);
                }
               
                for(int i=0;i!=right.size();i++)
                {
                    auto itc=find(V_FIRST[right[i]].begin(),V_FIRST[right[i]].end(),"\0");
                    if(!(itc==V_FIRST[right[i]].end()))
                    {
                        if(i+1==right.size())
                                V_FIRST[v].insert(0);
                        else
                        {
                            for(auto itb=V_FIRST[right[i+1]].begin();itb!=V_FIRST[right[i+1]].end();itb++)
                            {
                                V_FIRST[v].insert(*itb);
                            }
                        }
                    }
                    else
                        break;
                }
            }
        }
        count=0;
        for(auto it=V_FIRST.begin();it!=V_FIRST.end();it++)
        {
            count+=it->second.size();
        }
    }
}
std::set<std::string> First(std::vector<std::string> s)
{
    std::set<std::string> first;
    int index;
    auto it=find(T.begin(),T.end(),s[0]);
    if(!(it==T.end()))
    {
        first.insert(s[0]);
    }
    else
    {
            for(auto ite=V_FIRST[s[0]].begin();ite!=V_FIRST[s[0]].end();ite++)
        {
            first.insert(*ite);
        }
        for(index=0;index!=s.size();index++)
        {
            auto itb=find(V_FIRST[s[index]].begin(),V_FIRST[s[index]].end(),"\0");
            if(!(itb==V_FIRST[s[index]].end()))
            {
                if(index+1==s.size())
                {
                    first.insert("\0");
                    index++;
                    break;
                }
                for(auto ite=V_FIRST[s[index+1]].begin();ite!=V_FIRST[s[index+1]].end();ite++)
                {
                    first.insert(*ite);
                }
            }
            else
                break;
        }
    }
    return first;
}
std::set<status_event> Closure(std::set<status_event>I)
{
    std::set<status_event>last_cI={};
    std::set<status_event> cI=I;
    while(last_cI.size()!=cI.size())
    {
        last_cI=cI;
        for(std::set<status_event>::iterator it=last_cI.begin();it!=last_cI.end();it++)
        {
            status_event se=*it;
            if(it->pos!=it->right.size())
            {
                std::string v=it->right[it->pos];
                std::vector<std::string> beta;
                for(auto ite=it->right.begin()+it->pos+1;ite!=it->right.end();ite++)
                {
                    beta.push_back(*ite);
                }
            
                beta.push_back(it->except_symbol);
                std::set<std::string> temp=First(beta);
                for(std::vector<production>::iterator ite=PRODUCTION.begin();ite!=PRODUCTION.end();ite++)
                {
                    if(v==ite->left)
                    {

                        for(auto itg=temp.begin();itg!=temp.end();itg++)
                        {
                            status_event new_event;
                            new_event.left=v;
                            new_event.right=ite->right;
                            new_event.pos=0;
                            new_event.except_symbol=*itg;
                            cI.insert(new_event);
                        }

                    }
                }
            }
        }
    }
    return cI;
}
std::set<status_event> Goto(std::set<status_event>I,std::string s)
{
    std::set<status_event>cI;
    for(auto it=I.begin();it!=I.end();it++)
    {
        if(it->pos<it->right.size()&&it->right[it->pos]==s)
        {
            status_event new_event;
            new_event.left=it->left;
            new_event.right=it->right;
            new_event.pos=it->pos+1;
            new_event.except_symbol=it->except_symbol;
            cI.insert(new_event);
        }
    }
    
    return Closure(cI);
}
void print_vector(std::vector<std::string>const& vs,unsigned long begin=-1,unsigned long end=-1)
{
    if(begin==-1) begin=0;
    if(end==-1) end=vs.size();
    for(auto it=vs.begin()+begin;it!=vs.begin()+end;it++)
    {
        std::cout<<*it+" ";
    }
}
void parsing(std::vector<word> s)
{
    std::vector<int> status_stack;
    std::vector<std::string> char_stack;
    std::vector<std::string>reduction_stack;
    status_stack.push_back(0);
    char_stack.push_back("#");
    int index=0;
    struct pair status_tf;
    std::string status;
//    print_vector(s);
//    std::cout<<std::endl;
    
    while(index<s.size())
    {
        status_tf.status=status_stack.back();
        status_tf.input_str=s[index].a;
        status=ACTION[status_tf];
        if(status[0]=='S')
        {
            status_stack.push_back(atoi(status.substr(1).c_str()));
            char_stack.push_back(status_tf.input_str);
            
            reduction_stack.push_back(s[index].b);
            
            index++;
        }
        else if(status[0]=='r')
        {
            int product_index=atoi(status.substr(1).c_str())-1;
            std::string left=PRODUCTION[product_index].left;
            std::vector<std::string> right=PRODUCTION[product_index].right;
            std::string temp1;
            
            std::cout<<left+"->";print_vector(right);std::cout<<" "<<product_index<<std::endl;
            fun_list[product_index](reduction_stack);
            
            unsigned long size=right.size();
            while(size!=0)
            {
                status_stack.pop_back();
                char_stack.pop_back();
                reduction_stack.pop_back();
                size--;
            }
            status_tf.status=status_stack.back();
            status_tf.input_str=left;
            
            status=GOTO[status_tf];
            
            status_stack.push_back(atoi(status.c_str()));
            char_stack.push_back(status_tf.input_str);
            reduction_stack.push_back(status_tf.input_str);
//            print_vector(char_stack,1);
//            print_vector(s,index);
//            std::cout<<std::endl;
        }
        else if(status=="acc")
        {
            fun_list[211](reduction_stack);
			assembling(nt);
            return ;
        }
    }
}
void Syntax_analyis_init()
{
    TOKEN_INIT("/Users/joker/Desktop/token.txt");
    GRAMMER_INIT("/Users/joker/Desktop/grammer.txt");
    FIRST_INIT();
    Collenction_init("translation_unit");
    for(auto it=ACTION.begin();it!=ACTION.end();it++)
    {
        std::cout<<it->first.status<<" "<<it->first.input_str<<" "<<it->second<<std::endl;
    }
    for(auto it=GOTO.begin();it!=GOTO.end();it++)
    {
        std::cout<<it->first.status<<" "<<it->first.input_str<<" "<<it->second<<std::endl;
    }
}
void TOKEN_INIT(std::string filename)
{
    std::fstream f(filename);
    std::string s;
    while(f>>s)
    {
        if(s[0]>='A'&&s[0]<='Z')
        {
            T.insert(s);
        }
        else
        {
            std::string subs=s.substr(1,s.size()-2);
            subs.insert(0,"'");
            subs.append("'");
            T.insert(subs);
        }
    }
}
void GRAMMER_INIT(std::string filename)
{
    std::fstream f(filename);
    std::string s;
    std::string s2;
    while(f>>s)
    {
        std::string left=s;
        V.insert(s);
        V_FIRST.insert({s,{}});
        std::vector<std::string>right;
        f>>s;
        while(s!=";")
        {
            s2="";
            right.clear();
            while(f>>s&&s!="|"&&s!=";")
            {
                s2=s2+s+" ";
                right.push_back(s);
                if(std::find(T.begin(),T.end(),s)==T.end())
                {
                    V.insert(s);
                    V_FIRST.insert({s,{}});
                }
            }
            production pro;
            pro.left=left;
            pro.right=right;
            PRODUCTION.push_back(pro);
        }
        
    }
    PRODUCTION.push_back({"Z",{"translation_unit"}});
}
