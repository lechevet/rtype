#ifndef		GAME_HH
# define	GAME_HH

# include	"EntityManager.hpp"
# include	"Starfield.hh"

class		Game
{
private:
  EntityManager<IEntity*>	_entityManager;
  EntityManager<Ship*>		_shipManager;

public:
  Game();
  ~Game();

  EntityManager<IEntity*>	getEntityManager() const;
  EntityManager<Ship*>		getShipManager() const;

  void				setEntityManager(EntityManager<IEntity*> &);
  void				setShipManager(EntityManager<Ship*> &);

  void				addShip(int);
  void				removeShip(int);
  void				updateShip(EnumData, int);
  int				shipNumber() const;

  int				update();
  int				reset();
};

#endif
