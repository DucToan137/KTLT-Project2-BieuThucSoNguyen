#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include"PhepTinh.h"

using namespace std;





vector<string> split(string s);

int precedence(char op);

string applyOp(string a, string b, char op);