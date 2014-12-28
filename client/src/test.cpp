#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define	WINHEIGHT	600
#define	WINWIDTH	800

using namespace sf;

int	main()
{
  RenderWindow app(VideoMode(WINWIDTH, WINHEIGHT, 32), "lol", Style::Close | Style::Resize | Style::Titlebar);
  Texture	texture;
  Sprite	sprite;
  View		view(FloatRect(0, 0, 800, 600));
  float		moving;
  FloatRect	frect;
  SoundBuffer	buffer;
  Sound		sound;

  app.setFramerateLimit(60);
  buffer.loadFromFile("music/ffbattle.wav");
  sound.setBuffer(buffer);
  texture.loadFromFile("sprites/r-typesheet42.gif", IntRect(0, 0, 32, 20));
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(0, 0));
  sprite.setScale(Vector2f(1.5, 1.5));
  frect = sprite.getGlobalBounds();
  Clock clock;
  sound.play();
  sound.setLoop(true);
  while (app.isOpen())
    {
      Event event;

      while (app.pollEvent(event))
      	{
	  switch (event.type)
	    {
	    case Event::Closed :
	      app.close();
	      break;
	    case Event::KeyPressed:
	      keyState[event.key.code] = true;
	      switch (event.key.code)
		{
		case Keyboard::Escape :
		  app.close();
		  break;
		default:
		  break;
		}
	      break;
	    case Event::KeyReleased:
	      keyState[event.key.code] = false;
	      break;
	    default:
	      break;
	    }
	}
      if (keyState[Keyboard::Up])
	{
	  if (sprite.getPosition().y >= moving)
	    sprite.move(Vector2f(0, -moving));
	}
      if (keyState[Keyboard::Down])
	{
	  if (sprite.getPosition().y + moving + frect.height < WINHEIGHT)
	    sprite.move(Vector2f(0, moving));
	}
      if (keyState[Keyboard::Left])
	{
	  if (sprite.getPosition().x >= moving)
	    sprite.move(Vector2f(-moving, 0));
	}
      if (keyState[Keyboard::Right])
	{
	  if (sprite.getPosition().x + moving + frect.width < WINWIDTH)
	    sprite.move(Vector2f(moving, 0));
	}
      app.clear();
      app.draw(sprite);
      app.setView(view);
      app.display();
    }
  return (0);
}
