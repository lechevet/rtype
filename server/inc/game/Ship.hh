#ifndef         SHIP_HH
# define        SHIP_HH

# include       <map>
# include       "AEntity.hh"
# include       "Definitions.hh"

class           Ship : public AEntity
{
private:
  std::map<Command, bool>       _key;
  TIMEVAL		_start;
  TIMEVAL		_time;
  MySleep		_sleep;

public:
  Ship(int id);
  ~Ship();

  void          setDirection(EnumData);
  bool          move();
  bool          isShooting();
  void          getDamage(int, EntityType);
};

#endif
