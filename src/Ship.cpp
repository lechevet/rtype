#include	<iostream>
#include	"Ship.hh"
#include	"BasicWeapon.hh"

Ship::Ship(SpriteGiver &sprites)
{
  sprite = sprites.getSprite("Ship");
  sprite.setPosition(Vector2f(0, 0));
  sprite.setScale(Vector2f(1.5, 1.5));
  weapon = new BasicWeapon(this, sprites);
  type = SHIP;
  life = 10;
}

Ship::~Ship()
{
}

void	Ship::getDamage(int damage, EnumSound type)
{
  if (type == ENEMYWEAPON)
    life -= damage;
}

AWeapon*	Ship::getWeapon() const
{
  return (weapon);
}

void	Ship::setWeapon(AWeapon *newWeapon)
{
  weapon = newWeapon;
}

void		Ship::setKeyState(std::map<Keyboard::Key, bool> &theState)
{
  keyState = theState;
}

bool		Ship::move()
{
  FloatRect	frect = sprite.getGlobalBounds();
  float		moving = 0.2 * framerate;

  if (keyState[Keyboard::Up])
    {
      if (this->getPosition().y >= moving)
	this->translation(Vector2f(0, -moving));
    }
  if (keyState[Keyboard::Down])
    {
      if (this->getPosition().y + moving + frect.height < WINHEIGHT)
	this->translation(Vector2f(0, moving));
    }
  if (keyState[Keyboard::Left])
    {
      if (this->getPosition().x >= moving)
	this->translation(Vector2f(-moving, 0));
    }
  if (keyState[Keyboard::Right])
    {
      if (this->getPosition().x + moving + frect.width < WINWIDTH)
	this->translation(Vector2f(moving, 0));
    }
  return (true);
}

bool		Ship::isShooting()
{
  static int	delay = 0;
  bool		ret;

  delay += framerate;
  if (delay > (60 * weapon->getDelay()))
    {
      delay = 0;
      ret = keyState[Keyboard::Space];
      keyState[Keyboard::Space] = false;
      return (ret);
    }
  else
    return (false);
}


std::map<Keyboard::Key, bool>&	Ship::getKeyState()
{
  return (keyState);
}
