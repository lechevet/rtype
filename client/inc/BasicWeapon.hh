#ifndef		BASICWEAPON_HH
# define	BASICWEAPON_HH

# include	"IEntity.hpp"
# include	"AWeapon.hh"

class		BasicWeapon : public AWeapon
{
public:
  BasicWeapon(IEntity *entity, SpriteGiver &);
  ~BasicWeapon();
};

#endif
