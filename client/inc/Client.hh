#ifndef		CLIENT_HH
# define	CLIENT_HH

# include	"Definitions.hh"
# include	"Socket.hh"
# include	"SpriteGiver.hh"
# include	"AudioManager.hh"

class		Client
{
private:
  ISocket*	_sock;
  RenderWindow	*_app;
  SpriteGiver	_spriteGiver;
  struct sockaddr_in	_sin;
  socklen_t		_len;
  int			_id;
  bool		_dead;

public:
  Client();
  Client(const std::string &);
  ~Client();

  void		makeConnection();
  void		sendData(EnumData cmd);
  t_proto	recvData();
  Sprite	getRightSprite(EntityType);
  int		rendering();
  EnumData	eventGest();
  void		gameOver(AudioManager &);
  bool		isDead() const;
};

#endif
