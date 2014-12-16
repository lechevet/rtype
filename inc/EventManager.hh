#ifndef		EVENTMANAGER_HH
# define	EVENTMANAGER_HH

# include	<SFML/Graphics.hpp>
# include	"Ship.hh"
# include	"Enemy.hh"
# include	"EntityManager.hh"

class		EventManager
{
private:
  std::map<Keyboard::Key, bool>	keyState;
  RenderWindow	*app;
  Clock		clock;

public:
  EventManager(RenderWindow *);
  ~EventManager();
  void		checkEvent(EntityManager &entityManager, IEntity *ship);
  void		spawningEnemies(EntityManager &entityManager, SpriteGiver &sprites);
  std::map<Keyboard::Key, bool>&	getKeyState();
  void		setKeyState(std::map<Keyboard::Key, bool> &);
};

#endif
