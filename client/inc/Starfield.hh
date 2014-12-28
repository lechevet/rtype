#ifndef		STARFIELD_HH
# define	STARFIELD_HH

# include	"AEntity.hh"

class		Starfield : public AEntity
{
private:
  Sprite	sprite2;
  Texture	texture2;
  Sprite	*mainSprite;
  Sprite	*secondSprite;

public:
  Starfield(SpriteGiver &sprites);
  ~Starfield();
  void		getDamage(int damage, EnumSound type);
  virtual bool	move();
  bool		checkDeath() const;
  void		translation(const Vector2f &);
  void		changeScale(const Vector2f &);
  void		changePosition(const Vector2f &);
  Vector2f	getPosition();
  void		draw(RenderWindow &);
};

#endif
