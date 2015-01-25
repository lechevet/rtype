#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"SpriteGiver.hh"

SpriteGiver::SpriteGiver()
{
  this->loadSprite(SHIP, "sprites/r-typesheet42.gif", "Ship", IntRect(0, 0, 32, 20));
  this->loadSprite(ENEMY, "sprites/r-typesheet21.gif", "Enemy", IntRect(16, 16, 64, 32));
  this->loadSprite(WEAPON, "sprites/r-typesheet1.gif", "BasicWeapon", IntRect(104, 172, 80, 16));
  this->loadSprite(STARFIELD, "sprites/space.jpg", "Space");
  this->loadSprite(STARFIELD2, "sprites/space2.png", "Space2");
  this->loadSprite(GAMEOVER, "sprites/gameover.png", "GameOver");
  sprites[SHIP].sprite.setScale(Vector2f(1.5, 1.5));
}

SpriteGiver::~SpriteGiver()
{
}

Sprite		SpriteGiver::getSprite(const EntityType type)
{
  return (sprites[type].sprite);
}

void		SpriteGiver::loadSprite(const EntityType type, const std::string &filename, const std::string &name, const IntRect &rect)
{
  sprites[type].texture.loadFromFile(filename, rect);
  sprites[type].sprite.setTexture(sprites[type].texture);
}

void		SpriteGiver::loadSprite(const EntityType type, const std::string &filename, const std::string &name)
{
  sprites[type].texture.loadFromFile(filename);
  sprites[type].texture.setSmooth(true);
  sprites[type].sprite.setTexture(sprites[type].texture);
}
