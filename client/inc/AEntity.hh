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
  int		life;
  int		id;
  float		framerate;

public:
  virtual ~AEntity() {}
  void		setFramerate(const float);
  Sprite&	getSprite();
  void		setSprite(const std::string &filepath, const Vector2f &, const Vector2f &);
  void		translation(const Vector2f &vector);
  void		changeScale(const Vector2f &vector);
  void		changePosition(const Vector2f &vector);
  Vector2f	getPosition();
  virtual void	getDamage(int damage, EnumSound type) = 0;
  EntityType	getType() const;
  virtual bool	move() = 0;
  bool		checkDeath() const;
  int		getId() const;
  void		setId(int);
  void		draw(RenderWindow &);
};

#endif
