#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "MD5.h"
#include "net.h"

class youdaoApi
{
	string word;
	string appkey;
	string from;
	string to;
	string salt;
	string appSecret;
	MD5 md5;
	string md5Str;
	string sign;
	string url;

public:
	youdaoApi();
	~youdaoApi();
};

