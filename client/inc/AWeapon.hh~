#ifndef		AWEAPON_HH
# define	AWEAPON_HH

# include	"AEntity.hh"
# include	"Definitions.hh"
# include	"EntityManager.hh"

class		AWeapon : public AEntity
{
protected:
  EnumSound	weaponType;
  int		power;
  int		delay;
  
public:
  void		doDamage(IEntity *);
  EnumSound	getWeaponType() const;
  int		getPower() const;
  int		getDelay() const;
  void		getDamage(int, EnumSound);
  bool		move();
  bool		checkTarget(EntityManager &entityManager);
};

#endif
