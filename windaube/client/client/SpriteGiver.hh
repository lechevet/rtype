#ifndef		SPRITEGIVER_HH
# define	SPRITEGIVER_HH

#include	"Definitions.hh"

class		SpriteGiver
{
private:
  std::map<EntityType, t_sprites>	sprites;

public:
  SpriteGiver();
  ~SpriteGiver();
  Sprite	getSprite(const EntityType type);
  void		loadSprite(const EntityType type, const std::string &filename, const std::string &name, const IntRect &rect);
  void		loadSprite(const EntityType type, const std::string &filename, const std::string &name);
};

#endif
