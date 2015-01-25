#include	<sys/time.h>
#include	"game/Game.hh"

Game::Game()
{
   _entityManager.add(new Starfield());
}

Game::~Game()
{
}

EntityManager<IEntity*>		Game::getEntityManager() const
{
  return (_entityManager);
}

EntityManager<Ship*>		Game::getShipManager() const
{
  return (_shipManager);
}

void				Game::setEntityManager(EntityManager<IEntity*> &entityManager)
{
  _entityManager = entityManager;
}

void				Game::setShipManager(EntityManager<Ship*> &shipManager)
{
  _shipManager = shipManager;
}

void				Game::addShip(int id)
{
  Ship				*ship = new Ship(id);

  _entityManager.add(ship);
  _shipManager.add(ship);
}

void				Game::removeShip(int id)
{
  Ship				*ship;

  ship = _shipManager.findById(id);
  _entityManager.remove((IEntity *)ship);
  _shipManager.remove(ship);
}

void				Game::updateShip(EnumData data, int id)
{
  _shipManager.findById(id)->setDirection(data);
}

int				Game::update()
{
  return (_entityManager.updateEntities());
    
}

void				Game::reset()
{
  _entityManager.removeAll();
  _entityManager.add(new Starfield());
}
