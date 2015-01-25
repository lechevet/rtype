#ifndef		MUTEXWINDOWS_HPP
# define	MUTEXWINDOWS_HPP

# include	"IMutex.hh"

class		MutexWindows : public IMutex
{
private:
  HANDLE	_mutex;

public:
  MutexWindows()
  {
    _mutex = CreateMutex(NULL, false, (LPCWSTR)"Lock");
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
};

#endif
