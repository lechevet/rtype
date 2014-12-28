#include <iostream>
#include	"Server.hh"

Server::Server()
{
  _sock = new AbstractSocket(TCP);
  _ids = 0;
}

Server::~Server()
{
}

LobbyManager&	Server::getLobbyManager()
{
  return (_lobbyManager);
}

ISocket*	Server::getSock() const
{
  return (_sock);
}

int		Server::getIds() const
{
  return (_ids);
}

void		Server::setLobbyManager(LobbyManager &lobbyManager)
{
  _lobbyManager = lobbyManager;
}

void		Server::setSock(ISocket *sock)
{
  _sock = sock;
}

void		Server::setIds(int ids)
{
  _ids = ids;
}

void		Server::addClient()
{
  Client	*client = new Client(_ids);
  ISocket	*sock;

  sock = _sock->accept();
  client->setSock(sock);
  _clientManager.add(client);
  _lobbyManager.addClient(client);
  ++_ids;
}

Client*		Server::getClient(int nb) const
{
  return (_clientManager.get(nb));
}
