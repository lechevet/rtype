#include	<SFML/Graphics.hpp>
#include	"SpriteGiver.hh"

SpriteGiver::SpriteGiver()
{
  this->loadSprite("sprites/r-typesheet42.gif", "Ship", IntRect(0, 0, 32, 20));
  this->loadSprite("sprites/r-typesheet21.gif", "Enemy", IntRect(16, 16, 64, 32));
  this->loadSprite("sprites/r-typesheet1.gif", "BasicWeapon", IntRect(104, 172, 80, 16));
  this->loadSprite("sprites/space.jpg", "Space");
  this->loadSprite("sprites/space2.png", "Space2");
}

SpriteGiver::~SpriteGiver()
{
}

Sprite		SpriteGiver::getSprite(const std::string &name)
{
  return (sprites[name].sprite);
}

void		SpriteGiver::loadSprite(const std::string &filename, const std::string &name, const IntRect &rect)
{
  sprites[name].texture.loadFromFile(filename, rect);
  sprites[name].sprite.setTexture(sprites[name].texture);
}

void		SpriteGiver::loadSprite(const std::string &filename, const std::string &name)
{
  sprites[name].texture.loadFromFile(filename);
  sprites[name].sprite.setTexture(sprites[name].texture);
}
