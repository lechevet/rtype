#include	<iostream>
#include	"EventManager.hh"
#include	"AEntity.hh"
#include	"BasicWeapon.hh"

EventManager::EventManager(RenderWindow *other)
{
  app = other;
}

EventManager::~EventManager()
{
}

void		EventManager::checkEvent(EntityManager &entityManager, IEntity *ship)
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

void		EventManager::spawningEnemies(EntityManager &entityManager, SpriteGiver &sprites)
{
  if (rand() % 100 == 2)
    entityManager.add(new Enemy(sprites));
}

std::map<Keyboard::Key, bool>&	EventManager::getKeyState()
{
  return (keyState);
}

void		EventManager::setKeyState(std::map<Keyboard::Key, bool> &theState)
{
  keyState = theState;
}
