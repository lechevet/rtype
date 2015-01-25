#ifndef		DLUNIX_HPP
# define	DLUNIX_HPP

# include	<dlfcn.h>
# include	"IDl.hh"

class		DlUnix : public IDl
{
private:
  void		*_handle;

public:
  DlUnix() {}
  ~DlUnix()
  {
    dlclose(_handle);
  }

  void		open(const char *filename, int flag)
  {
    _handle = dlopen(filename, flag);
  }

  char		*error()
  {
    return (dlerror());
  }

  void		*sym(const char *symbol)
  {
    return (dlsym(_handle, symbol));
  }

  int		close()
  {
    return (dlclose(_handle));
  }

};

#endif
