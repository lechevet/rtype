#include	<iostream>
#include        "game/Ship.hh"

Ship::Ship(int id)
{
  _coord.setX(0);
  _coord.setY(0);
  _key[UP] = false;
  _key[LEFT] = false;
  _key[DOWN] = false;
  _key[RIGHT] = false;
  _key[SPACE] = false;
  _type = SHIP;
  _life = 40;
  _translation = 8;
  _id = id;
  _power = 5;
  _damaged = false;
  setDensity(48, 30);
  gettimeofday(&_time, NULL);
  gettimeofday(&_start, NULL);
}

Ship::~Ship()
{
}

void            Ship::setDirection(EnumData data)
{
  if (data == UPDATA)
    _key[UP] = true;
  if (data == DOWNDATA)
    _key[DOWN] = true;
  if (data == LEFTDATA)
    _key[LEFT] = true;
  if (data == RIGHTDATA)
    _key[RIGHT] = true;
  if (data == SPACEDATA)
    _key[SPACE] = true;
  if (data == RELEASEUPDATA)
    _key[UP] = false;
  if (data == RELEASEDOWNDATA)
    _key[DOWN] = false;
  if (data == RELEASERIGHTDATA)
    _key[RIGHT] = false;
  if (data == RELEASELEFTDATA)
    _key[LEFT] = false;
  if (data == RELEASESPACEDATA)
    _key[SPACE] = false;

}

bool            Ship::move()
{
  TIMEVAL	end;

  gettimeofday(&end, NULL);
  if (end.tv_sec > _time.tv_sec)
    _damaged = false;
  else if (end.tv_usec - _time.tv_usec >= 200000)
    _damaged = false;
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

bool            Ship::isShooting()
{
  TIMEVAL	end;

  gettimeofday(&end, NULL);
  if (end.tv_sec - _start.tv_sec >= 1)
    {
      gettimeofday(&_start, NULL);
      return (_key[SPACE]);
    }
  else if (end.tv_usec - _start.tv_usec >= 200000)
    {
      gettimeofday(&_start, NULL);
      return (_key[SPACE]);
    }
  return (false);
}

void            Ship::getDamage(int damage, EntityType type)
{
  if (type == ENEMY && _damaged == false)
    {
      _life -= damage;
      _damaged = true;
      gettimeofday(&_time, NULL);
    }
}
