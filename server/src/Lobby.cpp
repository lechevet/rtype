#include	"NoSuchObjectException.hpp"
#include	"Lobby.hh"
#include <iostream>

Lobby::Lobby(int id)
{
  _activeClients = 0;
  _id = id;
}

Lobby::Lobby(const Lobby &other)
{
  _id = other._id;
  _activeClients = other._activeClients;
  _clientManager = other._clientManager;
}

Lobby&	Lobby::operator=(const Lobby &other)
{
  _clientManager = other._clientManager;
  _activeClients = other._activeClients;
  _id = other._id;
  return (*this);
}

Lobby::~Lobby()
{
}

ClientManager&	Lobby::getClientManager()
{
  return (_clientManager);
}

void		Lobby::addClient(Client *client)
{
  std::cout << "Lobby : " << _id;
  std::cout << ", client " << client->getId();
  client->setId(_activeClients);
  if (_activeClients < 4)
    _clientManager.add(client);
  numberClients();
  std::cout << ", client local id " << client->getId() << std::endl;
}

void		Lobby::numberClients()
{
  _activeClients = _clientManager.count();
}

int		Lobby::getNumberClients() const
{
  return (_activeClients);
}

bool		Lobby::operator!=(Lobby &other) const
{
  if (_id != other._id)
    return (true);
  return (false);
}

bool		Lobby::operator==(Lobby &other) const
{
  if (_id == other._id)
    return (true);
  return (false);
}

int		Lobby::getId() const
{
  return (_id);
}
