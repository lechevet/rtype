#ifndef		ENTITYMANAGER_HH
# define	ENTITYMANAGER_HH

# include	<vector>
# include	<list>
# include	"IEntity.hpp"
# include	"AEntity.hh"

class		EntityManager
{
private:
  std::list<IEntity *>	_list;
  SpriteGiver	sprites;
  int		id;
  float		framerate;

  bool		collisions(IEntity *first, IEntity *second);

public:
  EntityManager(const SpriteGiver &);
  ~EntityManager();
  void		add(IEntity *);
  void		remove(IEntity *);
  void		remove(int);
  IEntity*	find(int) const;
  IEntity*	findById(int);
  void		updateEntities(RenderWindow &, Clock &);
  void		shoot(IEntity *);
  bool		collision(IEntity *);
  bool		move(IEntity *);
  void		draw(RenderWindow &, IEntity *);
};

#endif
