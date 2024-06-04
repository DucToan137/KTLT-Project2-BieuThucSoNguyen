#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<fstream>
#include"PhepTinh.h"





vector<string> split(string s);
int precedence(char op);
string applyOp(string a, string b, char op);
string ChuanHoa(string infix);