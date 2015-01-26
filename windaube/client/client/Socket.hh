#ifndef		SOCKET_HH
# define	SOCKET_HH

# include	"ISocket.hh"

# ifdef	_WIN32
#  include "socketWindows.hpp"
typedef socketWindows AbstractSocket;
# else
#  include "socketUnix.hpp"
typedef socketUnix AbstractSocket;
# endif


#endif
