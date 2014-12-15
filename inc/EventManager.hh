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
  void		checkEvent();
  void		shipReaction(Ship *, const Vector2f &);
  void		spawningEnemies(EntityManager &entityManager);
};

#endif
