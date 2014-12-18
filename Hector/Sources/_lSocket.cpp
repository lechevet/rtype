#include "_lSocket.h"
#include "Output.h"
/*
=============================================================================
	CONSTRUCTEUR DE LA CLASSE _lSocket
=============================================================================
*/
_lSocket::_lSocket()
{
	this->_hostname = NULL;
	this->_context  = NULL;
	this->_addrSize = sizeof(sockaddr_in);
}
/*
=============================================================================
	DESTRUCTEUR DE LA CLASSE _lSocket
=============================================================================
*/
_lSocket::~_lSocket()
{
	if (this->_hostname)
		delete (this->_hostname);
	this->destroySocket();
}
/*
=============================================================================
	DETRUIT UNE SOCKET CREE
=============================================================================
*/
int _lSocket::destroySocket()
{
	return (close(this->_fd));
}
/*
=============================================================================
	GETTER PORT
=============================================================================
*/
int _lSocket::getPort() const
{
	return (this->_port);
}
/*
=============================================================================
	GETTER FD
=============================================================================
*/
const int _lSocket::getFd() const
{
	return (this->_fd);
}
/*
=============================================================================
	GETTER ADDR SIZE
=============================================================================
*/
socklen_t &			_lSocket::getAddrSize()
{
	return (this->_addrSize);
}
/*
=============================================================================
	GETTER HOSTNAME
=============================================================================
*/
const char * _lSocket::getHostName() const 
{
	return (this->_hostname);
}
/*
=============================================================================
	GETTER SOCKADDR (STRUCTURE MODIFIABLE)
=============================================================================
*/
sockaddr_in & _lSocket::getSockAddr()
{
	return (this->_addr);
}
/*
=============================================================================
	SETTER DU CONTEXT : NECESSAIRE POUR LA CREATION D'UNE SOCKET CLIENT
=============================================================================
*/
void _lSocket::setContext(ISocket *context)
{
	this->_context = context;
}
/*
=============================================================================
	FONCTION VISIBLE : INITIALISE UNE SOCKET CLIENT OU SERVER
	1 : SERVER_SOCKET
	2 : CLIENT_SOCKET
=============================================================================
*/
int _lSocket::initSocket(int port, char *hostname, int socket_type)
{
	this->_port = port;
	this->_hostname = hostname;
	this->_type = socket_type;
	if (socket_type & SERVER_SOCKET)
		return (this->initLinuxServerSocket());
	else if (socket_type & CLIENT_SOCKET)
		return (this->initLinuxClientSocket());
	else
		return (-1);
}
/*
=============================================================================
	FONCTION MASQUEE : INITIALISE UNE SOCKET SERVER
=============================================================================
*/
int _lSocket::initLinuxServerSocket()
{
	int *	int_ptr;

	if ((this->_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		return (-1);
	int_ptr = new int;
	if((setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR, (char*)int_ptr, sizeof(int)) == -1 ) ||
       (setsockopt(this->_fd, SOL_SOCKET, SO_KEEPALIVE, (char*)int_ptr, sizeof(int)) == -1 ))
	{
        delete (int_ptr);
        return (-1);
    }
    delete (int_ptr);
    this->_addr.sin_family = AF_INET;
    this->_addr.sin_port   = htons(this->_port);
    for (unsigned int i = 0; i < sizeof(this->_addr.sin_zero); i++)
    	*((char *)this->_addr.sin_zero) = 0;
	this->_addr.sin_addr.s_addr = INADDR_ANY ;
    if(bind(this->_fd, (sockaddr*)&(this->_addr), sizeof(this->_addr)) == -1 )
   		return (-1);
   	return (0);
}
/*
=============================================================================
	FONCTION MASQUEE : INITIALISE UNE SOCKET CLIENT
=============================================================================
*/
int _lSocket::initLinuxClientSocket()
{
	// LAISSER VIDE POUR LE PROTOCOLE UDP
	// LE FD N'A AUCUNE IMPORTANCE
	return (this->_fd);
}