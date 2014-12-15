#include	"AWeapon.hh"

void		AWeapon::doDamage(IEntity *entity)
{
  if (entity->getSprite().getPosition().x == sprite.getPosition().x &&
      entity->getSprite().getPosition().y == sprite.getPosition().y)
    entity->getDamage(power, weaponType);
}

EnumSound	AWeapon::getWeaponType() const
{
  return (weaponType);
}

int		AWeapon::getPower() const
{
  return (power);
}

float		AWeapon::getFrequence() const
{
  return (frequence);
}

void		AWeapon::getDamage(int damage, EnumSound type)
{
}
