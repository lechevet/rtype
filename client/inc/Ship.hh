#ifndef		SHIP_HH
# define	SHIP_HH

# include	"AEntity.hh"
# include	"AWeapon.hh"
# include	<SFML/Graphics.hpp>

class		Ship : public AEntity
{
private:
  AWeapon	*weapon;
  std::map<Keyboard::Key, bool>	keyState;

public:
  Ship(SpriteGiver &);
  ~Ship();

  void		getDamage(const int damage);
  AWeapon*	getWeapon() const;
  void		setWeapon(AWeapon *);
  std::map<Keyboard::Key, bool>&	getKeyState();
  void		setKeyState(std::map<Keyboard::Key, bool>&);
  bool		move();
  bool		isShooting();
};

#endif
