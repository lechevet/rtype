#ifndef		CLIENTMANAGER_HH
# define	CLIENTMANAGER_HH

# include	<list>
# include	"Client.hh"

class		ClientManager
{
private:
  std::list<Client *>	_clients;
  
public:
  ClientManager();
  ClientManager(const ClientManager &);
  ~ClientManager();

  ClientManager&	operator=(const ClientManager &);

  void		add(Client *);
  void		remove(Client *);
  Client*	get(int) const;
  Client*	findById(int) const;
  Client*	findBySockAddr(struct sockaddr_in *);
  void		remove_all();
  int		count();
};

#endif
