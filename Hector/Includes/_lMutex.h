#ifndef _L_MUTEX_H
#define _L_MUTEX_H

#include <pthread.h>
#include <time.h>
#include "IMutex.h"

class _lMutex
{
	public:
		
		_lMutex();
		virtual int lockMutex();
		virtual int unlockMutex();
		virtual ~_lMutex();

	protected:

		pthread_mutex_t _mutex;

};

#endif // _L_MUTEX_H
