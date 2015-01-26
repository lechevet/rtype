#ifndef		ENTITYMANAGER_HH
# define	ENTITYMANAGER_HH

# include	<stdlib.h>
# include	<time.h>
# include	<list>
# include	"IEntity.hpp"
# include	"DynamicLibrariesLoader.hh"
# include	"Ship.hh"
# include	<iostream>
# include	"Weapon.hh"

template<typename Type>
class		EntityManager
{
private:
  std::list<Type>	_list;
  int			_ids;
/*  DynamicLibrariesLoader	_loader;*/

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
	  {
		  add(new Enemy(_ids));
		/*  add(_loader.getInstanceObject(_ids)); */
		  ++_ids;
	  }
  }


  void		shoot(IEntity *entity)
  {
	Ship	*tmp;

	if (entity->getType() == SHIP)
	  {
	tmp = (Ship *)entity;
		if (tmp->isShooting() == true)
		  add(new Weapon(entity, getIds()));
	  }
  }

  bool		move(Type entity)
  {
	if (entity->move() == false)
	  return (false);
	return (true);
  }

  int		getIds()
  {
	return (_ids);
  }

  int		count()
  {
	return (_list.size());
  }

  void collision(IEntity* first)
  {
	IEntity *second;
	int	i = 0;
	
	while ((second = find(i)))
	  {
	if (second->getId() != first->getId())
	  {
		if ((second->getCoord().getX() >= first->getCoord().getX() + first->getDensity().getX())
		|| (second->getCoord().getX() + second->getDensity().getX() <= first->getCoord().getX())
		|| (second->getCoord().getY() >= first->getCoord().getY() + first->getDensity().getY())
		|| (second->getCoord().getY() + second->getDensity().getY() <= first->getCoord().getY()))
		  {
		  }
		else
		  {
		first->getDamage(second->getPower(), first->getType());
		second->getDamage(first->getPower(), first->getType());
		  }
	  }
	++i;
	  }
  }

  int	updateEntities()
  {
	typename std::list<Type>::iterator	it;
	typename std::list<Type>::iterator	tmp;
	int	id;

	it = _list.begin();
	spawningEnemies();
	while (it != _list.end())
	  {
	tmp = it;
	if (move(*it) == false)
	  tmp = _list.erase(it);
	else
	  {
		shoot(*it);
		collision(*it);
		if ((*it)->checkDeath() == true)
		  {
		id = (*it)->getId();
		tmp = _list.erase(it);
		if ((*it)->getType() == SHIP)
		  return (id);
		  }
	  }
	if (tmp != it)
	  it = tmp;
	else
	  ++it;
	  }
	return (-1);
  } 
  };

#endif
