#ifndef		DL_HH
# define	DL_HH

# ifdef	_WIN32
#  include "DlWindows.hpp"
typedef DlWindows AbstractDl;
# else
#  include "DlUnix.hpp"
typedef DlUnix AbstractDl;
# endif

#endif
