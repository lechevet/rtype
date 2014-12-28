#include <iostream>
#include "Enemy.hh"
#include <stdlib.h>
#include <time.h>

Enemy::Enemy(int id)
{
  int	y;

  y = rand() % (RES_Y - _density.getY());
  if (y <= 0)
    y = 0;
  _coord.setX(RES_X + _density.getX());
  _type = ENEMY;
  _life = 5;
  _translation = -3;
  _id = id;
  setDensity(64, 32);
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
  // FloatRect	frect = sprite.getGlobalBounds();
  // float		speed = 0.1 * framerate;

  if (type == WEAPON)
    {
      _life -= power;
      //      this->translation(Vector2f(speed, 0));
    }
}

bool		Enemy::move()
{
  // static int	delay = 0;
  // FloatRect	frect = sprite.getGlobalBounds();
  // float		speed = ((0.4 * framerate) / 4) * (WINWIDTH / 800);

  // if (sprite.getColor() == Color::Red)
  //   {
  //     delay += framerate;
  //     if (delay >= 900)
  // 	{
  // 	  sprite.setColor(Color::White);
  // 	  delay = 0;
  // 	}
  //   }
  // this->translation(Vector2f(-speed, 0));
  if (_coord.getX() == -_density.getX())
    return (false);
  return (true);
}

extern "C" void		Destroy(Enemy *enemy)
{
  delete (enemy);
}
