#include	"Game.hh"
#include	<stdlib.h>
#include	<sys/time.h>
#include <iostream>


Game::Game(ClientManager &clientManager)
{
  Ship	*ship;

  _clientManager = clientManager;
  _sock = new AbstractSocket(UDP);
  ship = new Ship(0);
  ship->setActivity(true);
  _ships.add(ship);
  _ships.add(new Ship(1));
  _ships.add(new Ship(2));
  _ships.add(new Ship(3));
  
}

Game::~Game()
{
}

void		Game::newClient(Client *client)
{
  _ships.findById(client->getId())->setActivity(true);
}

bool		Game::checkLife() const
{
  int		i = 0;
  Ship		*tmp;

  while ((tmp = _ships.find(i)) != NULL)
    {
      if (tmp->isActive() == true)
	return (true);
      ++i;
    }
  return (false);
}

void		Game::getInfoFromClients()
{
  // std::list<Client *>::iterator	it;
  
  // it = _clientManager.begin();
  // while (it != _clientManager.end())
  //   {
  //     keys[(*it)->getId()] = (*it)->getSock()->recvDataFrom(
  //   }
}

void		Game::start()
{
  struct timeval	start;
  struct timeval	end;
  double		frame;
  int			i = 0;
  srand(time(NULL));
  while (checkLife() == true)
    {
      gettimeofday(&start, NULL);
      _entityManager.spawningEnemies();
      _entityManager.updateEntities();
      gettimeofday(&end, NULL);
      frame = ((double)(1000000*(end.tv_sec-start.tv_sec)+((end.tv_usec-start.tv_usec))));
      usleep(1000000 / 72 - frame);
      std::cout << ++i << std::endl;
    }
}
