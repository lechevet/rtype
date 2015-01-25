#ifndef		AENTITY_HH
# define	AENTITY_HH

# include	"IEntity.hpp"

class		AEntity : public IEntity
{
protected:
  Vector	_coord;
  float		_translation;
  Vector	_density;
  int		_id;
  int		_life;
  EntityType	_type;
  int		_power;
  bool		_damaged;

public:
  virtual ~AEntity() {}
  virtual void		setTranslation(float);
  virtual void		setCoord(const Vector &);
  virtual void		setCoord(int, int);
  virtual void		setId(int);
  virtual void		setLife(int);
  virtual void		setDensity(int, int);
  virtual void		setDensity(const Vector &);

  virtual Vector	getCoord() const;
  virtual float		getTranslation() const;
  virtual int		getId() const;
  virtual int		getLife() const;
  virtual EntityType	getType() const;
  virtual Vector	getDensity() const;
  virtual int		getPower() const;
  virtual bool		move() = 0;
  virtual bool		checkDeath() const;

  virtual bool		isDamaged() const;
  virtual void		getDamage(int, EntityType) = 0;
};

#endif
