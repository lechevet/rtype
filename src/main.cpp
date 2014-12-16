#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Ship.hh"
#include	"EventManager.hh"
#include	"EntityManager.hh"
#include	"Definitions.hh"
#include	"AudioManager.hh"
#include	"Enemy.hh"
#include	"Starfield.hh"

int	main()
{

  RenderWindow app(VideoMode(WINWIDTH, WINHEIGHT, 32), "R-Type", Style::Close | Style::Titlebar);
  SpriteGiver	sprites;
  IEntity	*ship;
  EntityManager	entityManager(sprites);
  EventManager	eventManager(&app);
  AudioManager	audioManager;
  Clock		clock;

  ship = new Ship(sprites);
  srand(time(NULL));
  entityManager.add(new Starfield(sprites));
  entityManager.add(ship);
  entityManager.add(new Enemy(sprites));
  app.setFramerateLimit(60);
  audioManager.playMusic();
  while (app.isOpen())
    {
      eventManager.checkEvent(entityManager, ship);
      ((Ship *)ship)->setKeyState(eventManager.getKeyState());
      eventManager.spawningEnemies(entityManager, sprites);
      app.clear();
      entityManager.updateEntities(app, clock);
      app.display();
    }
  return (0);
}

