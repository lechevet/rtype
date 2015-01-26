#include <iostream>
#include	"Starfield.hh"

Starfield::Starfield()
{
  setCoord(0, 0);
  setDensity(1920, 1080);
  setCoord2(_density.getX(), 0);
  _life = 0;
  _type = STARFIELD;
  _translation = -10;
  _damaged = false;
}


Starfield::~Starfield()
{
}


void	Starfield::getDamage(int damage, EntityType type)
{
}

bool	Starfield::move()
{
  _coord.setX(_coord.getX() + _translation);
  _coord2.setX(_coord2.getX() + _translation);
  if (_coord.getX() <= -(_density.getX()))
    _coord.setX(_coord2.getX() + _density.getX());
  if (_coord2.getX() <= -(_density.getX()))
    _coord2.setX(_coord.getX() + _density.getX());
  return (true);
}

bool	Starfield::checkDeath() const
{
  return (false);
}

Vector	Starfield::getCoord2() const
{
  return (_coord2);
}

void	Starfield::setCoord2(const Vector &coord2)
{
  _coord2 = coord2;
}

void	Starfield::setCoord2(int x, int y)
{
  _coord2.setX(x);
  _coord2.setY(y);
}
