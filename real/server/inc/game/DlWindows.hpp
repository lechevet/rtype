#ifndef		DLWINDOWS_HPP
# define	DLWINDOWS_HPP

# include	<windows.h>
# include	<string.h>
# include	"IDl.hh"

class		DlWindows : public IDl
{
private:
  HMODULE	_handle;

public:
  void		open(const char *filename, int flag)
  {
    char	*name;
    int		i = 0;

    name = (char *)malloc(strlen(filename) + 2);
    memset(name, 0, strlen(filename) + 2);
    strcpy(name, filename);
    while (name && name[i] && name[i] != '.')
      ++i;
    if (filename[i] == '.')
      {
		name[i + 1] = 'd';
		name[i + 2] = 'l';
		name[i + 3] = 'l';
      }
    _handle = LoadLibrary((LPCWSTR)name);
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
