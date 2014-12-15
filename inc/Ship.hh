#ifndef		SHIP_HH
# define	SHIP_HH

# include	"AEntity.hh"
# include	"AWeapon.hh"

class		Ship : public AEntity
{
private:
  int		life;
  AWeapon	weapon;

public:
  Ship();
  ~Ship();

  void		getDamage(const int damage, const EnumSound type);
  AWeapon	getWeapon() const;
  void		setWeapon(const AWeapon &);
};

#endif
