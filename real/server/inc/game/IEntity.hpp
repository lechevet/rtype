#ifndef		IENTITY_HPP
# define	IENTITY_HPP

# include	"Vector.hh"
# include	"ISocket.hh"

class		IEntity
{
public:
  virtual ~IEntity() {}
  virtual void		setTranslation(float) = 0;
  virtual void		setCoord(const Vector &) = 0;
  virtual void		setCoord(int, int) = 0;
  virtual void		setId(int) = 0;
  virtual void		setLife(int) = 0;
  virtual void		setDensity(int, int) = 0;
  virtual void		setDensity(const Vector &) = 0;
  virtual Vector       	getCoord() const = 0;
  virtual float		getTranslation() const = 0;
  virtual int		getId() const = 0;
  virtual int		getLife() const = 0;
  virtual EntityType	getType() const = 0;
  virtual Vector	getDensity() const = 0;
  virtual int		getPower() const = 0;
  virtual bool		isDamaged() const = 0;
  virtual bool		move() = 0;
  virtual bool		checkDeath() const = 0;
  virtual void		getDamage(int, EntityType) = 0;
};

#endif
