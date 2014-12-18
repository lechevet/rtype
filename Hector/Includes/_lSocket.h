#ifndef _L_SOCKET_H
#define _L_SOCKET_H


#include "Output.h"
#include "ISocket.h"

class _lSocket : public ISocket
{
	public:
		_lSocket();
		virtual int 			initSocket(int port = 1101,
										   char *hostname = NULL,
										   int socket_type = 1);
		virtual int 			destroySocket();
		virtual const int 		getFd() const;
		virtual int  			getPort() const;
		virtual const char *	getHostName() const;
		virtual sockaddr_in &	getSockAddr();
		virtual 				~_lSocket();
		virtual void 			setContext(ISocket *context);
		virtual socklen_t &			getAddrSize();

	private:

		int 					initLinuxServerSocket();
		int 					initLinuxClientSocket();
};


#endif // _L_SOCKET_H
