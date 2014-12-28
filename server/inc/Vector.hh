#ifndef		VECTOR_HH
# define	VECTOR_HH

class		Vector
{
private:
  int		_x;
  int		_y;

public:
  Vector();
  Vector(int, int);
  ~Vector();
  int		getX() const;
  int		getY() const;

  void		setX(int);
  void		setY(int);
};

#endif
