#include <iostream>
#include "Enemy.hh"

Enemy::Enemy(SpriteGiver &sprites)
{
  int	y;

  y = rand() % WINHEIGHT - sprite.getGlobalBounds().height;
  if (y <= 0)
    y = 0;
  sprite = sprites.getSprite("Enemy");
  sprite.setScale(Vector2f(2, 2));
  sprite.setPosition(Vector2f(WINWIDTH + sprite.getGlobalBounds().width, y));
  type = ENEMY;
  life = 5;
}

Enemy::~Enemy()
{
}

extern "C" Enemy*	Create(SpriteGiver &sprites)
{
  return (new Enemy(sprites));
}

int		Enemy::getLife() const
{
  return (life);
}

void		Enemy::getDamage(int power, EnumSound type)
{
  FloatRect	frect = sprite.getGlobalBounds();
  float		speed = 0.1 * framerate;

  if (type != ENEMYWEAPON)
    {
      life -= power;
      this->translation(Vector2f(speed, 0));
      sprite.setColor(Color::Red);
    }
}

bool		Enemy::move()
{
  static int	delay = 0;
  FloatRect	frect = sprite.getGlobalBounds();
  float		speed = ((0.4 * framerate) / 4) * (WINWIDTH / 800);

  if (sprite.getColor() == Color::Red)
    {
      delay += framerate;
      if (delay >= 900)
	{
	  sprite.setColor(Color::White);
	  delay = 0;
	}
    }
  this->translation(Vector2f(-speed, 0));
  if (this->getPosition().x == -frect.width)
    return (false);
  return (true);
}

extern "C" void		Destroy(Enemy *enemy)
{
  delete (enemy);
}
