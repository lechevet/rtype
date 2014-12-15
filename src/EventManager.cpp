#include	<iostream>
#include	"EventManager.hh"
#include	"AEntity.hh"

EventManager::EventManager(RenderWindow *other)
{
  app = other;
}

EventManager::~EventManager()
{
}

void		EventManager::checkEvent()
{
  Event		event;

  while (app->pollEvent(event))
    {
      switch (event.type)
	{
	case Event::Closed :
	  app->close();
	  break;
	case Event::KeyPressed:
	  keyState[event.key.code] = true;
	  switch (event.key.code)
	    {
	    case Keyboard::Escape :
	      app->close();
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
}

void		EventManager::shipReaction(Ship *ship, const Vector2f &res)
{
  Time		frameTime = clock.restart();
  float		framerate = 1 / (frameTime.asSeconds());
  int		moving = 0.2 * framerate;
  FloatRect	frect = ship->getSprite().getGlobalBounds();

  if (keyState[Keyboard::Up])
    {
      if (ship->getPosition().y >= moving)
	ship->move(Vector2f(0, -moving));
    }
  if (keyState[Keyboard::Down])
    {
      if (ship->getPosition().y + moving + frect.height < res.y)
	ship->move(Vector2f(0, moving));
    }
  if (keyState[Keyboard::Left])
    {
      if (ship->getPosition().x >= moving)
	ship->move(Vector2f(-moving, 0));
    }
  if (keyState[Keyboard::Right])
    {
      if (ship->getPosition().x + moving + frect.width < res.x)
	ship->move(Vector2f(moving, 0));
    }
}

void		EventManager::spawningEnemies(EntityManager &entityManager)
{
  if (rand() % 100 == 2)
    entityManager.add(new Enemy());
}
