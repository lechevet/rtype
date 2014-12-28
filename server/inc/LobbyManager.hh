#ifndef		LOBBYMANAGER_HH
# define	LOBBYMANAGER_HH

# include	<list>
# include	"Lobby.hh"

class		LobbyManager
{
private:
  std::list<Lobby *>	_list;
  int			_ids;

public:
  LobbyManager();
  ~LobbyManager();
  void		add();
  void		addClient(Client *);
  void		remove(Lobby *);
  Lobby*	get(int);
  int		count();
  void		remove_all();
};

#endif
