#include <iostream>
#include "EntityManager.hh"
#include "Ship.hh"
#include "BasicWeapon.hh"

EntityManager::EntityManager(const SpriteGiver &_sprites)
{
  sprites = _sprites;
  framerate = 0;
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
  entity->setId(id);
  ++id;
  _list.push_back(entity);
}

void		EntityManager::remove(IEntity *entity)
{
  std::list<IEntity *>::iterator	it;

  if (entity)
    {
      it = _list.begin();
      while (it != _list.end() && *it != entity)
	++it;
      if (*it == entity)
	_list.erase(it);
    }
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

IEntity*	EntityManager::find(int index) const
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


IEntity*	EntityManager::findById(int id)
{
  std::list<IEntity *>::iterator	it;

  it = _list.begin();
  while (it != _list.end() && (*it)->getId() != id)
    ++it;
  return (*it);
}

void		EntityManager::updateEntities(RenderWindow &render, Clock &clock)
{
  std::list<IEntity *>::iterator	it;
  Time		frameTime = clock.restart();
  float		newFramerate = 1 / (frameTime.asSeconds());

  framerate = newFramerate;
  it = _list.begin();
  while (it != _list.end())
    {
      (*it)->setFramerate(framerate);
      shoot(*it);
      collision(*it);
      if (move(*it) == false)
	it = _list.erase(it);
      else
	{
	  draw(render, *it);
	  ++it;
	}
    }
}

void		EntityManager::shoot(IEntity *entity)
{
  if (entity->getType() == SHIP)
    {
      if (((Ship *)entity)->isShooting() == true)
	add(new BasicWeapon(entity, sprites));
    }
}

void		EntityManager::collision(IEntity *entity)
{
  static float	delay = 0;

  if (entity->getSprite().getColor() == Color::White)
    {
      delay += framerate;
      if (delay > 900)
	{
	  if (entity->getType() == ENEMY)
	    entity->getDamage(0, BASICWEAPON);
	  delay = 0;
	}
    }
}

bool		EntityManager::move(IEntity *entity)
{
  if ((entity->move() == false) || (entity->checkDeath() == true))
    return (false);
  return (true);
}

void		EntityManager::draw(RenderWindow &render, IEntity *entity)
{
  entity->draw(render);
}



