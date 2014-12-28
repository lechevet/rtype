#include	"EntityManager.hh"

template<typename Type>
EntityManager<Type>::EntityManager()
{
}

template<typename Type>
EntityManager<Type>::~EntityManager()
{
}

template<typename Type>
void		EntityManager<Type>::add(Type entity)
{
  _list.push_back(entity);
}

template<typename Type>
void		EntityManager<Type>::remove(Type entity)
{
  std::list<Type>::iterator	it;

  it = _list.begin();
  while (it != _list.end() && entity != *it)
    ++it;
  if (it != _list.end())
    _list.erase(it);
}

template<typename Type>
void		EntityManager<Type>::removeAll()
{
  std::list<Type>::iterator	it;

  it = _list.begin();
  while (it != _list.end())
    it = _list.erase(it);
}

template<typename Type>
IEntity*	EntityManager<Type>::find(int index) const
{
  std::list<Type>::const_iterator	it = _list.begin();
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

template<typename Type>
IEntity*	EntityManager<Type>::findById(int id) const
{
  std::list<Type>::const_iterator	it = _list.begin();

  while (it != _list.end() && (*it)->getId() != id)
    ++it;
  if (it == _list.end())
    return (NULL);
  return (*it);
}

template<typename Type>
void		EntityManager<Type>::updateEntities()
{
  std::list<Type>::iterator	it;

  it = _list.begin();
  while (it != _list.end())
    {
      //      shoot(*it);
      collision(*it);
      if (move(*it) == false)
	it = _list.erase(it);
      else
	++it;
    }
}

template<typename Type>
void		EntityManager<Type>::shoot()
{
  // if (entity->getType() == SHIP)
  //   {
  //     if (((Ship *)entity)->isShooting() == true)
  // 	{
  // 	  add(new BasicWeapon(entity, _ids));
  // 	  ++_ids;
  // 	}
  //   }
}

template<typename Type>
void		EntityManager<Type>::collision(Type entity)
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

template<typename Type>
bool		EntityManager<Type>::move(Type entity)
{
  if ((entity->move() == false) || (entity->checkDeath() == true))
    return (false);
  return (true);
}

template<typename Type>
void		EntityManager<Type>::spawningEnemies()
{
  // if (rand() % 100 == 2)
  //   add(loader.getInstanceObject(sprites));
}
