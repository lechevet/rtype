#include "_pThread.h"

/*
=============================================================================
	CONSTRUCTEUR DE LA CLASSE _pThread
=============================================================================
*/
_pThread::_pThread(bool isWorkerThread, bool isUiThread)
{
	this->_isWorkerThread	= isWorkerThread;
	this->_isUiThread		= isUiThread;
	this->_isRunning 		= false;
	this->_args				= NULL;
	this->_data				= NULL;
}
/*
=============================================================================
	DESTRUCTEUR DE LA CLASSE _pThread
=============================================================================
*/
_pThread::~_pThread()
{
	this->stopThread();
}
/*
=============================================================================
	CREATION DU THREAD 
	routine : Fonction a executer
	args    : Parametres a envoyer a la fonction
=============================================================================
*/ 
int _pThread::createThread(void *(routine)(void *), void *args)
{
	if (this->_isRunning == true)
		return (-1);
	int return_value;
	if (args)
		this->_args = args;
	return_value = pthread_create(&(this->_id), NULL, routine, this->_args);
	if (return_value == 0)
		this->_isRunning = true;
	return (return_value);
}
/*
=============================================================================
	ARRET DU THREAD
=============================================================================
*/
int _pThread::stopThread()
{
	if (this->_isRunning == false)
		return (-1);
	int return_value;
	return_value = pthread_cancel(this->_id);
	if (return_value == 0)
		this->_isRunning = false;
	return (return_value);
}
/*
=============================================================================
	ATTENDRE LE THREAD
	FONCTION NON IMPLEMENTEE
=============================================================================
*/
int _pThread::detachThread()
{
	int return_value;

	if (this->_isRunning == false)
		return (-1);
	return_value = pthread_detach(this->_id);
	return (return_value);
}
/*
=============================================================================
	REJOINDRE LE THREAD
	BLOQUE L'EXECUTION TANT QUE LE THREAD VISE N'EST PAS TERMINE
=============================================================================
*/
int _pThread::joinThread()
{
	if (this->_isRunning == false)
		return (-1);
	int return_value;
	return_value = pthread_join(this->_id, NULL);
	if (return_value == 0)
		this->_isRunning = false;
	return (return_value);
}
/*
=============================================================================
	SETTER DES ARGUMENTS A ENVOYER A LA ROUTINE
=============================================================================
*/
int _pThread::setArgs(void *args)
{
	if (args)
	{
		this->_args = args;
		return (0);
	}
	return (-1);
}
/*
=============================================================================
	SETTER DU POINTEUR DATA
=============================================================================
*/
int _pThread::setData(void *data)
{
	if (data)
	{
		this->_data = data;
		return (0);
	}
	return (-1);
}
/*
=============================================================================
	GETTER DE L'ID DU THREAD
=============================================================================
*/
const pthread_t & _pThread::getId() const
{
	return (this->_id);
}
/*
=============================================================================
	GETTER WORKER THREAD
=============================================================================
*/
const bool & _pThread::isWorkerThread() const
{
	return (this->_isWorkerThread);
}
/*
=============================================================================
	GETTER UI THREAD
=============================================================================
*/
const bool & _pThread::isUiThread() const
{
	return (this->_isUiThread);
}