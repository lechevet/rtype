#ifndef		IMUTEX_HH
# define	IMUTEX_HH

class		IMutex
{
public:
  virtual ~IMutex() {}
  virtual int		lock() = 0;
  virtual int		unlock() = 0;
};

#endif
