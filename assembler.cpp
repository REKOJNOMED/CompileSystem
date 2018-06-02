//
//  assembler.cpp
//  Compile
//
//  Created by JOKER on 9/5/2018.
//  Copyright © 2018 JOKER. All rights reserved.
//

#include "assembler.hpp"
int labelNo = -1;
struct data
{
	std::string data_name;
	std::string type_name;
	int addr;
};
struct process
{
	std::string processname;
	std::vector<std::string> code_list;
	std::vector<data> data_list;
	int variable_size;
};
int free_register(int flag[4])
{
	for (int i = 0; i != 4; i++)
	{
		if (!flag)
			return i;
	}
	return -1;
}
std::vector<std::string>split(std::string str, std::string pattern)
{
	if (str.empty()) return {};
	std::string::size_type pos;
	std::vector<std::string>result;
	str += pattern;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos-i);
			result.push_back(s);
			i = pos + pattern.size()-1 ;
		}
	}
	return result;
}
void assembling(name_table &nt)
{
	
	std::vector<process> process_list;
	std::vector<data>	 data_list;
	for (auto ita = nt.content.begin(); ita != nt.content.end(); ita++)
	{
		if (ita->child_table != NULL)
		{
			std::map<int,std::string> unsolved_label;
			process p;
			p.processname = ita->fun_var_name;
			name_table* tblptr = ita->child_table;
			int variable_size = 0;
			int offset = 0;
			p.code_list.push_back(p.processname + " " + "PROC");
			std::string temp_code;
			if (tblptr->content.size() != 0)
			{
				temp_code = "local ";
				for (auto itb = tblptr->content.begin(); itb != tblptr->content.end(); itb++)
				{
					if (itb->child_table == NULL)
					{
						data d;
						d.data_name = itb->fun_var_name;
						d.type_name = itb->type;
						d.addr = offset;
						if (itb->type == "int")
						{
							offset += 4;
							p.data_list.push_back(d);
							temp_code = temp_code + d.data_name + ":" + "DWORD" + ",";
						}
						if (itb->type == "int[]")
						{
							p.data_list.push_back(d);
							temp_code = temp_code + d.data_name + "[" + std::to_string(itb->offset_list) + "]:" + "DWORD" + ",";
						}
					}
				}
				temp_code += "_temp:DWORD";
				p.code_list.push_back(temp_code);
				p.variable_size = offset;
			}
			bool register_list_flag[4] = { false,false,false,false };
			for (int i = 0; i != tblptr->quaternary_list.size(); i++)
			{
				if (tblptr->quaternary_list[i].op == "if_false" || tblptr->quaternary_list[i].op == "jmp")
				{
					labelNo++;
					unsolved_label.insert({ atoi(tblptr->quaternary_list[i].result.c_str()), "LABEL" + std::to_string(labelNo) });
				}
			}
			for (int i = 0; i != tblptr->quaternary_list.size(); i++)
			{
				if (!tblptr->quaternary_list.empty())
				{
					for (auto it = unsolved_label.begin(); it != unsolved_label.end(); it++)
					{
						if (it->first == i)
						{
							temp_code = it->second + ":";
							p.code_list.push_back(temp_code);
							break;
						}
					}
				}
				std::string op = tblptr->quaternary_list[i].op;
				if (op == "*")
				{
					std::string temp_code;
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
					p.code_list.push_back(temp_code);
					temp_code = "mul ebx";
					p.code_list.push_back(temp_code);
					temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
					p.code_list.push_back(temp_code);
				}
				else if (op == "/")
				{
					std::string temp_code;
					p.code_list.push_back("xor edx,edx");
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
					p.code_list.push_back(temp_code);
					temp_code = "div ebx";
					p.code_list.push_back(temp_code);
					temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
					p.code_list.push_back(temp_code);
				}
				else if (op == "invoke")
				{
					std::string temp_code;
					std::string fun_name = tblptr->quaternary_list[i].arg1;
					std::vector<std::string>arg_list = split(tblptr->quaternary_list[i].arg2, ",");
					temp_code = "invoke " + fun_name;
					if (!arg_list.empty())
					{
						for (auto it = arg_list.begin(); it != arg_list.end(); it++)
						{
							if ((*it)[0] == '\"')
								temp_code += ",chr$(" + *it + ")";
							else if ((*it)[0] == '&')
							{
								int begin = (*it).find("[", 0);

								if (begin != -1)
								{
									int end = (*it).find("]", begin);
									std::string pos = (*it).substr(begin+1, end - begin-1);
									p.code_list.push_back(("mov edx," + pos));
									temp_code += ",addr(" + (*it).substr(1, begin-1) + "[edx*4])";
								}
								else
								{
									temp_code += ",addr(" + (*it).substr(1) + ")";
								}
							}
							else
								temp_code += "," + (*it);
						}
					}
					p.code_list.push_back(temp_code);
				}
				else if (op == "+")
				{
					
					int begin = tblptr->quaternary_list[i].arg2.find("[", 0);

					if (begin != -1)
					{
						int end = tblptr->quaternary_list[i].arg2.find("]", begin);
						std::string pos = tblptr->quaternary_list[i].arg2.substr(begin+1, end - begin-1);
						p.code_list.push_back(("mov edx," + pos));
						std::string temp_code;
						temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
						p.code_list.push_back(temp_code);
						temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2.substr(0,begin)+"[edx*4]";
						p.code_list.push_back(temp_code);
						temp_code = "add eax,ebx";
						p.code_list.push_back(temp_code);
						temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
						p.code_list.push_back(temp_code);
					}
					else
					{
						std::string temp_code;
						temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
						p.code_list.push_back(temp_code);
						temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
						p.code_list.push_back(temp_code);
						temp_code = "add eax,ebx";
						p.code_list.push_back(temp_code);
						temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
						p.code_list.push_back(temp_code);
					}
					
				}
				else if (op == "-")
				{
					std::string temp_code;
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
					p.code_list.push_back(temp_code);
					temp_code = "sub eax,ebx";
					p.code_list.push_back(temp_code);
					temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
					p.code_list.push_back(temp_code);
				}
				else if (op == "assign")
				{
					std::string temp_code;
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov " + tblptr->quaternary_list[i].result + ",eax";
					p.code_list.push_back(temp_code);
				}
				else if (op == "<")
				{
					std::string temp_code;
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
					p.code_list.push_back(temp_code);
					temp_code = "cmp eax,ebx";
					p.code_list.push_back(temp_code);
				}
				else if (op == ">")
				{
					std::string temp_code;
					temp_code = "mov eax," + tblptr->quaternary_list[i].arg1;
					p.code_list.push_back(temp_code);
					temp_code = "mov ebx," + tblptr->quaternary_list[i].arg2;
					p.code_list.push_back(temp_code);
					temp_code = "cmp eax,ebx";
					p.code_list.push_back(temp_code);
				}
				else if (op == "if_false")
				{
					if (tblptr->quaternary_list[i].arg1 == "<")
					{
						std::string temp_code;
						temp_code = "jge " + unsolved_label[atoi(tblptr->quaternary_list[i].result.c_str())];
						p.code_list.push_back(temp_code);
					}
					else if (tblptr->quaternary_list[i].arg1 == ">")
					{
						std::string temp_code;
						temp_code = "jle " + unsolved_label[atoi(tblptr->quaternary_list[i].result.c_str())];
						p.code_list.push_back(temp_code);
					}
				}
				else if (op == "jmp")
				{
					std::string temp_code;

					temp_code = "jmp " + unsolved_label[atoi(tblptr->quaternary_list[i].result.c_str())];
					p.code_list.push_back(temp_code);
				}
				else if (op == "return")
				{
					std::string temp_code;
					temp_code = "ret";
					p.code_list.push_back(temp_code);
				}
			}
			p.code_list.push_back(p.processname + " ENDP");
			if (p.processname == "main")
				p.code_list.push_back("END main");
			process_list.push_back(p);
		}
	}
	std::fstream file("asm.txt");
	file << "INCLUDE ASM32.INC" << std::endl;
	file << ".DATA" << std::endl;
	for (auto it = data_list.begin(); it != data_list.end(); it++)
	{

	}
	file << ".CODE" << std::endl;
	for (auto it = process_list.begin(); it != process_list.end(); it++)
	{
		for (auto ita = it->code_list.begin(); ita != it->code_list.end(); ita++)
		{
			file << (*ita) << std::endl;
		}

	}

}