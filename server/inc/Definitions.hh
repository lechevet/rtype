#ifndef		DEFINITIONS_HH
# define	DEFINITIONS_HH

# define	RES_X	1080
# define	RES_Y	720
# define	PORT	4242

enum		EntityType
  {
    SHIP = 0,
    ENEMY,
    WEAPON,
    STARFIELD,
  };

enum		Protocole
  {
    TCP = 0,
    UDP
  };

enum		Command
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    SPACE,
    PONG
  };

#endif
