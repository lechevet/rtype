#include	<iostream>
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

int		AWeapon::getDelay() const
{
  return (delay);
}

void		AWeapon::getDamage(int damage, EnumSound type)
{
}

bool		AWeapon::move()
{
  float		speed = (framerate * 0.4) * (WINWIDTH / 800);

  this->translation(Vector2f(speed, 0));
  if (this->getPosition().x > WINWIDTH | this->getPosition().y == WINHEIGHT)
    return (false);
  return (true);
}


