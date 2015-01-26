#ifndef		SLEEP_HPP
# define	SLEEP_HPP

# ifdef	_WIN32

#  include <time.h>
#  include <sys/timeb.h>

class	MySleep
{
public:
	static int gettimeofday (struct timeval *tp, void *tz)
	{
		struct _timeb timebuffer;
		_ftime64_s(&timebuffer);
		tp->tv_sec = (long)(timebuffer.time);
		tp->tv_usec = (long)(timebuffer.millitm * 1000);
		return 0;
	}

	static void	usleep(size_t value)
	{
		Sleep(value / 1000);
	}

};
# else
#	include <iostream>

#  include	<time.h>
#  include	<sys/time.h>

class	MySleep
{
public:
  static 	int gettimeofday(struct timeval *tp, struct timezone *tz)
  {
    struct timeval te;

    ::gettimeofday(&te, NULL);
    tp->tv_sec = te.tv_sec;
    tp->tv_usec = te.tv_usec;
    return 0;
  }

  static void	usleep(size_t value)
  {
    ::usleep(value);
  }

};

# endif

#endif
