#ifndef		AWEAPON_HH
# define	AWEAPON_HH

# include	"AEntity.hh"
# include	"Definitions.hh"

class		AWeapon : public AEntity
{
protected:
  EnumSound	weaponType;
  EntityType	type;
  int		power;
  float		frequence;
  
public:
  void		doDamage(IEntity *);
  EnumSound	getWeaponType() const;
  int		getPower() const;
  float		getFrequence() const;
  void		getDamage(int, EnumSound);
};

#endif
