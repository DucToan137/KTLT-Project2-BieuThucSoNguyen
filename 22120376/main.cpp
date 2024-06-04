#include<iostream>
#include"TrungTo.h"


using namespace std;


int main() {

	cout << string(54, '-') << "\n";
	cout << "CHUONG TRINH TINH TOAN GIA TRI BIEU THUC SO NGUYEN LON\n";
	cout << string(54, '-') << "\n\n";

	string filename ="input.txt";
	DocFile(filename);


	return 0;
}