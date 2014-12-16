#ifndef		SPRITEGIVER_HH
# define	SPRITEGIVER_HH

#include	"Definitions.hh"

class		SpriteGiver
{
private:
  std::map<std::string, t_sprites>	sprites;

public:
  SpriteGiver();
  ~SpriteGiver();
  Sprite	getSprite(const std::string &name);
  void		loadSprite(const std::string &filename, const std::string &name, const IntRect &rect);
  void		loadSprite(const std::string &filename, const std::string &name);
};

#endif
