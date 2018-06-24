#include "net.h"

void sendHttp(string host, string request) {
	int sockfd;
	struct sockaddr_in address;
	struct hostnet *server;

	sockfd = socket(AF_INET, SOCK_STREAM,0);
	address.sin_family = AF_INET;
	address.sin_port = htons(80);
	//server = (struct hostnet *)gethostbyname(host.c_str());
	//memcpy((char *)&address.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

	//if (-1 == connect(sockfd, (struct sockaddr *)&address, sizeof(address))) {
	//	cout << "connection error!" << std::endl;
	//	return;
	//}

	//cout << request << std::endl;
	//send(sockfd, request.c_str(), request.size(), 0);
	//char buf[1024 * 1024] = { 0 };


	//int offset = 0;
	//int rc;

	//while (rc = recv(sockfd, buf + offset, 1024, 0))
	//{
	//	offset += rc;
	//}



	//closesocket(sockfd);
	//buf[offset] = 0;
	//cout << buf << std::endl;
}