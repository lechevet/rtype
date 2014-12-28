#ifndef		LOBBY_HH
# define	LOBBY_HH

# include	"ClientManager.hh"

class		Lobby
{
private:
  ClientManager	_clientManager;
  int		_activeClients;
  int		_id;

  void		numberClients();

public:
  Lobby(int id);
  Lobby(const Lobby &);
  ~Lobby();

  Lobby&		operator=(const Lobby &);
  ClientManager&	getClientManager();
  void			addClient(Client *);
  int			getNumberClients() const;
  int			getId() const;

  bool			operator!=(Lobby&) const;
  bool			operator==(Lobby &) const;
};

#endif
