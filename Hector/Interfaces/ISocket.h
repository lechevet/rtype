#ifndef I_SOCKET_H
#define I_SOCKET_H

#define SERVER_SOCKET 1
#define CLIENT_SOCKET 2

#ifdef _WIN32
	
	#define WINDOWS 1
	#include <windows.h>
	#include <winsock2.h>

#endif

#ifdef __unix__

	#define WINDOWS 0
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>

#endif

#include <unistd.h>

class ISocket;

class ISocket
{
	public:

		virtual int 			initSocket(int port = 1101,
										   char * hostname = NULL,
										   int socket_type=1) = 0;
		virtual int 			destroySocket() = 0;
		virtual int  			getPort() const = 0;
		virtual const int 		getFd() const = 0;
		virtual const char *	getHostName() const = 0;
		virtual sockaddr_in &	getSockAddr() = 0;
		virtual socklen_t &		getAddrSize() = 0;
		virtual 				~ISocket() {};
		virtual void 			setContext(ISocket *context) = 0;

	
	protected:

		int 					_type;
		int 					_fd;
		int 					_port;
		char *					_hostname;
		sockaddr_in 			_addr;
		socklen_t 				_addrSize;
		ISocket *				_context;

	private:
};

#endif // I_SOCKET_H