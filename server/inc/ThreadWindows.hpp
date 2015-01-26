#ifndef		THREADWINDOWS_HPP
# define	THREADWINDOWS_HPP

class		ThreadWindows : public IThread
{
private:
  HANDLE	_thread;
  DWORD		_id;

public:
  ThreadWindows() {}
  ~ThreadWindows() {}

  int		create(void * (* start_routine) (void *), void * arg)
  {
    _thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)start_routine, (LPVOID) arg, 0, &_id);
	return (0);
  }

  int		cancel()
  {
    int		ret;

    ret = TerminateThread(_thread, (DWORD) NULL);
    return (ret);
  }

  int		join(void ** thread_return)
  {
    WaitForSingleObject(_thread, INFINITE);
    thread_return = NULL;
	return (0);
  }

  int		exit(void * retval)
  {
    ExitThread(0);
    return (0);
  }
};

#endif
