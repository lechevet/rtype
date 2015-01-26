#include	"Weapon.hh"

Weapon::Weapon(IEntity *entity, int id)
{
  setCoord(entity->getCoord().getX() + entity->getTranslation() + 1, entity->getCoord().getY());
  _translation = 12;
  _id = id;
  _life = 1;
  _type = WEAPON;
  _power = 10;
  setDensity(80, 16);
  _damaged = false;
}

Weapon::~Weapon()
{
}

int		Weapon::getDelay() const
{
  return (_delay);
}

void		Weapon::setDelay(int delay)
{
  _delay = delay;
}

bool		Weapon::move()
{
  _coord.setX(_coord.getX() + _translation);
  if (_coord.getX() >= RES_X)
    return (false);
  return (true);
}

void		Weapon::getDamage(int damage, EntityType type)
{
  if (type != WEAPON && type != SHIP)
    _life -= damage;
}
