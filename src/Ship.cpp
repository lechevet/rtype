#include	"Ship.hh"

Ship::Ship()
{
  texture.loadFromFile("sprites/r-typesheet42.gif", IntRect(0, 0, 32, 20));
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(0, 0));
  sprite.setScale(Vector2f(1.5, 1.5));
  type = SHIP;
}

Ship::~Ship()
{
}

void	Ship::getDamage(int damage, EnumSound type)
{
  if (type == ENEMYWEAPON)
    life -= damage;
}

AWeapon	Ship::getWeapon() const
{
  return (weapon);
}

void	Ship::setWeapon(const AWeapon &newWeapon)
{
  weapon = newWeapon;
}
