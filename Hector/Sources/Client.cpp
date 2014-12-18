#include "Client.h"

/*
=============================================================================
	CONSTRUCTEUR DE LA CLASSE CLIENT
	: initialise la socket
	: initialise l'id a -1 (Client non connecté)
=============================================================================
*/
Client::Client(int port, ISocket * serverSocket)
{
	this->_clientSocket = _SocketFactory::createUDPClientSocket(port, NULL);
	this->_id = -1;
	this->_serverSocket = serverSocket;
}
/*
=============================================================================
	DESTRUCTEUR DE LA CLASS CLIENT
=============================================================================
*/
Client::~Client()
{
	delete (this->_clientSocket);
}
/*
=============================================================================
	GETTER DE LA SOCKET
	: (non const car peut être modifiée)
=============================================================================
*/
ISocket * Client::getSocket()
{
	return (this->_clientSocket);
}
/*
=============================================================================
	FONCTION DE LECTURE SUR LA SOCKET
=============================================================================
*/
int 	Client::recv()
{
	unsigned int readed;
	struct t_packet * packet;

	readed = 0;
	packet = new packet;
	for (register unsigned int i = 0; i < sizeof(t_packet); i++)
		((char *)packet)[i] = 0;
	readed = recvfrom(this->_serverSocket->fetFd(), packet, sizeof(packet), 0,
		(struct sockaddr *)&(this->_clientSocket->getSockAddr()), &(this->_clientSocket->getAddrSize());
	if (readed == sizeof(t_packet))
		{
			this->_recvMutex->lockMutex();
			this->_packet_recv->push_back(packet);
			this->_recvMutex->unlockMutex();
			return (readed);
		}
	delete packet;
	return (readed);
}
/*
=============================================================================
	FONCTION D'ECRITURE SUR LA SOCKET
===========================================================================
*/
int 	Client::send()
{
	
}
/*
=============================================================================
	FONCTION MASQUEE DE LECTURE EN THREAD DE LA SOCKET
	: lit en boucle la socket
=============================================================================
*/
void * Client::recvLoop(void *context)
{
	context = (Client *)context;
}
/*
=============================================================================
	FONCTION MASQUEE D'ECRITURE EN THREAD DE LA SOCKET
	: ecris en boucle sur la socket
=============================================================================
*/
void * Client::sendLoop(void *context)
{
	context = (Client *)context;
}