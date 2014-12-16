#include	<iostream>
#include	"AEntity.hh"

Sprite&		AEntity::getSprite()
{
  return (sprite);
}

void		AEntity::setFramerate(const float newFramerate)
{
  framerate = newFramerate;
}

void		AEntity::setSprite(const std::string &filepath, const Vector2f &pos, const Vector2f &vector)
{
  Texture texture;

  texture.loadFromFile(filepath, IntRect(pos.x, pos.y, vector.x, vector.y));
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(0, 0));
  sprite.setScale(Vector2f(1.5, 1.5));
}

void		AEntity::translation(const Vector2f &vector)
{
  sprite.move(vector);
}

void		AEntity::changeScale(const Vector2f &vector)
{
  sprite.setScale(vector);
}

void		AEntity::changePosition(const Vector2f &vector)
{
  sprite.setPosition(vector);
}

Vector2f	AEntity::getPosition()
{
  return (sprite.getPosition());
}

EntityType	AEntity::getType() const
{
  return (type);
}

bool		AEntity::checkDeath() const
{
  if (life <= 0)
    return (true);
  return (false);
}

int		AEntity::getId() const
{
  return (id);
}

void		AEntity::setId(int nb)
{
  id = nb;
}

void		AEntity::draw(RenderWindow &render)
{
  render.draw(sprite);
}
