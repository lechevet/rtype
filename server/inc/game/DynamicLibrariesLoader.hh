#ifndef		DYNAMICLIBRARIESLOADER_HH
# define	DYNAMICLIBRARIESLOADER_HH

# include	<string>
# include	<map>
# include	"Enemy.hh"
# include	"Dl.hh"

class		DynamicLibrariesLoader
{
private:
  IDl		*handler;
  void		*create;
  void		*destroy;

public:
  DynamicLibrariesLoader();
  ~DynamicLibrariesLoader();
  Enemy		*getInstanceObject(int);
  void		destroyInstanceObject(Enemy *);
};

#endif
