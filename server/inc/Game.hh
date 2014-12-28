#ifndef		GAME_HH
# define	GAME_HH

# include	"CrossType.hh"
# include	"Definitions.hh"
# include	"ISocket.hh"
# include	"IEntity.hpp"
# include	"EntityManager.hpp"
# include	"Ship.hh"
# include	"ClientManager.hh"

class		Game
{
private:
  EntityManager<IEntity *>	_entityManager;
  EntityManager<Ship *>	_ships;
  DynamicLibrariesLoader	_loader;
  ClientManager	_clientManager;
  ISocket	*_sock;
  std::map<Command, bool> keys;

  bool		checkLife() const;
  void		getInfoFromClients();

public:
  Game(ClientManager &);
  ~Game();
  void		start();
  void		newClient(Client *client);
};

#endif