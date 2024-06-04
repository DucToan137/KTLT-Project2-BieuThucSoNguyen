#include"Helper.h"

vector<string> split(string s) {
	vector<string> result;

	int dem = 0;
	for (int i = 0; i < s.length(); i++) {
		dem = i;
		if (s[i] == ' ') {
			continue;
		}

		if (s[i] == '(' || s[i] == ')') {
			result.push_back(string(1, s[i]));
		}

		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == ':') {
			stringstream builder;
			builder << s[i];
			while (isdigit(s[i + 1])) {
				builder << s[i + 1];
				i++;
			}

			string tmp = builder.str();
			result.push_back(tmp);
			continue;
		}

		if (isdigit(s[i])) {
			stringstream builder;
			builder << s[i];
			while (isdigit(s[i + 1])) {
				builder << s[i + 1];
				i++;
			}

			string tmp = builder.str();
			result.push_back(tmp);
		}
	}

	return result;
}

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == ':')
		return 2;
	return 0;
}

string applyOp(string a, string b, char op) {
	switch (op) {
	case '+': return Tong(a, b);
	case '-': return Hieu(a, b);
	case '*': return Tich(a, b);
	case ':': return Thuong(a, b);
	}
}

string ChuanHoa(string infix) {
	vector<string> tokens = split(infix);
	string result = "";
	stringstream builder;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "(") {
			builder << tokens[i];
		}
		else {
			builder << tokens[i] << " ";
		}
	
		
	}
	result = builder.str();

	for (int i = 0; i < result.length(); i++) {
		if (result[i] == ')') {
			result.erase(i - 1, 1);
		}
	}
	return result;
}