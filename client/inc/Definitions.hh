#ifndef		DEFINITIONS_HH
# define	DEFINITIONS_HH


#define	WINHEIGHT	1080
#define	WINWIDTH	1920

# include	<SFML/Graphics.hpp>

using namespace sf;

enum EnumSound
  {
    MUSIC = 0,
    BASICWEAPON
  };

enum	EntityType
  {
    SHIP = 0,
    ENEMY,
    WEAPON,
    STARFIELD
  };

typedef struct		s_sprites
{
  Texture		texture;
  Sprite		sprite;
}			t_sprites;

#endif
