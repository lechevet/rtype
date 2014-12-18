#ifndef COM_WRAPPER_H
#define COM_WRAPPER_H

#include "_SocketFactory.cpp"

class ComWrapper
{
	public:
	
		ComWrapper(unsigned int flags);
		~ComWrapper();

		int initServer();
		int addClient();

	protected:


};

#endif // COM_WRAPPER_H
