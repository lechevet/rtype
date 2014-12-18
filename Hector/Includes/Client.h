#ifndef CLIENT_H
#define CLIENT_H

#include <queue>
#include "_SocketFactory.h"
#include "IThread.h"
#include "IMutex.h"

#define INITALIZED 2

typedef struct s_packet
{
		unsigned int 	id;
		char 			data_1[200];
		char			data_2[200];
		char			data_3[200];
}			   t_packet;

class Client
{

	public:
	
		Client(int port, ISocket *_serverSocket);
		~Client();

		ISocket *getSocket();
		
		int 	send();
		int 	recv();

		void 	lockSend();
		void	lockRecv();

		void	startRecvThread();
		void 	startSendThread();

		void 	stopRecvThread();
		void 	stopSendThread();

		IThread *getRecvThread();
		IThread *getSendThread();

		bool operator==(const Client & compare) const;

	private:

		static  void *recvLoop(void *context);
		static  void *sendLoop(void *context);

	protected:

		ISocket *			_clientSocket;
		ISocket * 			_serverSocket;
		unsigned int 		_id;

		queue<t_packet *>	_packet_send;
		queue<t_packet *>	_packet_recv;

		IMutex				_sendMutex;
		IMutex				_recvMutex;

		IThread				_sendThread;
		IThread				_recvThread;

};

#endif // CLIENT_H
