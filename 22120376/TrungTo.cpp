#include"TrungTo.h"




string evaluate(string infix) {

	vector<string> tokens = split(infix);
	stack<string> values;
	stack<char> ops;

	for (int i = 0; i < tokens.size(); i++) {
		string token = tokens[i];

		// Token hiện tại là khoảng trắng, bỏ qua nó.
		if (token == " ")
			continue;

		// Token hiện tại là dấu mở ngoặc, đẩy nó vào stack 'ops'
		else if (token == "(") {
			ops.push('(');
		}

		// Token hiện tại là số, đẩy nó vào stack 'values'.
		else if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
			values.push(token);
		}

		// Gặp dấu đóng ngoặc, giải quyết toàn bộ biểu thức trong ngoặc.
		else if (token == ")") {
			while (!ops.empty() && ops.top() != '(') {
				string val2 = values.top();
				values.pop();

				string val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}

			// Bỏ dấu mở ngoặc.
			if (!ops.empty())
				ops.pop();
		}

		// Token hiện tại là một toán tử.
		else {
			// Trong khi đỉnh của 'ops' có độ ưu tiên lớn hơn hoặc bằng token hiện tại,
			// áp dụng toán tử trên đỉnh của 'ops' với hai phần tử trên đỉnh của stack 'values'.
			while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
				string val2 = values.top();
				values.pop();

				string val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}

			// Đẩy token hiện tại vào 'ops'.
			ops.push(token[0]);
		}
	}

	// Biểu thức đã được phân tích hoàn toàn, áp dụng các toán tử còn lại với các giá trị còn lại.
	while (!ops.empty()) {
		string val2 = values.top();
		values.pop();

		string val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(applyOp(val1, val2, op));
	}

	// Đỉnh của 'values' chứa kết quả, trả về nó.
	return values.top();
}