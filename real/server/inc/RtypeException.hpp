#ifndef		RTYPEEXCEPTION_HH
# define	RTYPEEXCEPTION_HH

# include	<sstream>
# include	<errno.h>
class		RtypeException : public std::exception
{
public:

  RtypeException(const char *Msg)
  { 
    std::ostringstream oss; 
    oss << "Error : " << Msg; 
    this->msg = oss.str(); 
  } 
  
  virtual ~RtypeException() throw() 
  { 
  
  } 
  
  virtual const char * what() const throw() 
  { 
    return this->msg.c_str(); 
  } 
  
private: 
  std::string msg;
};

#endif
