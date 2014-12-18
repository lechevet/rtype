#ifndef I_MUTEX_H
#define I_MUTEX_H

class IMutex
{
	public:
	
		virtual ~IMutex() {};
		virtual void lockMutex() = 0;
		virtual void unlockMutex() = 0;
};


#endif // I_MUTEX_H

