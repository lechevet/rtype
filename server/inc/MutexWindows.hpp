#ifndef		MUTEXWINDOWS_HPP
# define	MUTEXWINDOWS_HPP

class		MutexWindows : public IMutex
{
private:
  HANDLE	_mutex;

public:
  MutexWindows()
  {
    _mutex = MutexCreate(NULL, false, "Lock");
  }

  ~MutexWindows() {}

  int		lock()
  {
    WaitForSingleObject(_mutex, INFINITE);
    return (1);
  }

  int		unlock()
  {
    return (ReleaseMutex(_mutex));
  }
}

#endif
