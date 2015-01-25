#ifndef		STARFIELD_HH
# define	STARFIELD_HH

# include	"AEntity.hh"

class		Starfield : public AEntity
{
private:
  Vector	_coord2;

public:
  Starfield();
  ~Starfield();
  void		getDamage(int, EntityType);
  bool		move();
  bool		checkDeath() const;
  Vector	getCoord2() const;
  void		setCoord2(const Vector &);
  void		setCoord2(int, int);
};

#endif
