#ifndef		WEAPON_HH
# define	WEAPON_HH

class		Weapon : public AEntity
{
private:
  int		_delay;

public:
  Weapon();
  ~Weapon();

  bool		move();

  void		getDamage(int, EntityType);
};

#endif
