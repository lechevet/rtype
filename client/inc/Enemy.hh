#ifndef		ENEMY_HH
# define	ENEMY_HH

# include	"AEntity.hh"

class		Enemy : public AEntity
{
public:
    Enemy(SpriteGiver &);
    ~Enemy();
  int		getLife() const;
  void		getDamage(int power, EnumSound type);
  bool		move();
};

extern "C"
{
    Enemy*	Create(SpriteGiver &);
    void	Destroy(Enemy *);
}

#endif
