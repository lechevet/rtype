#ifndef		SERVER_HH
# define	SERVER_HH

# include	"LobbyManager.hh"

class		Server
{
private:
  ClientManager	_clientManager;
  LobbyManager	_lobbyManager;
  ISocket	*_sock;
  int		_ids;

public:
  Server();
  ~Server();

  LobbyManager&	getLobbyManager();
  ISocket*	getSock() const;
  int		getIds() const;
  Client*	getClient(int) const;
  void		addClient();

  void		setLobbyManager(LobbyManager &);
  void		setSock(ISocket *);
  void		setIds(int);
};

#endif
