#ifndef		SOCKET_HH
# define	SOCKET_HH

# ifdef	_WIN32
#  include "socketWindows.hpp"
# else
#  include "socketUnix.hpp"
# endif


#endif
