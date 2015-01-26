#ifndef		ISOCKET_HH_
# define	ISOCKET_HH_

# include	<string>
# include	"CrossType.hh"
# include	"Definitions.hh"

class		ISocket
{
public:
  virtual ~ISocket() {};
  virtual bool	bind() = 0;
  virtual bool	listen() = 0;
  virtual void	close() = 0;
  virtual ISocket*	accept() = 0;
  virtual int	realSock() = 0;
  virtual int	sendData(const void *, size_t, int) const = 0;
  virtual int	sendDataTo(const void *, size_t, int, const SOCKADDR *, socklen_t) const = 0;
  virtual int	recvData(void *, size_t, int) const = 0;
  virtual int	recvDataFrom(void *, size_t, int, SOCKADDR *, socklen_t *) const = 0;
};

#endif
