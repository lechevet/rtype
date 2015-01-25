#include	"game/Vector.hh"

Vector::Vector()
{
  _x = 0;
  _y = 0;
}

Vector::Vector(int x, int y)
{
  _x = x;
  _y = y;
}

Vector::~Vector()
{
}

int		Vector::getX() const
{
  return (_x);
}

int		Vector::getY() const
{
  return (_y);
}

void		Vector::setX(int x)
{
  _x = x;
}

void		Vector::setY(int y)
{
  _y = y;
}
