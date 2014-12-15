#include	<SFML/Graphics.hpp>
#include	<SFML/Audio.hpp>
#include	"Ship.hh"
#include	"EventManager.hh"
#include	"EntityManager.hh"
#include	"Definitions.hh"
#include	"AudioManager.hh"
#include	"Enemy.hh"
#include	<iostream>

int	main()
{

  RenderWindow app(VideoMode(WINWIDTH, WINHEIGHT, 32), "R-Type", Style::Close | Style::Titlebar);
  IEntity	*ship = new Ship();
  EntityManager	entityManager;
  EventManager	eventManager(&app);
  AudioManager	audioManager;
  Texture	texture;
  Sprite	sprite;

  srand(time(NULL));
  texture.loadFromFile("sprites/space.jpg");
  sprite.setTexture(texture);
  sprite.setPosition(Vector2f(0, 0));
  entityManager.add(ship);
  entityManager.add(new Enemy());
  app.setFramerateLimit(60);
  //  audioManager.playMusic();
  while (app.isOpen())
    {
      eventManager.checkEvent();
      eventManager.shipReaction((Ship *)ship, Vector2f(WINWIDTH, WINHEIGHT));
      entityManager.enemyScrolling();
      eventManager.spawningEnemies(entityManager);
      app.clear();
      app.draw(sprite);
      entityManager.draw_all(app);
      app.display();
    }
  return (0);
}
