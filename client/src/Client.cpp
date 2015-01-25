#include	<iostream>
#include	"Client.hh"

Client::Client()
{
  struct hostent	*hostinfo;

  _app = new RenderWindow(VideoMode(RES_X, RES_Y, 32), "R-Type", Style::Close);
  _sock = new AbstractSocket(UDP);
  hostinfo = gethostbyname("localhost");
  _sin.sin_family = AF_INET;
  _sin.sin_port = htons(PORT);
  _sin.sin_addr = *(IN_ADDR *)hostinfo->h_addr;
  _len = sizeof(_sin);
  _app->setKeyRepeatEnabled(false);
  _dead = false;
}

Client::Client(const std::string &hostname)
{
  struct hostent	*hostinfo;

  _app = new RenderWindow(VideoMode(RES_X, RES_Y, 32), "R-Type", Style::Close);
  hostinfo = gethostbyname(hostname.c_str());
  _sin.sin_family = AF_INET;
  _sin.sin_port = htons(PORT);
  _sin.sin_addr = *(IN_ADDR *)hostinfo->h_addr;
  _len = sizeof(_sin);
  _app->setKeyRepeatEnabled(false);
  _app->setFramerateLimit(72);
  _dead = false;
}

Client::~Client()
{
}

void		Client::makeConnection()
{
  t_recv	rec;
  t_hello	hello;
  
  rec.id = 0;
  rec.data = NEW;
  _sock->sendDataTo(&rec, sizeof(t_recv), 0, (SOCKADDR *)&_sin, _len);
  _sock->recvDataFrom(&hello, sizeof(t_hello), 0, NULL, NULL);
  _id = hello.id;
  rec.id = _id;
  rec.data = OK;
  std::cout << _id << std::endl;
  _sock->sendDataTo(&rec, sizeof(t_recv), 0, (SOCKADDR *)&_sin, _len);
}

void		Client::sendData(EnumData cmd)
{
  t_recv	rec;

  rec.id = _id;
  rec.data = cmd;
  if (_dead == false)
    _sock->sendDataTo(&rec, sizeof(t_recv), 0, (SOCKADDR *)&_sin, _len);
  if (cmd == BYE)
    {
      _app->close();
      exit(0);
    }
}

t_proto		Client::recvData()
{
  t_proto	proto;

  _sock->recvDataFrom(&proto, sizeof(t_proto), 0, (SOCKADDR *)&_sin, &_len);
  return (proto);
}

Sprite		Client::getRightSprite(EntityType type)
{
  return (_spriteGiver.getSprite(type));
}
void		Client::gameOver(AudioManager &audioManager)
{
  Sprite	sprite;
  static bool	_continue = true;

  if (_continue == true)
    {
      audioManager.stopMusic(MUSIC);
      audioManager.playMusic(GAMEOVERAUDIO);
      _continue = false;
    }
  _dead = true;
  _app->clear();
  sprite = getRightSprite(GAMEOVER);
  sprite.setPosition(Vector2f(0, 0));
  _app->draw(sprite);
  _app->display();
}

int		Client::rendering()
{
  t_proto	proto;
  size_t	entityCount;
  size_t	i;
  Sprite	sprite;

  _sock->recvDataFrom(&proto, sizeof(t_proto), 0, (SOCKADDR *)&_sin, &_len);
  if (proto.deadId == _id)
    return (-1);
  entityCount = proto.entityCount;
  i = 0;
  _app->clear();
  sprite = getRightSprite(proto.type);
  sprite.setPosition(Vector2f(proto.x, proto.y));
  if (proto.damaged == true)
    sprite.setColor(Color(255, 0, 0));
  _app->draw(sprite);
  while (i < entityCount)
    {
      _sock->recvDataFrom(&proto, sizeof(t_proto), 0, (SOCKADDR *)&_sin, &_len);
      if (proto.deadId == _id)
	return (-1);
      sprite = getRightSprite(proto.type);
      sprite.setPosition(Vector2f(proto.x, proto.y));
      if (proto.damaged == true)
      	sprite.setColor(Color(255, 0, 0));
      _app->draw(sprite);
      ++i;
    }
  _app->display();
  return (0);
}

EnumData	Client::eventGest()
{
  Event		event;

  while (_app->pollEvent(event))
    {
      switch (event.type)
	{
	case Event::Closed :
	  _app->close();
	  break;
	case Event::KeyPressed:
	  switch (event.key.code)
	    {
	    case Keyboard::Up :
	      return (UPDATA);
	      break;
	    case Keyboard::Down :
	      return (DOWNDATA);
	      break;
	    case Keyboard::Left :
	      return (LEFTDATA);
	      break;
	    case Keyboard::Right :
	      return (RIGHTDATA);
	      break;
	    case Keyboard::Space :
	      return (SPACEDATA);
	      break;
	    case Keyboard::Escape :
	      return (BYE);
	      break;
	    default:
	      break;
	    }
	  break;
	case Event::KeyReleased:
	  switch (event.key.code)
	    {
	    case Keyboard::Up :
	      return (RELEASEUPDATA);
	      break;
	    case Keyboard::Down :
	      return (RELEASEDOWNDATA);
	      break;
	    case Keyboard::Left :
	      return (RELEASELEFTDATA);
	      break;
	    case Keyboard::Right :
	      return (RELEASERIGHTDATA);
	      break;
	    case Keyboard::Space :
	      return (RELEASESPACEDATA);
	      break;
	    default:
	      break;
	    }
	default:
	  break;
	}
    }
  return (NONE);
}

bool		Client::isDead() const
{
  return (_dead);
}
