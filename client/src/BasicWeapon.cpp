#include	"BasicWeapon.hh"
#include <iostream>

BasicWeapon::BasicWeapon(IEntity *entity, SpriteGiver &sprites)
{
  FloatRect	frect = entity->getSprite().getGlobalBounds();

  sprite = sprites.getSprite("BasicWeapon");
  sprite.setScale(Vector2f(2, 2));
  sprite.setPosition(Vector2f(frect.left + frect.width, frect.top + (frect.height / 2)));
  weaponType = BASICWEAPON;
  type = WEAPON;
  power = 5;
  delay = 10;
  life = 1;
}

BasicWeapon::~BasicWeapon()
{
}
