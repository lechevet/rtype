#ifndef		AENTITY_HH
# define	AENTITY_HH


# include	<SFML/Graphics.hpp>
# include	"IEntity.hpp"

using namespace sf;

class		AEntity : public IEntity
{
protected:
  EntityType	type;
  Sprite	sprite;
  Texture	texture;

public:
  virtual ~AEntity() {}
  Sprite&	getSprite();
  void		setSprite(const std::string &filepath, const Vector2f &, const Vector2f &);
  void		move(const Vector2f &vector);
  void		changeScale(const Vector2f &vector);
  void		changePosition(const Vector2f &vector);
  Vector2f	getPosition();
  void		getDamage(int damage, EnumSound type) = 0;
  EntityType	getType() const;
};

#endif
