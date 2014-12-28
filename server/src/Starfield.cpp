#include <iostream>
#include	"Starfield.hh"

Starfield::Starfield()
{
  setCoord(0, 0);
  setDensity(1920, 1080);
  _life = 0;
  _type = STARFIELD;
  _translation = -5;
}


Starfield::~Starfield()
{
}


void	Starfield::getDamage(int damage, EntityType type)
{
}

bool	Starfield::move()
{
  return (true);
}

bool	Starfield::checkDeath() const
{
  return (false);
}
