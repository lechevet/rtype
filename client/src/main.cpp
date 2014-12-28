#include	<iostream>
#include	<stdexcept>
#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Ship.hh"
#include	"EventManager.hh"
#include	"EntityManager.hh"
#include	"Definitions.hh"
#include	"AudioManager.hh"
#include	"Enemy.hh"
#include	"Starfield.hh"
#include	"DynamicLibrariesLoader.hh"

int	main()
{

  RenderWindow app(VideoMode(WINWIDTH, WINHEIGHT, 32), "R-Type", Style::Close);
  SpriteGiver	sprites;
  IEntity	*ship;
  EntityManager	entityManager(sprites);
  AudioManager	audioManager;
  Clock		clock;
  DynamicLibrariesLoader	*loader;
  EventManager	*eventManager;

  ship = new Ship(sprites);
  srand(time(NULL));
  try
    {
  loader = new DynamicLibrariesLoader();
    }
  catch (std::runtime_error &e)
    {
      std::cerr << "Runtime error: " << e.what() << std::endl;
      return (0);
    }
  eventManager = new EventManager(&app, *loader);
  entityManager.add(new Starfield(sprites));
  entityManager.add(ship);
  entityManager.add(loader->getInstanceObject(sprites));
  app.setFramerateLimit(60);
  audioManager.playMusic();
  while (app.isOpen())
    {
      eventManager->checkEvent(entityManager, ship);
      ((Ship *)ship)->setKeyState(eventManager->getKeyState());
      eventManager->spawningEnemies(entityManager, sprites);
      app.clear();
      entityManager.updateEntities(app, clock);
      app.display();
    }
  return (0);
}

