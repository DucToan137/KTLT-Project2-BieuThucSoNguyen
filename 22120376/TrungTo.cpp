#include"TrungTo.h"





string evaluate(string infix) {

	vector<string> tokens = split(infix);
	Stack<string> values;
	Stack<char> ops;

	Init(values);
	Init(ops);


	for (int i = 0; i < tokens.size(); i++) {
		string token = tokens[i];

		// Token hiện tại là khoảng trắng, bỏ qua nó.
		if (token == " ")
			continue;

		// Token hiện tại là dấu mở ngoặc, đẩy nó vào stack 'ops'
		else if (token == "(") {
			Push(ops, '(');
		}

		// Token hiện tại là số, đẩy nó vào stack 'values'.
		else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
			Push(values, token);
		}

		// Gặp dấu đóng ngoặc, giải quyết toàn bộ biểu thức trong ngoặc.
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

			// Bỏ dấu mở ngoặc.
			if (!IsEmpty(ops))
				Pop(ops);
		}

		// Token hiện tại là một toán tử.
		else {
			// Trong khi đỉnh của 'ops' có độ ưu tiên lớn hơn hoặc bằng token hiện tại,
			// áp dụng toán tử trên đỉnh của 'ops' với hai phần tử trên đỉnh của stack 'values'.
			while (!IsEmpty(ops) && precedence(Top(ops)) >= precedence(token[0])) {

				string val2 = Top(values);
				Pop(values);

				string val1 = Top(values);
				Pop(values);

				char op = Top(ops);
				Pop(ops);


				Push(values, applyOp(val1, val2, op));
			}

			// Đẩy token hiện tại vào 'ops'.
			Push(ops, token[0]);
		}
	}

	// Biểu thức đã được phân tích hoàn toàn, áp dụng các toán tử còn lại với các giá trị còn lại.
	while (!IsEmpty(ops)) {
		string val2 = Top(values);
		Pop(values);

		string val1 = Top(values);
		Pop(values);

		char op = Top(ops);
		Pop(ops);

		Push(values, applyOp(val1, val2, op));
	}

	// Đỉnh của 'values' chứa kết quả, trả về nó.
	return Top(values);

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
		//cout << tmp << "\n";
		result.push_back(tmp);
	}

	for(int i = 0; i < inputs.size(); i++){
		cout << "Bieu thuc " << i + 1 << ":\n"; 
		cout << inputs[i] << "\n";
		cout << "Ket qua : \n";
		cout << result[i] << "\n\n";

	}

}


