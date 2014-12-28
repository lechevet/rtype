//
// Exception.cpp for vm in /home/wadin_h//tek2/c++/abstract_vm
//
// Made by hubert wadin
// Login   <wadin_h@epitech.net>
//
// Started on  Thu Feb 21 19:43:32 2013 hubert wadin
// Last update Sun Nov 17 16:59:47 2013 
//

#include		"SocketException.hh"
#include <iostream>
SocketException::SocketException(std::string const & name) throw()
  : std::runtime_error(name), _name(name)
{
  std::cout << "EXCEPTION DE LA MORT" << std::endl;
}

SocketException::~SocketException() throw()
{
};

const char		*SocketException::what() const throw()
{
  return (_name.c_str());
}
