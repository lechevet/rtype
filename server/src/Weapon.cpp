#include	"Weapon.hh"
#include <iostream>

Weapon::Weapon(IEntity *entity, int id)
{
  setCoord(entity->getCoord().getX() + entity->getDensity().getX(), entity->getCoord().getY());
  _type = WEAPON;
  _power = 5;
  _delay = 10;
  _life = 1;
  _translation = 6;
  _id = id;
  setDensity(80, 16);
}

Weapon::~Weapon()
{
}

void		Weapon::doDamage(IEntity *entity)
{
  /* collisions */
  entity->getDamage(_power, _type);
}

int		Weapon::getPower() const
{
  return (_power);
}

int		Weapon::getDelay() const
{
  return (_delay);
}

void		Weapon::getDamage(int damage, EntityType type)
{
}

bool		Weapon::move()
{
  if (_coord.getX() >= RES_X)
    return (false);
  return (true);
}
