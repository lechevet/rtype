#ifndef		SOCKETWINDOWS_HH_
# define	SOCKETWINDOWS_HH_

#include	<cstring>
#include	<sys/types.h>
#include	<io.h>
#include	<windows.h>
#include	<iostream>
#include	<string>

class		socketWindows : public ISocket
{
private:
  SOCKET	sock;

public:
  socketWindows(): ISocket()
  {
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);
    
    if ((sock = ::socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
      {
	wprintf(L"socket function failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
	throw std::runtime_error("socket function failed");
      }
  }

  socketWindows(int fd)
  {
    sock = fd;
  }

  ~socketWindows()
  {
    ::_close(sock);
  }

  virtual bool	bind()
  {
    struct sockaddr_in	sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = INADDR_ANY;
    if (::bind(sock, (SOCKADDR *)(&sin), sizeof(sin)) == -1)
      {
	wprintf(L"bind function failed with error %d\n", WSAGetLastError());
	if ((closesocket(sock)) == SOCKET_ERROR)
	  {
	    wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
	  }
	throw std::runtime_error("bind function failed");
	WSACleanup();
	delete(this);
	return false;
      }
    return true;
  }

  virtual bool	listen()
  {
    if ((::listen(sock, 42)) == SOCKET_ERROR)
      {
	wprintf(L"listen function failed with error: %d\n", WSAGetLastError());
	if ((closesocket(sock)) == SOCKET_ERROR)
	  {
	    wprintf(L"closesocket function failed with error %d\n", WSAGetLastError());
	  }
	WSACleanup();
	throw std::runtime_error("listen function failed");
	return false;
      }
    return (true);
  }

  virtual void	close()
  {
  }

  virtual ISocket*	accept()
  {
    ISocket* clientSocket;
    SOCKET newSock;
    SOCKADDR_IN csin;
    int csinSize;

    if ((newSock = ::accept(sock, (SOCKADDR *)&csin, &csinSize)) == INVALID_SOCKET)
      {
	wprintf(L"accept function failed with error: %ld\n", WSAGetLastError());
	WSACleanup();
	throw std::runtime_error("accept function failed");
        return NULL;
      }
    clientSocket = new socketWindows(newSock);
    return clientSocket;
  }

  virtual int	realSock()
  {
    return (sock);
  }

  int		sendData(const void *data,
			 size_t size,
			 int flags) const
  {
    int           ret = send(sock, (char *)data, size, flags);
    return (ret);
  }

  int		sendDataTo(const void *data,
			   size_t size,
			   int flags,
			   const SOCKADDR *sockaddr,
			   socklen_t socklen) const
  {
    int           ret = sendto(sock, (char *)data, size, flags, sockaddr, socklen);
    return (ret);
  }

  int		recvData(void *data,
			 size_t len,
			 int flags) const
  {
    int           ret = recv(sock, (char *)data, len, flags);
    return (ret);
  }


  int		recvDataFrom(void *data,
			     size_t len,
			     int flags,
			     SOCKADDR *sockaddr,
			     socklen_t *socklen) const
  {
    int           ret = recvfrom(sock, (char *)data, len, flags, sockaddr, socklen);
    return (ret);
  }
};
#ifdef WIN32
	typedef socketWindows AbstractSocket;
#endif
#endif
