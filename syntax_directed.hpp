//
//  syntax_directed.hpp
//  Compile
//
//  Created by JOKER on 8/5/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#ifndef syntax_directed_hpp
#define syntax_directed_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "lexical_analyis.hpp"
struct quaternary
{
	std::string op;
	std::string arg1;
	std::string arg2;
	std::string result;
};
struct name_table
{
    struct name_table_element
    {
        std::string fun_var_name;
        std::string type;
        int offset_list;
        name_table *child_table;
    };
    name_table* parent_table;
    std::string parent_name;
    int inmed_variableNo=-1;
    std::vector<name_table_element>content;
	std::vector<quaternary>quaternary_list;
    unsigned long getSize()
    {
        return content.size();
    }
    void push_back(std::string fun_var_name,std::string type,int offset,name_table* child_table)
    {
        content.push_back({fun_var_name,type,offset,child_table});
        
    }
    void set_parent_table(name_table*parent_table)
    {
        this->parent_table=parent_table;
    }
    void set_parent_name(std::string parent_name)
    {
        this->parent_name=parent_name;
    }
    void pop_back()
    {
        content.pop_back();
    }
    name_table_element operator[](int i)
    {
        return content[i];
    }
};


void fun0(std::vector<std::string>&reductioon_stack);
void fun1(std::vector<std::string>&reductioon_stack);
void fun2(std::vector<std::string>&reductioon_stack);
void fun3(std::vector<std::string>&reductioon_stack);
void fun4(std::vector<std::string>&reductioon_stack);
void fun5(std::vector<std::string>&reductioon_stack);
void fun6(std::vector<std::string>&reductioon_stack);
void fun7(std::vector<std::string>&reductioon_stack);
void fun8(std::vector<std::string>&reductioon_stack);
void fun9(std::vector<std::string>&reductioon_stack);
void fun10(std::vector<std::string>&reductioon_stack);
void fun11(std::vector<std::string>&reductioon_stack);
void fun12(std::vector<std::string>&reductioon_stack);
void fun13(std::vector<std::string>&reductioon_stack);
void fun14(std::vector<std::string>&reductioon_stack);
void fun15(std::vector<std::string>&reductioon_stack);
void fun16(std::vector<std::string>&reductioon_stack);
void fun17(std::vector<std::string>&reductioon_stack);
void fun18(std::vector<std::string>&reductioon_stack);
void fun19(std::vector<std::string>&reductioon_stack);
void fun20(std::vector<std::string>&reductioon_stack);
void fun21(std::vector<std::string>&reductioon_stack);
void fun22(std::vector<std::string>&reductioon_stack);
void fun23(std::vector<std::string>&reductioon_stack);
void fun24(std::vector<std::string>&reductioon_stack);
void fun25(std::vector<std::string>&reductioon_stack);
void fun26(std::vector<std::string>&reductioon_stack);
void fun27(std::vector<std::string>&reductioon_stack);
void fun28(std::vector<std::string>&reductioon_stack);
void fun29(std::vector<std::string>&reductioon_stack);
void fun30(std::vector<std::string>&reductioon_stack);
void fun31(std::vector<std::string>&reductioon_stack);
void fun32(std::vector<std::string>&reductioon_stack);
void fun33(std::vector<std::string>&reductioon_stack);
void fun34(std::vector<std::string>&reductioon_stack);
void fun35(std::vector<std::string>&reductioon_stack);
void fun36(std::vector<std::string>&reductioon_stack);
void fun37(std::vector<std::string>&reductioon_stack);
void fun38(std::vector<std::string>&reductioon_stack);
void fun39(std::vector<std::string>&reductioon_stack);
void fun40(std::vector<std::string>&reductioon_stack);
void fun41(std::vector<std::string>&reductioon_stack);
void fun42(std::vector<std::string>&reductioon_stack);
void fun43(std::vector<std::string>&reductioon_stack);
void fun44(std::vector<std::string>&reductioon_stack);
void fun45(std::vector<std::string>&reductioon_stack);
void fun46(std::vector<std::string>&reductioon_stack);
void fun47(std::vector<std::string>&reductioon_stack);
void fun48(std::vector<std::string>&reductioon_stack);
void fun49(std::vector<std::string>&reductioon_stack);
void fun50(std::vector<std::string>&reductioon_stack);
void fun51(std::vector<std::string>&reductioon_stack);
void fun52(std::vector<std::string>&reductioon_stack);
void fun53(std::vector<std::string>&reductioon_stack);
void fun54(std::vector<std::string>&reductioon_stack);
void fun55(std::vector<std::string>&reductioon_stack);
void fun56(std::vector<std::string>&reductioon_stack);
void fun57(std::vector<std::string>&reductioon_stack);
void fun58(std::vector<std::string>&reductioon_stack);
void fun59(std::vector<std::string>&reductioon_stack);
void fun60(std::vector<std::string>&reductioon_stack);
void fun61(std::vector<std::string>&reductioon_stack);
void fun62(std::vector<std::string>&reductioon_stack);
void fun63(std::vector<std::string>&reductioon_stack);
void fun64(std::vector<std::string>&reductioon_stack);
void fun65(std::vector<std::string>&reductioon_stack);
void fun66(std::vector<std::string>&reductioon_stack);
void fun67(std::vector<std::string>&reductioon_stack);
void fun68(std::vector<std::string>&reductioon_stack);
void fun69(std::vector<std::string>&reductioon_stack);
void fun70(std::vector<std::string>&reductioon_stack);
void fun71(std::vector<std::string>&reductioon_stack);
void fun72(std::vector<std::string>&reductioon_stack);
void fun73(std::vector<std::string>&reductioon_stack);
void fun74(std::vector<std::string>&reductioon_stack);
void fun75(std::vector<std::string>&reductioon_stack);
void fun76(std::vector<std::string>&reductioon_stack);
void fun77(std::vector<std::string>&reductioon_stack);
void fun78(std::vector<std::string>&reductioon_stack);
void fun79(std::vector<std::string>&reductioon_stack);
void fun80(std::vector<std::string>&reductioon_stack);
void fun81(std::vector<std::string>&reductioon_stack);
void fun82(std::vector<std::string>&reductioon_stack);
void fun83(std::vector<std::string>&reductioon_stack);
void fun84(std::vector<std::string>&reductioon_stack);
void fun85(std::vector<std::string>&reductioon_stack);
void fun86(std::vector<std::string>&reductioon_stack);
void fun87(std::vector<std::string>&reductioon_stack);
void fun88(std::vector<std::string>&reductioon_stack);
void fun89(std::vector<std::string>&reductioon_stack);
void fun90(std::vector<std::string>&reductioon_stack);
void fun91(std::vector<std::string>&reductioon_stack);
void fun92(std::vector<std::string>&reductioon_stack);
void fun93(std::vector<std::string>&reductioon_stack);
void fun94(std::vector<std::string>&reductioon_stack);
void fun95(std::vector<std::string>&reductioon_stack);
void fun96(std::vector<std::string>&reductioon_stack);
void fun97(std::vector<std::string>&reductioon_stack);
void fun98(std::vector<std::string>&reductioon_stack);
void fun99(std::vector<std::string>&reductioon_stack);
void fun100(std::vector<std::string>&reductioon_stack);
void fun101(std::vector<std::string>&reductioon_stack);
void fun102(std::vector<std::string>&reductioon_stack);
void fun103(std::vector<std::string>&reductioon_stack);
void fun104(std::vector<std::string>&reductioon_stack);
void fun105(std::vector<std::string>&reductioon_stack);
void fun106(std::vector<std::string>&reductioon_stack);
void fun107(std::vector<std::string>&reductioon_stack);
void fun108(std::vector<std::string>&reductioon_stack);
void fun109(std::vector<std::string>&reductioon_stack);
void fun110(std::vector<std::string>&reductioon_stack);
void fun111(std::vector<std::string>&reductioon_stack);
void fun112(std::vector<std::string>&reductioon_stack);
void fun113(std::vector<std::string>&reductioon_stack);
void fun114(std::vector<std::string>&reductioon_stack);
void fun115(std::vector<std::string>&reductioon_stack);
void fun116(std::vector<std::string>&reductioon_stack);
void fun117(std::vector<std::string>&reductioon_stack);
void fun118(std::vector<std::string>&reductioon_stack);
void fun119(std::vector<std::string>&reductioon_stack);
void fun120(std::vector<std::string>&reductioon_stack);
void fun121(std::vector<std::string>&reductioon_stack);
void fun122(std::vector<std::string>&reductioon_stack);
void fun123(std::vector<std::string>&reductioon_stack);
void fun124(std::vector<std::string>&reductioon_stack);
void fun125(std::vector<std::string>&reductioon_stack);
void fun126(std::vector<std::string>&reductioon_stack);
void fun127(std::vector<std::string>&reductioon_stack);
void fun128(std::vector<std::string>&reductioon_stack);
void fun129(std::vector<std::string>&reductioon_stack);
void fun130(std::vector<std::string>&reductioon_stack);
void fun131(std::vector<std::string>&reductioon_stack);
void fun132(std::vector<std::string>&reductioon_stack);
void fun133(std::vector<std::string>&reductioon_stack);
void fun134(std::vector<std::string>&reductioon_stack);
void fun135(std::vector<std::string>&reductioon_stack);
void fun136(std::vector<std::string>&reductioon_stack);
void fun137(std::vector<std::string>&reductioon_stack);
void fun138(std::vector<std::string>&reductioon_stack);
void fun139(std::vector<std::string>&reductioon_stack);
void fun140(std::vector<std::string>&reductioon_stack);
void fun141(std::vector<std::string>&reductioon_stack);
void fun142(std::vector<std::string>&reductioon_stack);
void fun143(std::vector<std::string>&reductioon_stack);
void fun144(std::vector<std::string>&reductioon_stack);
void fun145(std::vector<std::string>&reductioon_stack);
void fun146(std::vector<std::string>&reductioon_stack);
void fun147(std::vector<std::string>&reductioon_stack);
void fun148(std::vector<std::string>&reductioon_stack);
void fun149(std::vector<std::string>&reductioon_stack);
void fun150(std::vector<std::string>&reductioon_stack);
void fun151(std::vector<std::string>&reductioon_stack);
void fun152(std::vector<std::string>&reductioon_stack);
void fun153(std::vector<std::string>&reductioon_stack);
void fun154(std::vector<std::string>&reductioon_stack);
void fun155(std::vector<std::string>&reductioon_stack);
void fun156(std::vector<std::string>&reductioon_stack);
void fun157(std::vector<std::string>&reductioon_stack);
void fun158(std::vector<std::string>&reductioon_stack);
void fun159(std::vector<std::string>&reductioon_stack);
void fun160(std::vector<std::string>&reductioon_stack);
void fun161(std::vector<std::string>&reductioon_stack);
void fun162(std::vector<std::string>&reductioon_stack);
void fun163(std::vector<std::string>&reductioon_stack);
void fun164(std::vector<std::string>&reductioon_stack);
void fun165(std::vector<std::string>&reductioon_stack);
void fun166(std::vector<std::string>&reductioon_stack);
void fun167(std::vector<std::string>&reductioon_stack);
void fun168(std::vector<std::string>&reductioon_stack);
void fun169(std::vector<std::string>&reductioon_stack);
void fun170(std::vector<std::string>&reductioon_stack);
void fun171(std::vector<std::string>&reductioon_stack);
void fun172(std::vector<std::string>&reductioon_stack);
void fun173(std::vector<std::string>&reductioon_stack);
void fun174(std::vector<std::string>&reductioon_stack);
void fun175(std::vector<std::string>&reductioon_stack);
void fun176(std::vector<std::string>&reductioon_stack);
void fun177(std::vector<std::string>&reductioon_stack);
void fun178(std::vector<std::string>&reductioon_stack);
void fun179(std::vector<std::string>&reductioon_stack);
void fun180(std::vector<std::string>&reductioon_stack);
void fun181(std::vector<std::string>&reductioon_stack);
void fun182(std::vector<std::string>&reductioon_stack);
void fun183(std::vector<std::string>&reductioon_stack);
void fun184(std::vector<std::string>&reductioon_stack);
void fun185(std::vector<std::string>&reductioon_stack);
void fun186(std::vector<std::string>&reductioon_stack);
void fun187(std::vector<std::string>&reductioon_stack);
void fun188(std::vector<std::string>&reductioon_stack);
void fun189(std::vector<std::string>&reductioon_stack);
void fun190(std::vector<std::string>&reductioon_stack);
void fun191(std::vector<std::string>&reductioon_stack);
void fun192(std::vector<std::string>&reductioon_stack);
void fun193(std::vector<std::string>&reductioon_stack);
void fun194(std::vector<std::string>&reductioon_stack);
void fun195(std::vector<std::string>&reductioon_stack);
void fun196(std::vector<std::string>&reductioon_stack);
void fun197(std::vector<std::string>&reductioon_stack);
void fun198(std::vector<std::string>&reductioon_stack);
void fun199(std::vector<std::string>&reductioon_stack);
void fun200(std::vector<std::string>&reductioon_stack);
void fun201(std::vector<std::string>&reductioon_stack);
void fun202(std::vector<std::string>&reductioon_stack);
void fun203(std::vector<std::string>&reductioon_stack);
void fun204(std::vector<std::string>&reductioon_stack);
void fun205(std::vector<std::string>&reductioon_stack);
void fun206(std::vector<std::string>&reductioon_stack);
void fun207(std::vector<std::string>&reductioon_stack);
void fun208(std::vector<std::string>&reductioon_stack);
void fun209(std::vector<std::string>&reductioon_stack);
void fun210(std::vector<std::string>&reductioon_stack);
void fun211(std::vector<std::string>&reductioon_stack);
extern void (*fun_list[])(std::vector<std::string>&reduction_stack);
extern name_table nt;
#endif /* syntax_directed_hpp */
