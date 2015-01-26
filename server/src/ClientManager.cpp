#include	"ClientManager.hh"
#include	"NoSuchObjectException.hpp"

#include <iostream>

ClientManager::ClientManager()
{
}

ClientManager::ClientManager(const ClientManager &other)
{
  std::list<Client *>::const_iterator it;

  it = other._clients.begin();
  while (it != other._clients.end())
    {
      _clients.push_back(*it);
      ++it;
    }
}

ClientManager::~ClientManager()
{
}

ClientManager&	ClientManager::operator=(const ClientManager &other)
{
  std::list<Client *>::const_iterator it;

  it = other._clients.begin();
  while (it != other._clients.end())
    {
      _clients.push_back(*it);
      ++it;
    }
  return (*this);
}

void		ClientManager::add(Client *client)
{
  _clients.push_front(client);
}

void		ClientManager::remove(Client *client)
{
  std::list<Client *>::iterator it;

  it = _clients.begin();
  while (it != _clients.end() && *it != client)
    ++it;
  if (it != _clients.end())
    _clients.erase(it);
}

Client*		ClientManager::get(int nb) const
{
  std::list<Client *>::const_iterator it;
  int		i = 0;

  it = _clients.begin();
  while (it != _clients.end() && i < nb)
    {
      ++it;
      ++i;
    }
  if (it == _clients.end())
    throw NoSuchObjectException();
  return (*it);
}

void		ClientManager::remove_all()
{
  std::list<Client *>::iterator it;

  it = _clients.begin();
  while (it != _clients.end())
    it = _clients.erase(it);
}

int		ClientManager::count()
{
  return (_clients.size());
}

Client*		ClientManager::findById(int id) const
{
  std::list<Client *>::const_iterator it;
  int		i = 0;

  it = _clients.begin();
  while (it != _clients.end() && (*it)->getId() != id)
    {
      ++it;
      ++i;
    }
  if (it == _clients.end())
    throw NoSuchObjectException();
  return (*it);  
}

Client*		ClientManager::findBySockAddr(SOCKADDR_IN *sin)
{
  std::list<Client *>::const_iterator it;
  int		i = 0;

  it = _clients.begin();
  while (it != _clients.end() && (*it)->getInfos().sin.sin_addr.s_addr != sin->sin_addr.s_addr)
    {
      ++it;
      ++i;
    }
  if (it == _clients.end())
    throw NoSuchObjectException();
  return (*it);  
}
