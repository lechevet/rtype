#ifndef		SOCKETUNIX_HH
# define	SOCKETUNIX_HH

# include	<cstring>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netdb.h>
# include	"RtypeException.hpp"

class		socketUnix : public ISocket
{
private:
  SOCKET	sock;

public:
  socketUnix(enum Protocole protocole)
  {
    struct protoent	*pe;

    if (protocole == TCP)
      {
	pe = getprotobyname("TCP");
	if ((sock = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
	  throw RtypeException("Can't create socket.");
      }
    else
      {
	pe = getprotobyname("UDP");
	if ((sock = socket(AF_INET, SOCK_DGRAM, pe->p_proto)) == -1)
	  throw RtypeException("Can't create socket.");
      }
    bind();
  }

  socketUnix(int fd)
  {
    sock = fd;
  }

  ~socketUnix()
  {
    ::close(sock);
  }

  virtual bool	bind()
  {
    struct sockaddr_in	sin;

    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = INADDR_ANY;
    if (::bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
      throw RtypeException("Can't bind socket.");
    return (0);
  }

  virtual bool	listen()
  {
    ::listen(sock, 42);
    return (true);
  }

  virtual void	close()
  {
    delete(this);
  }

  virtual ISocket*	accept()
  {
    ISocket*		ret;
    int			cs;
    struct sockaddr_in	sin_client;
    int			client_len;

    ret = NULL;
    if ((cs = ::accept(sock, (struct sockaddr *)&sin_client, (socklen_t *)&client_len)) == -1)
      return (NULL);
    ret = new socketUnix(cs);
    return (ret);  
  }

  virtual SOCKET		realSock()
  {
    return (sock);
  }

  int		sendData(const void *data,
			 size_t size,
			 int flags) const
  {
    int           ret = send(sock, data, size, flags | MSG_NOSIGNAL);
    return (ret);
  }

  int		sendDataTo(const void *data,
			   size_t size,
			   int flags,
			   const SOCKADDR *sockaddr,
			   socklen_t socklen) const
  {
    int           ret = sendto(sock, data, size, flags, sockaddr, socklen);
    return (ret);
  }

  int		recvData(void *data,
			 size_t len,
			 int flags) const
  {
    int           ret = recv(sock, data, len, flags | MSG_NOSIGNAL);
    return (ret);
  }

  int		recvDataFrom(void *data,
			     size_t len,
			     int flags,
			     SOCKADDR *sockaddr,
			     socklen_t *socklen) const
  {
    int           ret = recvfrom(sock, data, len, flags, sockaddr, socklen);
    return (ret);

  }
};

typedef socketUnix AbstractSocket;

#endif
