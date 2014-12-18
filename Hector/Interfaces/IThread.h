#ifndef I_THREAD_
#define I_THREAD_H

class IThread
{
	public:

		virtual int createThread(void *(routine)(void *), void *args) = 0;
		virtual int stopThread() = 0;
		virtual int detachThread() = 0;
		virtual int joinThread() = 0;
		virtual int setArgs(void *args) = 0;
		virtual int setData(void *data) = 0;
		virtual ~IThread() {};

	protected:
		bool 	_isWorkerThread;
		bool 	_isUiThread;
		bool 	_isRunning;
		void *	_args;
		void *	_data;

	private:
};

#endif // I_THREAD_H

