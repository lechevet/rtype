#ifndef		MUTEX_HH
# define	MUTEX_HH

# ifdef _WIN32
#  include "MutexWindows.hpp"
typedef	MutexWindows	AbstractMutex;
#  else
#  include "MutexUnix.hpp"
typedef	MutexUnix	AbstractMutex;
# endif

#endif
