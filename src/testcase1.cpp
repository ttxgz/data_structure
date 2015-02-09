
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#include "testcase1.h"

void testcase1()
{

	int sockFd, n;
	char recvLine[MAXLINE_TC_1 + 1];
	struct sockaddr_in sockServer;
	
	//get the ip address from input
	cout << "please input the ip address" << endl;
	string ipAddr;
	getline(cin, ipAddr);
	cout << "confirmed IP address is: " << ipAddr;

	bzero(&sockServer, sizeof(sockServer));
	sockServer.sin_family = AF_INET;

	
}
