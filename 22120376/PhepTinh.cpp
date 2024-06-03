#include"PhepTinh.h"


// So sanh a va b
// a < b: return -1
// a = b: return 0
// a > b: return 1
int compare(string a, string b) {
	// a < 0, b > 0
	if (a[0] == '-' && b[0] != '-') {
		return -1;
	}
	// a > 0, b < 0
	else if (a[0] != '-' && b[0] == '-') {
		return 1;
	}
	else { // a, b < 0
		if (a[0] == '-' && b[0] == '-') {
			a.erase(0, 1);
			b.erase(0, 1);


			long n1 = a.length();
			long n2 = b.length();

			if (n1 < n2) {
				return 1;
			}
			else if (n1 > n2) {
				return -1;
			}
			else {
				for (long i = 0; i < n1; i++) {
					if (a[i] < b[i]) {
						return 1;
					}
					else if (a[i] > b[i]) {
						return -1;
					}
				}
				return 0;
			}
		}
		else {
			// a, b > 0
			long n1 = a.length();
			long n2 = b.length();

			if (n1 < n2) {
				return -1;
			}
			else if (n1 > n2) {
				return 1;
			}
			else {
				for (long i = 0; i < n1; i++) {
					if (a[i] < b[i]) {
						return -1;
					}
					else if (a[i] > b[i]) {
						return 1;
					}
				}
				return 0;
			}
		}

	}
}

// CỘNG 2 SỐ NGUYÊN LỚN
// cộng 2 số dương (X)
// cộng 2 số trái dấu (X)
string Tong(string a, string b) {

	// a = 0
	if (a == "0") {
		return b;
	}


	string result = "";

	if (a[0] == '-' && b[0] == '-') {
		a.erase(0, 1);
		b.erase(0, 1);
		result = Tong(a, b);
		result.insert(0, 1, '-');
		return result;
	}

	if (a[0] == '-') {
		a.erase(0, 1);
		return Hieu(b, a);
	}

	if (b[0] == '-') {
		b.erase(0, 1);
		return Hieu(a, b);
	}

	// a, b > 0
	long n1 = a.length();
	long n2 = b.length();
	long nho = 0;
	long tong = 0;
	long i = 0;

	if (n1 > n2) {
		b.insert(0, n1 - n2, '0');
	}
	if (n1 < n2) {
		a.insert(0, n2 - n1, '0');
	}

	result = a;

	for (i = a.length() - 1; i >= 0; i--) {
		tong = (a[i] - '0') + (b[i] - '0') + nho;
		nho = tong / 10;
		tong = tong % 10;
		result[i] = tong + '0';
	}

	if (nho > 0) {
		result.insert(0, 1, nho + '0');
	}


	return result;
}



// TRỪ 2 SỐ NGUYÊN LỚN
// 2 số nguyên > 0
string Hieu(string a, string b) {
	// a = b
	if (a == b) {
		return "0";
	}

	// a = 0, b != 0
	if (a == "0" && b != "0") {
		if (b[0] == '-') {
			b.erase(0, 1);
			return b;
		}
		else {
			return b;
		}
	}

	// a != 0, b = 0
	if (a != "0" && b == "0") {
		return a;
	}

	string result = "";

	long lenA = a.length();
	long lenB = b.length();

	long muon = 0;
	long hieu = 0;
	int flag = 0;

	if (a[0] != '-' && b[0] != '-') {

		if (compare(a, b) == -1) {
			flag = 1;
			swap(a, b);
		}

		if (lenA > lenB) {
			b.insert(0, lenA - lenB, '0');
		}

		for (long i = lenA - 1; i >= 0; i--) {
			hieu = (a[i] - '0') - (b[i] - '0') - muon;
			if (hieu < 0) {
				hieu += 10;
				muon = 1;
			}
			else {
				muon = 0;
			}
			result.insert(0, 1, hieu + '0');
		}

		while (result.length() > 1 && result[0] == '0') {
			result.erase(0, 1);
		}

		if (flag == 1) {
			result.insert(0, 1, '-');
		}
		return result;
	}
	else if (a[0] != '-' && b[0] == '-') {
		b.erase(0, 1);
		result = Tong(a, b);
		return result;
	}
	else if (a[0] == '-' && b[0] != '-') {
		a.erase(0, 1);
		result = Tong(a, b);
		result.insert(0, 1, '-');
		return result;
	}
	else {
		a.erase(0, 1);
		b.erase(0, 1);
		result = Hieu(b, a);
		return result;
	}

	return result;
}


// NHÂN 2 SỐ NGUYÊN LỚN 
string Tich(string a, string b) {

	int flag = 0;

	if (a[0] == '-' && b[0] == '-') {
		a.erase(0, 1);
		b.erase(0, 1);
	}
	else if (a[0] == '-') {
		flag = 1;
		a.erase(0, 1);
	}
	else if (b[0] == '-') {
		flag = 1;
		b.erase(0, 1);
	}

	string result(a.length() + b.length(), '0');

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int lenA = a.length();
	int lenB = b.length();

	for (int iB = 0; iB < lenB; iB++) {
		int iA;
		int nho = 0;

		for (iA = 0; iA < lenA; iA++) {
			int x = (b[iB] - '0') * (a[iA] - '0') + nho + (result[iA + iB] - '0');
			nho = x / 10;
			result[iA + iB] = x % 10 + '0';

		}

		if (nho > 0) {
			result[iA + iB] = nho + '0';
		}
	}

	reverse(result.begin(), result.end());

	size_t startpos = result.find_first_not_of('0');
	if (string::npos != startpos) {
		result = result.substr(startpos);
	}
	else {
		result = "0";
	}


	if (flag == 1) {
		result.insert(0, 1, '-');
	}

	return result;
}




// CHIA 2 SỐ NGUYÊN LỚN (lấy phần nguyên)
string Thuong(string a, string b) {
	if (b == "0") {
		cout << "Khong the chia cho 0\n";
		return "";
	}

	int flag = 0;
	if (a[0] == '-' && b[0] == '-') {
		a.erase(0, 1);
		b.erase(0, 1);
	}
	else if (a[0] == '-') {
		flag = 1;
		a.erase(0, 1);
	}
	else if (b[0] == '-') {
		flag = 1;
		b.erase(0, 1);
	}

	string result;
	string current;

	for (size_t i = 0; i < a.length(); ++i) {
		current += a[i];

		// Loại bỏ các số 0 dẫn đầu từ current
		while (current.length() > 1 && current[0] == '0') {
			current.erase(0, 1);
		}

		size_t count = 0;
		while (compare(current, b) >= 0) {
			current = Hieu(current, b);
			count++;
		}
		result += to_string(count);
	}

	// Loại bỏ các số 0 dẫn đầu trong kết quả

	while (result.length() > 1 && result[0] == '0') {
		result.erase(0, 1);
	}

	if (flag == 1 && result != "0") {
		result.insert(0, 1, '-');
	}

	return result;
}
