#ifndef		THREADUNIX_HPP
# define	THREADUNIX_HPP

# include	<pthread.h>
# include	"IThread.hh"

class		ThreadUnix : public IThread
{
private:
  pthread_t	_thread;

public:
  ThreadUnix() {}
  ~ThreadUnix()
  {
  }

  int		create(void * (* start_routine) (void *), void * arg)
  {
    int		ret;

    ret = pthread_create(&_thread, NULL, start_routine, arg);
    return (ret);
  }
  
  int		cancel()
  {
    int	ret;

    ret = pthread_cancel(_thread);
    return (ret);
  }

  int		join(void ** thread_return)
  {
    pthread_join(_thread, thread_return);
    return (0);
  }

  int		exit(void * retval)
  {
    pthread_exit(retval);
    return (0);
  }
};

#endif
