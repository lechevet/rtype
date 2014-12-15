#include	"Enemy.hh"

Enemy::Enemy()
{
  texture.loadFromFile("sprites/r-typesheet21.gif", IntRect(16, 16, 64, 32));
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(864, rand() % 600));
  type = ENEMY;
}

Enemy::~Enemy()
{
}

int		Enemy::getLife() const
{
  return (life);
}

void		Enemy::getDamage(int power, EnumSound type)
{
  if (type != ENEMYWEAPON)
    life -= power;
}
