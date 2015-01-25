#ifndef		THREAD_HH
# define	THREAD_HH

# include	"IThread.hh"

# ifdef _WIN32
#  include "ThreadWindows.hpp"
typedef	ThreadWindows	AbstractThread;
#  else
#  include "ThreadUnix.hpp"
typedef	ThreadUnix	AbstractThread;
# endif

#endif