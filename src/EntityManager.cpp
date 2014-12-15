#include <iostream>
#include "EntityManager.hh"

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
  std::list<IEntity *>::iterator	it;
  IEntity*	tmp;

  it = _list.begin();
  while (it != _list.end())
    it = _list.erase(it);
}

void		EntityManager::add(IEntity *entity)
{
  _list.push_back(entity);
}

void		EntityManager::remove(IEntity *entity)
{
  std::list<IEntity *>::iterator	it;

  it = _list.begin();
  while (it != _list.end() && *it != entity)
    ++it;
  if (*it == entity)
    _list.erase(it);
}

void		EntityManager::remove(int index)
{
  std::list<IEntity *>::iterator	it;
  int					i;

  i = 0;
  it = _list.begin();
  while (it != _list.end() && i < index)
    {
      ++it;
      ++i;
    }
  if (it != _list.end())
    _list.erase(it);
}

IEntity*	EntityManager::get(int index) const
{
  std::list<IEntity *>::const_iterator	it;
  int		i;

  i = 0;
  it = _list.begin();
  while (it != _list.end() && i < index)
    {
      ++it;
      ++i;
    }
  if (it != _list.end())
    return (*it);
  return (NULL);
}

void		EntityManager::draw_all(RenderWindow &render)
{
  std::list<IEntity *>::iterator	it;

  it = _list.begin();
  while (it != _list.end())
    {
      render.draw((*it)->getSprite());
      ++it;
    }
}

void		EntityManager::enemyScrolling()
{
  std::list<IEntity *>::iterator	it;

  it = _list.begin();
  while (it != _list.end())
    {
      if ((*it)->getType() == ENEMY)
	(*it)->move(Vector2f(-2, 0));
      if ((*it)->getPosition().x == -64)
	it = _list.erase(it);
      ++it;
    }  
}
