#ifndef		IDL_HH
# define	IDL_HH

class		IDl
{
public:
  virtual ~IDl() {}

  virtual void	open(const char *filename, int flag) = 0;
  virtual char	*error() = 0;
  virtual void	*sym(const char *symbol) = 0;
  virtual int	close() = 0;
};

#endif
