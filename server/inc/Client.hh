#ifndef		CLIENT_HH
# define	CLIENT_HH

# include	"ISocket.hh"
# include	"Socket.hh"

class		Client
{
private:
  ISocket	*_sock;
  std::string	_sendBuffer;
  std::string	_recvBuffer;
  int		_id;

public:
  Client();
  Client(int);
  Client(const Client &);
  ~Client();

  ISocket*	getSock() const;
  std::string	getSendBuffer() const;
  std::string	getRecvBuffer() const;
  int		getId() const;

  void		setSock(ISocket *);
  void		setSendBuffer(const std::string &);
  void		setRecvBuffer(const std::string &);
  void		setId(int);

  bool		operator!=(Client&) const;
  bool		operator==(Client &) const;

};

#endif
