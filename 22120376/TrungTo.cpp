#include"TrungTo.h"





string evaluate(string infix) {

	vector<string> tokens = split(infix);
	Stack<string> values;
	Stack<char> ops;

	Init(values);
	Init(ops);


	for (int i = 0; i < tokens.size(); i++) {
		string token = tokens[i];

		if (token == " ")
			continue;

		else if (token == "(") {
			Push(ops, '(');
		}

		else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
			Push(values, token);
		}

		else if (token == ")") {
			while (!IsEmpty(ops) && Top(ops) != '(') {
				string val2 = Top(values);
				Pop(values);

				string val1 = Top(values);
				Pop(values);

				char op = Top(ops);
				Pop(ops);


				Push(values, applyOp(val1, val2, op));
			}

			if (!IsEmpty(ops))
				Pop(ops);
		}

		else {
			while (!IsEmpty(ops) && precedence(Top(ops)) >= precedence(token[0])) {

				string val2 = Top(values);
				Pop(values);

				string val1 = Top(values);
				Pop(values);

				char op = Top(ops);
				Pop(ops);


				Push(values, applyOp(val1, val2, op));
			}

			Push(ops, token[0]);
		}
	}

	while (!IsEmpty(ops)) {
		string val2 = Top(values);
		Pop(values);

		string val1 = Top(values);
		Pop(values);

		char op = Top(ops);
		Pop(ops);

		Push(values, applyOp(val1, val2, op));
	}

	return Top(values);

}

void GhiFile(string filename,vector<string>input) {
	ofstream out;
	out.open(filename);

	if (!out.is_open()) {
		cout << "Khong the mo file\n";
		return;
	}

	for(int i = 0; i < input.size(); i++){
		out << input[i] << "\n";
	}


}

void DocFile(string filename) {
	vector<string> inputs;
	vector<string>result;

	ifstream in;
	in.open(filename);

	if (!in.is_open()) {
		cout << "Khong the mo file\n";
		return;
	}

	string line;
	string tmp;

	while (getline(in, line)) {
		
		tmp = ChuanHoa(line);
		inputs.push_back(tmp);
		tmp = evaluate(line);
		result.push_back(tmp);
	}

	GhiFile("output.txt", result);

	for(int i = 0; i < inputs.size(); i++){
		cout << "Bieu thuc " << i + 1 << ":\n"; 
		cout << inputs[i] << "\n";
		cout << "Ket qua : \n";
		cout << result[i] << "\n\n";

	}

}


