#include	"AEntity.hh"

void		AEntity::setTranslation(float translation)
{
  _translation = translation;
}

void		AEntity::setCoord(const Vector &coord)
{
  _coord = coord;
}

void		AEntity::setCoord(int x, int y)
{
  _coord.setX(x);
  _coord.setY(y);
}

void		AEntity::setId(int id)
{
  _id = id;
}

void		AEntity::setLife(int life)
{
  _life = life;
}

void		AEntity::setDensity(int x, int y)
{
  _density.setX(x);
  _density.setY(y);
}

void		AEntity::setDensity(const Vector &vector)
{
  _coord = vector;
}

Vector		AEntity::getCoord() const
{
  return (_coord);
}

float		AEntity::getTranslation() const
{
  return (_translation);
}

int		AEntity::getId() const
{
  return (_id);
}

int		AEntity::getLife() const
{
  return (_life);
}

EntityType	AEntity::getType() const
{
  return (_type);
}

Vector		AEntity::getDensity() const
{
  return (_density);
}

bool		AEntity::checkDeath() const
{
  if (_life <= 0)
    return (true);
  return (false);
}
