#ifndef		ENTITYMANAGER_HH
# define	ENTITYMANAGER_HH

# include	<stdlib.h>
# include	<time.h>
# include	<list>
# include	"IEntity.hpp"
# include	"DynamicLibrariesLoader.hh"
# include	"Ship.hh"
# include	"Weapon.hh"

template<typename Type>
class		EntityManager
{
private:
  std::list<Type>	_list;
  int			_ids;
  DynamicLibrariesLoader	_loader;

public:
  EntityManager() { _ids = 0; }
  ~EntityManager() {}

  void		add(Type entity)
  {
    _list.push_back(entity);
    ++_ids;
  }

  void		remove(Type entity)
  {
    typename std::list<Type>::iterator	it;

    it = _list.begin();
    while (it != _list.end() && entity != *it)
      ++it;
    if (it != _list.end())
      _list.erase(it);
  }

  void		removeAll()
  {
    typename std::list<Type>::iterator	it;

    it = _list.begin();
    while (it != _list.end())
      it = _list.erase(it);
  }
  void		remove(int index)
  {
    typename std::list<Type>::iterator	it;
    int		i = 0;

    it = _list.begin();
    while (it != _list.end() && i < index)
      {
	++i;
	++it;
      }
    if (it != _list.end())
      _list.erase(it);    
  }

  Type		find(int index) const
  {
    typename std::list<Type>::const_iterator	it = _list.begin();
    int		i = 0;

    while (it != _list.end() && i < index)
      {
	++it;
	++i;
      }
    if (it == _list.end())
      return (NULL);
    return (*it);
  }

  Type		findById(int id) const
  {
    typename std::list<Type>::const_iterator	it = _list.begin();

    while (it != _list.end() && (*it)->getId() != id)
      ++it;
    if (it == _list.end())
      return (NULL);
    return (*it);
  }

  void		spawningEnemies()
  {
    if (rand() % 100 == 2)
      add(_loader.getInstanceObject(_ids));
    ++_ids;
  }

  void		updateEntities()
  {
    typename std::list<Type>::iterator	it;

    it = _list.begin();
    while (it != _list.end())
      {
	collision(*it);
	if (move(*it) == false)
	  it = _list.erase(it);
	else
	  ++it;
      }
  }
  
  void		shoot(EntityManager &entityManager)
  {
    typename std::list<Type>::iterator	it = _list.begin();

    while (it != _list.end())
      {
	if (((Ship *)(*it))->isShooting() == true)
	  entityManager.add(new Weapon(*it, entityManager.getIds()));
      }
  }

  void		collision(Type entity)
  {
    // static float	delay = 0;

    // if (entity->getSprite().getColor() == Color::White)
    //   {
    //     delay += framerate;
    //     if (delay > 900)
    // 	{
    // 	  if (entity->getType() == ENEMY)
    // 	    entity->getDamage(0, BASICWEAPON);
    // 	  delay = 0;
    // 	}
    //   }
  }

  bool		move(Type entity)
  {
    if ((entity->move() == false) || (entity->checkDeath() == true))
      return (false);
    return (true);
  }

  int		getIds()
  {
    return (_ids);
  }
};

#endif
