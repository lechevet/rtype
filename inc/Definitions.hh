#ifndef		DEFINITIONS_HH
# define	DEFINITIONS_HH


#define	WINHEIGHT	600
#define	WINWIDTH	800

# include	<SFML/Graphics.hpp>

using namespace sf;

enum EnumSound
  {
    MUSIC = 0,
    ENEMYWEAPON,
    BASICWEAPON,
    ROCKET,
    EXPLOSION
  };

enum	EntityType
  {
    SHIP = 0,
    ENEMY,
    WEAPON,
    STARFIELD,
    SPECTRE
  };

typedef struct		s_sprites
{
  Texture		texture;
  Sprite		sprite;
}			t_sprites;

#endif
