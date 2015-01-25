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

    name = malloc(strlen(filename) + 2);
    memset(name, 0, strlen(filename) + 2);
    strcpy(name, filename);
    while (filename && filename[i] && filename[i] != '.')
      ++i;
    if (filename[i] == '.')
      {
	filename[i + 1] = 'd';
	filename[i + 2] = 'l';
	filename[i + 3] = 'l';
      }
    _handle = LoadLibrary(name);
  }

  char		*error()
  {
    return ("Can't find symbol.");
  }

  void		*sym(const char *symbol)
  {
    return (dlsym(GetProcAddress(_handle, symbol)));
  }

  int		close()
  {
    return (FreeLibrary(_handle));
  }
};
#endif
