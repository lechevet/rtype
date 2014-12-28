#include	"NoSuchObjectException.hpp"
#include	"LobbyManager.hh"
#include	<iostream>

LobbyManager::LobbyManager()
{
  _ids = 0;
}

LobbyManager::~LobbyManager()
{
}

void		LobbyManager::add()
{
  Lobby		*lobby = new Lobby(_ids);

  ++_ids;
  _list.push_back(lobby);

}

void		LobbyManager::addClient(Client *client)
{
  std::list<Lobby *>::iterator it;
  Lobby		*tmp;

  it = _list.begin();
  while (it != _list.end() && (*it)->getNumberClients() >= 4)
    ++it;
  tmp = *it;
  if (it == _list.end())
    {
      add();
      tmp = _list.back();
    }
  tmp->addClient(client);
}

void		LobbyManager::remove(Lobby *lobby)
{
  std::list<Lobby *>::iterator it;

  it = _list.begin();
  while (it != _list.end() && *it != lobby)
    ++it;
  if (it != _list.end())
    _list.erase(it);
}

Lobby*		LobbyManager::get(int lobbyNumber)
{
  std::list<Lobby *>::iterator it;
  int		i = 0;

  it = _list.begin();
  while (it != _list.end() && i < lobbyNumber + 1)
    {
      ++it;
      ++i;
    }
  if (it == _list.end())
    throw NoSuchObjectException();
  return (*it);
}

void		LobbyManager::remove_all()
{
  std::list<Lobby *>::iterator	it;

  it = _list.begin();
  while (it != _list.end())
    it = _list.erase(it);
}

int		LobbyManager::count()
{
  return (_list.size());
}
