//
//  syntax_directed.cpp
//  Compile
//
//  Created by JOKER on 8/5/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#include "syntax_directed.hpp"

name_table nt;
name_table* tblptr=&nt;

std::vector<std::string>val_stack;
unsigned int jmp_count=0;
std::vector<unsigned int>unsolved_false_list;
std::vector<unsigned int>unsolved_true_list;
unsigned int while_cal_addr;
void (*fun_list[])(std::vector<std::string>&word_list)={fun0,fun1,fun2,fun3,fun4,fun5,fun6,fun7,fun8,fun9,fun10,fun11,fun12,fun13,fun14,fun15,fun16,fun17,fun18,fun19,fun20,fun21,fun22,fun23,fun24,fun25,fun26,fun27,fun28,fun29,fun30,fun31,fun32,fun33,fun34,fun35,fun36,fun37,fun38,fun39,fun40,fun41,fun42,fun43,fun44,fun45,fun46,fun47,fun48,fun49,fun50,fun51,fun52,fun53,fun54,fun55,fun56,fun57,fun58,fun59,fun60,fun61,fun62,fun63,fun64,fun65,fun66,fun67,fun68,fun69,fun70,fun71,fun72,fun73,fun74,fun75,fun76,fun77,fun78,fun79,fun80,fun81,fun82,fun83,fun84,fun85,fun86,fun87,fun88,fun89,fun90,fun91,fun92,fun93,fun94,fun95,fun96,fun97,fun98,fun99,fun100,fun101,fun102,fun103,fun104,fun105,fun106,fun107,fun108,fun109,fun110,fun111,fun112,fun113,fun114,fun115,fun116,fun117,fun118,fun119,fun120,fun121,fun122,fun123,fun124,fun125,fun126,fun127,fun128,fun129,fun130,fun131,fun132,fun133,fun134,fun135,fun136,fun137,fun138,fun139,fun140,fun141,fun142,fun143,fun144,fun145,fun146,fun147,fun148,fun149,fun150,fun151,fun152,fun153,fun154,fun155,fun156,fun157,fun158,fun159,fun160,fun161,fun162,fun163,fun164,fun165,fun166,fun167,fun168,fun169,fun170,fun171,fun172,fun173,fun174,fun175,fun176,fun177,fun178,fun179,fun180,fun181,fun182,fun183,fun184,fun185,fun186,fun187,fun188,fun189,fun190,fun191,fun192,fun193,fun194,fun195,fun196,fun197,fun198,fun199,fun200,fun201,fun202,fun203,fun204,fun205,fun206,fun207,fun208,fun209,fun210,fun211};
void fun0(std::vector<std::string>&reductioon_stack){val_stack.push_back(reductioon_stack.back());if(*(reductioon_stack.end()-3)=="while") while_cal_addr=(unsigned int)tblptr->quaternary_list.size();}
void fun1(std::vector<std::string>&reductioon_stack){val_stack.push_back(reductioon_stack.back());}
void fun2(std::vector<std::string>&reductioon_stack){val_stack.push_back(reductioon_stack.back());}
void fun3(std::vector<std::string>&reductioon_stack){}
void fun4(std::vector<std::string>&reductioon_stack){}
void fun5(std::vector<std::string>&reductioon_stack){
	std::string pos = val_stack.back();
	val_stack.pop_back();
	std::string id = val_stack.back();
	val_stack.pop_back();
	val_stack.push_back(id + "[" + pos + "]");
}
void fun6(std::vector<std::string>&reductioon_stack){
	tblptr->quaternary_list.push_back({ "invoke",val_stack.back(),"","" });
	val_stack.pop_back();
}
void fun7(std::vector<std::string>&reductioon_stack){
	std::string arg;
	while (val_stack.size() > 1)
	{
		arg =  val_stack.back()+","+arg;
		val_stack.pop_back();
	}
	arg.pop_back();
	tblptr->quaternary_list.push_back({"invoke",val_stack.back(),arg,""});
	val_stack.pop_back();
}
void fun8(std::vector<std::string>&reductioon_stack){}
void fun9(std::vector<std::string>&reductioon_stack){}
void fun10(std::vector<std::string>&reductioon_stack){}
void fun11(std::vector<std::string>&reductioon_stack){}
void fun12(std::vector<std::string>&reductioon_stack){}
void fun13(std::vector<std::string>&reductioon_stack){}
void fun14(std::vector<std::string>&reductioon_stack){}
void fun15(std::vector<std::string>&reductioon_stack){}
void fun16(std::vector<std::string>&reductioon_stack){}
void fun17(std::vector<std::string>&reductioon_stack){
	std::string id=val_stack.back();
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.push_back("&" + id);
}
void fun18(std::vector<std::string>&reductioon_stack){}
void fun19(std::vector<std::string>&reductioon_stack){}
void fun20(std::vector<std::string>&reductioon_stack){
	val_stack.push_back(reductioon_stack.back());
}
void fun21(std::vector<std::string>&reductioon_stack){}
void fun22(std::vector<std::string>&reductioon_stack){}
void fun23(std::vector<std::string>&reductioon_stack){}
void fun24(std::vector<std::string>&reductioon_stack){}
void fun25(std::vector<std::string>&reductioon_stack){}
void fun26(std::vector<std::string>&reductioon_stack){}
void fun27(std::vector<std::string>&reductioon_stack){}
void fun28(std::vector<std::string>&reductioon_stack){}
void fun29(std::vector<std::string>&reductioon_stack){
    tblptr->inmed_variableNo++;
    std::string temp_name="t"+std::to_string(tblptr->inmed_variableNo);
    tblptr->push_back(temp_name, "int", 0, NULL);
    tblptr->quaternary_list.push_back({"*",*(val_stack.end()-2),*(val_stack.end()-1),temp_name});
    val_stack.pop_back();
    val_stack.pop_back();
    val_stack.push_back(temp_name);
}
void fun30(std::vector<std::string>&reductioon_stack){
	tblptr->inmed_variableNo++;
	std::string temp_name = "t" + std::to_string(tblptr->inmed_variableNo);
	tblptr->push_back(temp_name, "int", 0, NULL);
	tblptr->quaternary_list.push_back({ "/",*(val_stack.end() - 2),*(val_stack.end() - 1),temp_name });
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.push_back(temp_name);
}
void fun31(std::vector<std::string>&reductioon_stack){}
void fun32(std::vector<std::string>&reductioon_stack){}
void fun33(std::vector<std::string>&reductioon_stack){
    tblptr->inmed_variableNo++;
    std::string temp_name="t"+std::to_string(tblptr->inmed_variableNo);
    tblptr->push_back(temp_name, "int", 0, NULL);
    tblptr->quaternary_list.push_back({"+",*(val_stack.end()-2),*(val_stack.end()-1),temp_name});
    val_stack.pop_back();
    val_stack.pop_back();
    val_stack.push_back(temp_name);
}
void fun34(std::vector<std::string>&reductioon_stack){
	tblptr->inmed_variableNo++;
	std::string temp_name = "t" + std::to_string(tblptr->inmed_variableNo);
	tblptr->push_back(temp_name, "int", 0, NULL);
	tblptr->quaternary_list.push_back({ "-",*(val_stack.end() - 2),*(val_stack.end() - 1),temp_name });
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.push_back(temp_name);
}
void fun35(std::vector<std::string>&reductioon_stack){}
void fun36(std::vector<std::string>&reductioon_stack){}
void fun37(std::vector<std::string>&reductioon_stack){}
void fun38(std::vector<std::string>&reductioon_stack){}
void fun39(std::vector<std::string>&reductioon_stack){
        tblptr->inmed_variableNo++;
    std::string temp_name="t"+std::to_string(tblptr->inmed_variableNo);
    tblptr->push_back(temp_name, "int", 0, NULL);
    tblptr->quaternary_list.push_back({"<",*(val_stack.end()-2),*(val_stack.end()-1),"<"});
    val_stack.pop_back();
    val_stack.pop_back();
    val_stack.push_back("<");
    jmp_count++;
}
void fun40(std::vector<std::string>&reductioon_stack){
	tblptr->inmed_variableNo++;
	std::string temp_name = "t" + std::to_string(tblptr->inmed_variableNo);
	tblptr->push_back(temp_name, "int", 0, NULL);
	tblptr->quaternary_list.push_back({ ">",*(val_stack.end() - 2),*(val_stack.end() - 1),">" });
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.push_back(">");
	jmp_count++;
}
void fun41(std::vector<std::string>&reductioon_stack){}
void fun42(std::vector<std::string>&reductioon_stack){}
void fun43(std::vector<std::string>&reductioon_stack){}
void fun44(std::vector<std::string>&reductioon_stack){}
void fun45(std::vector<std::string>&reductioon_stack){}
void fun46(std::vector<std::string>&reductioon_stack){}
void fun47(std::vector<std::string>&reductioon_stack){}
void fun48(std::vector<std::string>&reductioon_stack){}
void fun49(std::vector<std::string>&reductioon_stack){}
void fun50(std::vector<std::string>&reductioon_stack){}
void fun51(std::vector<std::string>&reductioon_stack){}
void fun52(std::vector<std::string>&reductioon_stack){}
void fun53(std::vector<std::string>&reductioon_stack){}
void fun54(std::vector<std::string>&reductioon_stack){}
void fun55(std::vector<std::string>&reductioon_stack){}
void fun56(std::vector<std::string>&reductioon_stack){}
void fun57(std::vector<std::string>&reductioon_stack){}
void fun58(std::vector<std::string>&reductioon_stack){}
void fun59(std::vector<std::string>&reductioon_stack){
    tblptr->quaternary_list.push_back({"assign",*(val_stack.end()-1),"",*(val_stack.end()-2)});
    val_stack.pop_back();
    val_stack.pop_back();
}
void fun60(std::vector<std::string>&reductioon_stack){}
void fun61(std::vector<std::string>&reductioon_stack){}
void fun62(std::vector<std::string>&reductioon_stack){}
void fun63(std::vector<std::string>&reductioon_stack){}
void fun64(std::vector<std::string>&reductioon_stack){}
void fun65(std::vector<std::string>&reductioon_stack){}
void fun66(std::vector<std::string>&reductioon_stack){}
void fun67(std::vector<std::string>&reductioon_stack){}
void fun68(std::vector<std::string>&reductioon_stack){}
void fun69(std::vector<std::string>&reductioon_stack){}
void fun70(std::vector<std::string>&reductioon_stack){}
void fun71(std::vector<std::string>&reductioon_stack){
    if(*(reductioon_stack.end()-3)=="if")
    {
        tblptr->quaternary_list.push_back({"if_false",*(val_stack.end()-1),"",""});
        jmp_count++;
        unsolved_false_list.push_back((int)tblptr->quaternary_list.size()-1);
        val_stack.pop_back();
    }
    else if(*(reductioon_stack.end()-3)=="while")
    {
        tblptr->quaternary_list.push_back({"if_false",*(val_stack.end()-1),"",""});
        unsolved_false_list.push_back((int)tblptr->quaternary_list.size()-1);
		val_stack.pop_back();
    }
}
void fun72(std::vector<std::string>&reductioon_stack){}
void fun73(std::vector<std::string>&reductioon_stack){}
void fun74(std::vector<std::string>&reductioon_stack){}
void fun75(std::vector<std::string>&reductioon_stack){
	if (!val_stack.empty())
	{
		tblptr->push_back(*(val_stack.end() - 1), *(val_stack.end() - 2), 0, NULL); val_stack.pop_back(); val_stack.pop_back();
	}
}
void fun76(std::vector<std::string>&reductioon_stack){}
void fun77(std::vector<std::string>&reductioon_stack){}
void fun78(std::vector<std::string>&reductioon_stack){}
void fun79(std::vector<std::string>&reductioon_stack){}
void fun80(std::vector<std::string>&reductioon_stack){}
void fun81(std::vector<std::string>&reductioon_stack){}
void fun82(std::vector<std::string>&reductioon_stack){}
void fun83(std::vector<std::string>&reductioon_stack){}
void fun84(std::vector<std::string>&reductioon_stack){}
void fun85(std::vector<std::string>&reductioon_stack){
	tblptr->push_back(*(val_stack.end() - 2), *(val_stack.end() - 3), 0, NULL);
	tblptr->quaternary_list.push_back({ "assign",*(val_stack.end() - 1),"",*(val_stack.end() - 2) });
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.pop_back();
}
void fun86(std::vector<std::string>&reductioon_stack){}
void fun87(std::vector<std::string>&reductioon_stack){}
void fun88(std::vector<std::string>&reductioon_stack){}
void fun89(std::vector<std::string>&reductioon_stack){}
void fun90(std::vector<std::string>&reductioon_stack){}
void fun91(std::vector<std::string>&reductioon_stack){ val_stack.push_back(reductioon_stack.back()); }
void fun92(std::vector<std::string>&reductioon_stack){}
void fun93(std::vector<std::string>&reductioon_stack){}
void fun94(std::vector<std::string>&reductioon_stack){val_stack.push_back(reductioon_stack.back());}
void fun95(std::vector<std::string>&reductioon_stack){}
void fun96(std::vector<std::string>&reductioon_stack){}
void fun97(std::vector<std::string>&reductioon_stack){}
void fun98(std::vector<std::string>&reductioon_stack){}
void fun99(std::vector<std::string>&reductioon_stack){}
void fun100(std::vector<std::string>&reductioon_stack){}
void fun101(std::vector<std::string>&reductioon_stack){}
void fun102(std::vector<std::string>&reductioon_stack){}
void fun103(std::vector<std::string>&reductioon_stack){}
void fun104(std::vector<std::string>&reductioon_stack){}
void fun105(std::vector<std::string>&reductioon_stack){}
void fun106(std::vector<std::string>&reductioon_stack){}
void fun107(std::vector<std::string>&reductioon_stack){}
void fun108(std::vector<std::string>&reductioon_stack){}
void fun109(std::vector<std::string>&reductioon_stack){}
void fun110(std::vector<std::string>&reductioon_stack){}
void fun111(std::vector<std::string>&reductioon_stack){}
void fun112(std::vector<std::string>&reductioon_stack){}
void fun113(std::vector<std::string>&reductioon_stack){}
void fun114(std::vector<std::string>&reductioon_stack){}
void fun115(std::vector<std::string>&reductioon_stack){}
void fun116(std::vector<std::string>&reductioon_stack){}
void fun117(std::vector<std::string>&reductioon_stack){}
void fun118(std::vector<std::string>&reductioon_stack){}
void fun119(std::vector<std::string>&reductioon_stack){}
void fun120(std::vector<std::string>&reductioon_stack){}
void fun121(std::vector<std::string>&reductioon_stack){}
void fun122(std::vector<std::string>&reductioon_stack){}
void fun123(std::vector<std::string>&reductioon_stack){}
void fun124(std::vector<std::string>&reductioon_stack){}
void fun125(std::vector<std::string>&reductioon_stack){}
void fun126(std::vector<std::string>&reductioon_stack){}
void fun127(std::vector<std::string>&reductioon_stack){}
void fun128(std::vector<std::string>&reductioon_stack){}
void fun129(std::vector<std::string>&reductioon_stack){}
void fun130(std::vector<std::string>&reductioon_stack){
	}
