#ifndef		ITHREAD_HH
# define	ITHREAD_HH

class		IThread
{
public:
  virtual ~IThread() {}
  virtual int		create(void * (* start_routine) (void *), void * arg) = 0;
  virtual int		cancel() = 0;
  virtual int		join(void ** thread_return) = 0;
  virtual int		exit(void * retval) = 0;
};

#endif
