#ifndef		WEAPON_HH
# define	WEAPON_HH

# include	"AEntity.hh"

class		Weapon : public AEntity
{
private:
  int		_power;
  int		_delay;

public:
  Weapon(IEntity *entity, int id);
  ~Weapon();

  void		doDamage(IEntity *);
  int		getPower() const;
  int		getDelay() const;
  void		getDamage(int, EntityType);
  bool		move();
  //  bool		checkTarget(EntityManager &);
};

#endif
