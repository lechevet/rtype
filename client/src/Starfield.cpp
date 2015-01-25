#include <iostream>
#include	"Starfield.hh"

Starfield::Starfield(SpriteGiver &sprites)
{
  sprite = sprites.getSprite("Space");
  sprite2 = sprites.getSprite("Space2");
  sprite.setPosition(Vector2f(0, 0));
  sprite2.setPosition(Vector2f(sprite.getGlobalBounds().width, 0));
  life = 0;
  type = STARFIELD;
  mainSprite = &sprite;
  secondSprite = &sprite2;
}


Starfield::~Starfield()
{
}


void	Starfield::getDamage(int damage)
{
}

bool	Starfield::move()
{
  float		moving = 0.2 * framerate;
  float		speed = moving * 1.6 * (WINWIDTH / 800);

  this->translation(Vector2f(-speed, 0));
  if (this->getPosition().x <= -(mainSprite->getGlobalBounds().width))
    {
      changePosition(Vector2f(secondSprite->getGlobalBounds().left + secondSprite->getGlobalBounds().width, 0));
      if (mainSprite == &sprite)
  	{
  	  mainSprite = &sprite2;
  	  secondSprite = &sprite;
  	}
      else
  	{
  	  mainSprite = &sprite;
  	  secondSprite = &sprite2;
  	}
    }
  return (true);
}

bool	Starfield::checkDeath() const
{
  return (false);
}

void		Starfield::translation(const Vector2f &vector)
{
  mainSprite->move(vector);
  secondSprite->move(vector);
}

void		Starfield::changeScale(const Vector2f &vector)
{
  mainSprite->setScale(vector);
  secondSprite->move(vector);
}

void		Starfield::changePosition(const Vector2f &vector)
{
  mainSprite->setPosition(vector);
}

Vector2f	Starfield::getPosition()
{
  return (mainSprite->getPosition());
}

void		Starfield::draw(RenderWindow &render)
{
  render.draw(sprite);
  render.draw(sprite2);
}
