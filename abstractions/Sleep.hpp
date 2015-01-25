#ifndef		SLEEP_HPP
# define	SLEEP_HPP

#ifdef	_WIN32

#include <time.h>
#include <sys/timeb.h>

int gettimeofday (struct timeval *tp, void *tz)
{
  struct _timeb timebuffer;
  _ftime (&timebuffer);
  tp->tv_sec = timebuffer.time;
  tp->tv_usec = timebuffer.millitm * 1000;
  return 0;
}

void	usleep(size_t value)
{
  Sleep(value / 1000);
}

#endif
