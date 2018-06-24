#include <iostream>

#include<cstdlib>
#include<ctime>
using namespace std;

#include "youdaoApi.h"
#include "MD5.h"

void PrintMD5(const string &str, MD5 &md5) {
	cout << "MD5(\"" << str << "\") = " << md5.toString() << endl;
}

int main() {
	cout << "Hello,world!" << endl;
	cout << MD5("abc").toString() << endl;
	srand((unsigned)time(NULL));

	MD5 md5;
	md5.reset();
	md5.update("message digest");
	PrintMD5("abcdefghijklmnopqrstuvwxyz", md5);

	youdaoApi api;
	system("pause");
	return 0;
}