#ifndef		ENEMY_HH
# define	ENEMY_HH

# include	"AEntity.hh"

class		Enemy : public AEntity
{
public:
  Enemy(int id);
    ~Enemy();
  int		getLife() const;
  void		getDamage(int power, EntityType type);
  bool		move();
};

extern "C"
{
  Enemy*	Create(int);
  void	Destroy(Enemy *);
}

#endif