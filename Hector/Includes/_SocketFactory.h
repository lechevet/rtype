#ifndef _SOCKET_FACTORY_H
#define _SOCKET_FACTORY_H

#ifdef _WIN32
	#include "_wSocket.h"
	#define SOCKET _wSocket
#endif

#ifdef __unix__
	#include "_lSocket.h"
	#define SOCKET _lSocket
#endif

class _SocketFactory
{
	public:
		_SocketFactory();
		~_SocketFactory();

		static ISocket * createUDPServerSocket(int port);
		static ISocket * createUDPClientSocket(int port, char *hostname);
};

#endif // _SOCKET_FACTORY_H
