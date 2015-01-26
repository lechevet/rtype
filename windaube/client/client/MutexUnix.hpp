#ifndef		MUTEXUNIX_HPP
# define	MUTEXUNIX_HPP

# include	<pthread.h>
# include	"IMutex.hh"

class		MutexUnix : public IMutex
{
private:

  pthread_mutex_t _mutex;

public:

  MutexUnix()
  {
    pthread_mutex_init(&_mutex, NULL);
  }

  ~MutexUnix() {}

  int		lock()
  {
    return (pthread_mutex_lock(&_mutex));
  }

  int		unlock()
  {
    return (pthread_mutex_unlock(&_mutex));
  }
};

#endif
