#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <_pThread.h>
#include <_SocketFactory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

static void * maroutine(void * data)
{
   std::cout << "YUP MAGEUL" << std::endl;
   return (data);
}

int main(int argc, char **argv)
{
	char *buffer;
	ISocket * serverSocket = _SocketFactory::createUDPServerSocket(1101);
	ISocket * clientSocket = _SocketFactory::createUDPClientSocket(1101, NULL);
	clientSocket->setContext(serverSocket);

   int n;
	buffer = new char[1024];
	while (true)
	{
		 n = recvfrom(serverSocket->getFd(), buffer, 1024, 0,
         (struct sockaddr *) &(clientSocket->getSockAddr()), &(clientSocket->getAddrSize()));
    	if (n < 0)
      		{
      			ERROR("error in recvfrom");
      		}
      	else
      		{
               buffer[n] = 0;
               printf("Received packet from %s:%d\nData: %s\n\n", 
               inet_ntoa((clientSocket->getSockAddr().sin_addr)), ntohs((clientSocket->getSockAddr().sin_port)), buffer);
      		}
      	sendto(serverSocket->getFd(), buffer, strlen(buffer), 0, 
            (struct sockaddr *) &(clientSocket->getSockAddr()), clientSocket->getAddrSize());
		memset(buffer, 0, 1024);
	}
}