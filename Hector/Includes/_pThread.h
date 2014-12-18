#ifndef _P_THREAD_H
#define _P_THREAD_H

#include <pthread.h>
#include "IThread.h"

class _pThread : public IThread
{

	public:
	
		_pThread(bool isWorkerThread = true
				,bool isUiThread = false);

		virtual int createThread(void *(routine)(void *) = NULL, void *args = NULL);
		virtual int stopThread();
		virtual int detachThread();
		virtual int joinThread();
		virtual int setArgs(void *args);
		virtual int setData(void *data);
		const pthread_t & getId() const;
		const bool 		& isWorkerThread() const;
		const bool 		& isUiThread() const;

		virtual ~_pThread();

	protected:

		pthread_t 	_id;

};

#endif // _P_THREAD_H

