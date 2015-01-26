#ifndef		NOSUCHOBJECTEXCEPTION_HH
# define	NOSUCHOBJECTEXCEPTION_HH

# include	<sstream>

class		NoSuchObjectException : public std::exception
{
public:

  NoSuchObjectException(const char *Msg)
  { 
    std::ostringstream oss; 
    oss << "Error : " << Msg; 
    this->msg = oss.str(); 
  } 
  
  NoSuchObjectException()
  {
  }

  virtual ~NoSuchObjectException() throw() 
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
