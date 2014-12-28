#ifndef		STARFIELD_HH
# define	STARFIELD_HH

# include	"AEntity.hh"

class		Starfield : public AEntity
{
public:
  Starfield()
  ~Starfield();
  void		getDamage(int, EntityType);
  bool		move();
  bool		checkDeath() const;
};

#endif
