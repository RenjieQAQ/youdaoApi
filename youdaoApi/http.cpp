﻿#include "http.h"

HttpConnect::HttpConnect()
{

}

HttpConnect::~HttpConnect()
{

}
void HttpConnect::socketHttp(string host, string request)
{
	int sockfd;
	struct sockaddr_in address;
	struct hostent *server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = htons(80);
	server = gethostbyname(host.c_str());
	memcpy((char *)&address.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

	if (-1 == connect(sockfd, (struct sockaddr *)&address, sizeof(address))) {
		cout << "connection error!" << std::endl;
		return;
	}

	cout << request << std::endl;
	send(sockfd, request.c_str(), request.size(),0);
	char buf[1024 * 1024] = { 0 };


	int offset = 0;
	int rc;

	while (rc = recv(sockfd, buf + offset, 1024,0))
	{
		offset += rc;
	}



	closesocket(sockfd);
	buf[offset] = 0;
	cout << buf << std::endl;

}

void HttpConnect::postData(std::string host, std::string path, std::string post_content)
{
	//POST请求方式
	std::stringstream stream;
	stream << "POST " << path;
	stream << " HTTP/1.0\r\n";
	stream << "Host: " << host << "\r\n";
	stream << "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.3) Gecko/20100401 Firefox/3.6.3\r\n";
	stream << "Content-Type:application/x-www-form-urlencoded\r\n";
	stream << "Content-Length:" << post_content.length() << "\r\n";
	stream << "Connection:close\r\n\r\n";
	stream << post_content.c_str();

	socketHttp(host, stream.str());
}

void HttpConnect::getData(std::string host, std::string path, std::string get_content)
{
	//GET请求方式
	std::stringstream stream;
	stream << "GET " << path << "?" << get_content;
	stream << " HTTP/1.0\r\n";
	stream << "Host: " << host << "\r\n";
	stream << "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.3) Gecko/20100401 Firefox/3.6.3\r\n";
	stream << "Connection:close\r\n\r\n";

	socketHttp(host, stream.str());
}
