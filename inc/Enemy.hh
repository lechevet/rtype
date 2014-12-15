#ifndef		ENEMY_HH
# define	ENEMY_HH

# include	"AEntity.hh"

class		Enemy : public AEntity
{
private:
  int		life;

public:
  Enemy();
  ~Enemy();
  int		getLife() const;
  void		getDamage(int power, EnumSound type);
};

#endif
