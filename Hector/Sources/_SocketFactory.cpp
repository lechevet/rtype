#include "_SocketFactory.h"

/*
=============================================================================
	CONSTRUCTEUR DE LA CLASSE _SocketFactory
=============================================================================
*/
_SocketFactory::_SocketFactory()
{

}
/*
=============================================================================
	DESTRUCTEUR DE LA CLASSE _SocketFactory
=============================================================================
*/
_SocketFactory::~_SocketFactory()
{

}
/*
=============================================================================
	GENERATEUR DE SOCKET SERVER
=============================================================================
*/
ISocket * _SocketFactory::createUDPServerSocket(int port)
{
	ISocket * newServerSocket = new SOCKET();
	newServerSocket->initSocket(port, NULL, SERVER_SOCKET);
	return (newServerSocket);
}
/*
=============================================================================
	GENERATEUR DE SOCKET CLIENT
=============================================================================
*/
ISocket * _SocketFactory::createUDPClientSocket(int port, char *hostname)
{
	ISocket *newClientSocket = new SOCKET();
	newClientSocket->initSocket(port, hostname, CLIENT_SOCKET);
	return (newClientSocket);
}