#ifndef			DEFINITIONS_HH
# define		DEFINITIONS_HH

# define		RES_X	1280
# define		RES_Y	720
# define		PORT	4242

# include		"Sleep.hpp"

enum			EntityType
  {
    SHIP = 0,
    ENEMY,
    WEAPON,
    STARFIELD,
    STARFIELD2
  };

enum			Protocole
  {
    TCP = 0,
    UDP
  };

enum			Command
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    SPACE,
    RELEASE,
    PING,
    DIE,
    HELLO
  };

enum			EnumData
  {
    NEW = 0,
    UPDATA,
    LEFTDATA,
    RIGHTDATA,
    DOWNDATA,
    SPACEDATA,
    RELEASEUPDATA,
    RELEASEDOWNDATA,
    RELEASELEFTDATA,
    RELEASERIGHTDATA,
    RELEASESPACEDATA,
    OK,
    BYE,
    NONE
  };
#endif
