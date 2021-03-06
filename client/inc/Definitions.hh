#ifndef			DEFINITIONS_HH
# define		DEFINITIONS_HH

# define		RES_X	1280
# define		RES_Y	720
# define		PORT	4242

#include		<SFML/Graphics.hpp>

using namespace		sf;

enum			EnumSound
  {
    MUSIC = 0,
    GAMEOVERAUDIO,
    WEAPONSOUND
  };

enum			EntityType
  {
    SHIP = 0,
    ENEMY,
    WEAPON,
    STARFIELD,
    STARFIELD2,
    GAMEOVER
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

typedef struct		s_proto
{
  EntityType		type;
  int			x;
  int			y;
  Command		cmd;
  size_t		entityCount;
  bool			damaged;
  int			deadId;
}			t_proto;

typedef struct		s_recv
{
  int			id;
  EnumData		data;
}			t_recv;

typedef struct		s_hello
{
  Command		cmd;
  int			id;
}			t_hello;

typedef struct		s_sprites
{
  Sprite		sprite;
  Texture		texture;
}			t_sprites;
#endif
