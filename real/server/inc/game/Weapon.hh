#ifndef		WEAPON_HH
# define	WEAPON_HH

# include	"game/AEntity.hh"

class		Weapon : public AEntity
{
private:
  int		_delay;

public:
  Weapon(IEntity*, int);
  ~Weapon();

  int		getDelay() const;

  void		setDelay(int);

  bool		move();
  void		getDamage(int, EntityType);

};
#endif
