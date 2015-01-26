#ifndef		DLWINDOWS_HPP
# define	DLWINDOWS_HPP

# include	<windows.h>
# include	<string.h>
# include	"IDl.hh"

class		DlWindows : public IDl
{
private:
  HINSTANCE	_handle;

public:
  void		open(const char *filename, int flag)
  {
	  _handle = LoadLibrary((LPCWSTR)filename);
  }

  char		*error()
  {
	return ("Can't find symbol.");
  }

  void		*sym(const char *symbol)
  {
	return (GetProcAddress(_handle, symbol));
  }

  int		close()
  {
	return (FreeLibrary(_handle));
  }
};
#endif
