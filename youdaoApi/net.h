#pragma once
#include <string>
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

class HttpConnect {



};

void sendHttp(string host, string request);
