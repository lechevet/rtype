#ifndef		IENTITY_HPP
# define	IENTITY_HPP


# include	<SFML/Graphics.hpp>
# include	"Definitions.hh"

using namespace sf;

class		IEntity
{
public:
  virtual ~IEntity() {}
  virtual Sprite&	getSprite() = 0;
  virtual void		setSprite(const std::string &filepath, const Vector2f &, const Vector2f &) = 0;
  virtual void		move(const Vector2f &vector) = 0;
  virtual void		changeScale(const Vector2f &vector) = 0;
  virtual void		changePosition(const Vector2f &vector) = 0;
  virtual Vector2f	getPosition() = 0;
  virtual void		getDamage(int damage, EnumSound type) = 0;
  virtual EntityType	getType() const = 0;
};

#endif
