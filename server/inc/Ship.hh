#ifndef		SHIP_HH
# define	SHIP_HH

# include	<map>
# include	"AEntity.hh"
# include	"Definitions.hh"

class		Ship : public AEntity
{
private:
  bool		_activity;
  std::map<Command, bool>	_key;

public:
  Ship(int id);
  ~Ship();
  void		setActivity(bool);
  void		setDirection(Command, bool);
  bool		isActive() const;
  bool		move();
  bool		isShooting();
  void		getDamage(int, EntityType);
};

#endif
