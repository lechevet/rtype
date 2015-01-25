#include <iostream>
#include "game/Enemy.hh"
#include <stdlib.h>

Enemy::Enemy(int id)
{
  size_t y;

  setDensity(64, 32);
  y = rand() % (RES_Y - _density.getY());
  if (y <= 0)
    y = 0;
  _coord.setY(y);
  _coord.setX(RES_X + _density.getX());
  _type = ENEMY;
  _life = 40;
  _translation = -3;
  _id = id;
  _power = 5;
  gettimeofday(&_start, NULL);
  _damaged = false;
}

Enemy::~Enemy()
{
}

extern "C" Enemy*	Create(int id)
{
  return (new Enemy(id));
}

int		Enemy::getLife() const
{
  return (_life);
}

void		Enemy::getDamage(int power, EntityType type)
{
  if (type != ENEMY && type != STARFIELD)
    {
      _life -= power;
      _damaged = true;
      gettimeofday(&_start, NULL);
    }
}

bool		Enemy::move()
{
  TIMEVAL	end;

  gettimeofday(&end, NULL);
  if (end.tv_sec > _start.tv_sec)
    _damaged = false;
  else if (end.tv_usec - _start.tv_usec >= 200000)
    _damaged = false;
  _coord.setX(_coord.getX() + _translation);
  if (_coord.getX() <= -_density.getX())
    return (false);
  return (true);
}

extern "C" void		Destroy(Enemy *enemy)
{
  delete (enemy);
}
