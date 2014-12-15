#ifndef		ENTITYMANAGER_HH
# define	ENTITYMANAGER_HH

# include	<list>
# include	"IEntity.hpp"
# include	"AEntity.hh"

class		EntityManager
{
private:
  std::list<IEntity *>	_list;

public:
  EntityManager();
  ~EntityManager();
  void		add(IEntity *);
  void		remove(IEntity *);
  void		remove(int);
  IEntity*	get(int) const;
  void		draw_all(RenderWindow &);
  void		enemyScrolling();
};

#endif
