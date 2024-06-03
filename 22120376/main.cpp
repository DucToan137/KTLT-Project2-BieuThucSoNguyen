#include<iostream>
#include"TrungTo.h"


using namespace std;


int main() {


	//////////////TEST CASE 1////////////////
	//string num1 = "123456789012345678901234567890";
	//string num2 = "987654321098765432109876543210";

	//cout << "Test case 1: 2 so nguyen duong\n";
	//cout << "Tong: \n";
	//cout << Tong(num1, num2) << "\n"; // 1111111110111111111011111111100
	//cout << "Hieu: \n";
	//cout << Hieu(num1, num2) << "\n"; // -86419753108641975308641975320
	//cout <<"Tich: \n";
	//cout << Nhan("1234567890", "9879879876543219876") << "\n"; 
	//cout << "Thuong: \n";
	//cout << Chia(Nhan(num1,num2), num1) << "\n"; 
	//cout << Chia("12197382452637423456119381640", "9879879876543219876") << "\n";
	//


	//////////////////TEST CASE 2////////////////
	//string num3 = "-123456789098765432101234567890";
	//string num4 = "987654321098765432109876543210";

	//cout << "Test case 2: 1 so duong, 1 so am\n";
	//cout << "Tong: \n";
	//cout << Tong(num3, num4) << "\n"; // 864197531086419753086
	//cout << "Hieu: \n";
	//cout << Hieu(num3, num4) << "\n"; // -1111111110203703702101111111100
	//cout << "Tich: \n";
	//cout << Nhan(num3, num4) << "\n"; // -12193263111263526912193263111263526912193263111263526900000000000
	//cout << "Thuong: \n";
	//cout << Chia(Nhan(num3,num4), num4) << "\n"; // 0



	string input0 = "((-5      +    (         89       * 6) - 36) * (55 + 5) + 33) * 4 - 10";
	string input1 = "24   -  9 - (129 + 90 - 178)";
	string input2 = "(5 - 2) * 3";
	string input3 = "800 : 4 + 20";
	string input4 = "(-123456789012345678901234567890 + 987654321098765432109876543210) * 12197382452637423456119381640 :     12197382452637423456119381640";

	cout << "input0: " << evaluate(input0) << "\n";
	cout << "input1: " << evaluate(input1) << "\n";
	cout << "input2: " << evaluate(input2) << "\n";
	cout << "input3: " << evaluate(input3) << "\n";
	cout << "input4: " << evaluate(input4) << "\n";

	return 0;
}