void fun131(std::vector<std::string>&reductioon_stack){val_stack.push_back(reductioon_stack.back());}
void fun132(std::vector<std::string>&reductioon_stack){}
void fun133(std::vector<std::string>&reductioon_stack){
	tblptr->push_back(*(val_stack.end() - 2), *(val_stack.end() - 3)+"[]",atoi((*(val_stack.end() - 1)).c_str()), NULL);
	val_stack.pop_back();
	val_stack.pop_back();
	val_stack.pop_back();
}
void fun134(std::vector<std::string>&reductioon_stack){}
void fun135(std::vector<std::string>&reductioon_stack){}
void fun136(std::vector<std::string>&reductioon_stack){}
void fun137(std::vector<std::string>&reductioon_stack){
    name_table*temp=new name_table;
    tblptr->push_back(*(val_stack.end()-1), *(val_stack.end()-2), 0, temp);

    temp->set_parent_table(tblptr);
    temp->set_parent_name(*(val_stack.end()-1));
    
    tblptr=temp;
    val_stack.pop_back();
    val_stack.pop_back();
}
void fun138(std::vector<std::string>&reductioon_stack){}
void fun139(std::vector<std::string>&reductioon_stack){}
void fun140(std::vector<std::string>&reductioon_stack){}
void fun141(std::vector<std::string>&reductioon_stack){}
void fun142(std::vector<std::string>&reductioon_stack){}
void fun143(std::vector<std::string>&reductioon_stack){}
void fun144(std::vector<std::string>&reductioon_stack){}
void fun145(std::vector<std::string>&reductioon_stack){}
void fun146(std::vector<std::string>&reductioon_stack){}
void fun147(std::vector<std::string>&reductioon_stack){}
void fun148(std::vector<std::string>&reductioon_stack){}
void fun149(std::vector<std::string>&reductioon_stack){}
void fun150(std::vector<std::string>&reductioon_stack){}
void fun151(std::vector<std::string>&reductioon_stack){}
void fun152(std::vector<std::string>&reductioon_stack){}
void fun153(std::vector<std::string>&reductioon_stack){}
void fun154(std::vector<std::string>&reductioon_stack){}
void fun155(std::vector<std::string>&reductioon_stack){}
void fun156(std::vector<std::string>&reductioon_stack){}
void fun157(std::vector<std::string>&reductioon_stack){}
void fun158(std::vector<std::string>&reductioon_stack){}
void fun159(std::vector<std::string>&reductioon_stack){}
void fun160(std::vector<std::string>&reductioon_stack){}
void fun161(std::vector<std::string>&reductioon_stack){}
void fun162(std::vector<std::string>&reductioon_stack){}
void fun163(std::vector<std::string>&reductioon_stack){}
void fun164(std::vector<std::string>&reductioon_stack){}
void fun165(std::vector<std::string>&reductioon_stack){}
void fun166(std::vector<std::string>&reductioon_stack){}
void fun167(std::vector<std::string>&reductioon_stack){}
void fun168(std::vector<std::string>&reductioon_stack){}
void fun169(std::vector<std::string>&reductioon_stack){}
void fun170(std::vector<std::string>&reductioon_stack){}
void fun171(std::vector<std::string>&reductioon_stack){}
void fun172(std::vector<std::string>&reductioon_stack){}
void fun173(std::vector<std::string>&reductioon_stack){
    if(*(reductioon_stack.end()-5)=="if")
    {
		tblptr->quaternary_list.push_back({ "jmp","","",""});
        unsolved_true_list.push_back((int)tblptr->quaternary_list.size()-1);
        tblptr->quaternary_list[unsolved_false_list.back()].result=std::to_string(tblptr->quaternary_list.size());
        unsolved_false_list.pop_back();
    }
    else if(*(reductioon_stack.end()-2)=="else")
    {
        tblptr->quaternary_list[unsolved_true_list.back()].result=std::to_string(tblptr->quaternary_list.size());
        unsolved_true_list.pop_back();
    }
    else if(*(reductioon_stack.end()-5)=="while")
    {
        tblptr->quaternary_list.push_back({"jmp","","",std::to_string(while_cal_addr)});
        tblptr->quaternary_list[unsolved_false_list.back()].result=std::to_string(tblptr->quaternary_list.size());
        unsolved_false_list.pop_back();
    }
}
void fun174(std::vector<std::string>&reductioon_stack){
}
void fun175(std::vector<std::string>&reductioon_stack){}
void fun176(std::vector<std::string>&reductioon_stack){}
void fun177(std::vector<std::string>&reductioon_stack){}
void fun178(std::vector<std::string>&reductioon_stack){}
void fun179(std::vector<std::string>&reductioon_stack){}
void fun180(std::vector<std::string>&reductioon_stack){}
void fun181(std::vector<std::string>&reductioon_stack){}
void fun182(std::vector<std::string>&reductioon_stack){}
void fun183(std::vector<std::string>&reductioon_stack){}
void fun184(std::vector<std::string>&reductioon_stack){}
void fun185(std::vector<std::string>&reductioon_stack){}
void fun186(std::vector<std::string>&reductioon_stack){}
void fun187(std::vector<std::string>&reductioon_stack){}
void fun188(std::vector<std::string>&reductioon_stack){}
void fun189(std::vector<std::string>&reductioon_stack){}
void fun190(std::vector<std::string>&reductioon_stack){}
void fun191(std::vector<std::string>&reductioon_stack){}
void fun192(std::vector<std::string>&reductioon_stack){
}
void fun193(std::vector<std::string>&reductioon_stack){}
void fun194(std::vector<std::string>&reductioon_stack){}
void fun195(std::vector<std::string>&reductioon_stack){}
void fun196(std::vector<std::string>&reductioon_stack){}
void fun197(std::vector<std::string>&reductioon_stack){}
void fun198(std::vector<std::string>&reductioon_stack){}
void fun199(std::vector<std::string>&reductioon_stack){}
void fun200(std::vector<std::string>&reductioon_stack){}
void fun201(std::vector<std::string>&reductioon_stack){}
void fun202(std::vector<std::string>&reductioon_stack){
	tblptr->quaternary_list.push_back({ "return","","","" });
}
void fun203(std::vector<std::string>&reductioon_stack){
	if((tblptr->quaternary_list).back().op!="return")
		tblptr->quaternary_list.push_back({ "return","","","" });
	tblptr = tblptr->parent_table;
}
void fun204(std::vector<std::string>&reductioon_stack){}
void fun205(std::vector<std::string>&reductioon_stack){}
void fun206(std::vector<std::string>&reductioon_stack){}
void fun207(std::vector<std::string>&reductioon_stack){}
void fun208(std::vector<std::string>&reductioon_stack){}
void fun209(std::vector<std::string>&reductioon_stack){}
void fun210(std::vector<std::string>&reductioon_stack){}
void fun211(std::vector<std::string>&reductioon_stack){}





