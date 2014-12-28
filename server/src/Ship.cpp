#include	"Ship.hh"

Ship::Ship(int id)
{
  _coord.setX(0);
  _coord.setY(0);
  _translation = 0;
  _activity = false;
  _key[UP] = false;
  _key[LEFT] = false;
  _key[DOWN] = false;
  _key[RIGHT] = true;
  _key[SPACE] = false;
  _type = SHIP;
  _life = 40;
  _translation = 5;
  _id = id;
  setDensity(80, 50);
}

Ship::~Ship()
{
}

void		Ship::setActivity(bool activity)
{
  _activity = activity;
}

void		Ship::setDirection(Command key, bool boolean)
{
  _key[key] = boolean;
}


bool		Ship::isActive() const
{
  return (_activity);
}

bool		Ship::move()
{
  if (_key[UP] == true)
    {
      if (_coord.getY() - _translation >= 0)
	_coord.setY(_coord.getY() - _translation);
    }
  if (_key[DOWN] == true)
    {
      if (_coord.getY() + _translation + _density.getY() <= RES_Y)
	_coord.setY(_coord.getY() + _translation);
    }
  if (_key[LEFT] == true)
    {
      if (_coord.getX() - _translation >= 0)
	_coord.setX(_coord.getX() - _translation);
    }
  if (_key[RIGHT] == true)
    {
      if (_coord.getX() + _translation + _density.getX() <= RES_X)
	_coord.setX(_coord.getX() + _translation);
    }
  return (true);
}

bool		Ship::isShooting()
{
  return (_key[SPACE]);
}

void		Ship::getDamage(int damage, EntityType type)
{
  if (type != WEAPON && type != SHIP)
    _life -= damage;
}
