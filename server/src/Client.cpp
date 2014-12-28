#include	"Client.hh"

Client::Client()
{
}

Client::Client(int id)
{
  _id = id;
}

Client::Client(const Client &other)
{
  _id = other._id;
  _sock = other._sock;
  _sendBuffer = other._sendBuffer;
  _recvBuffer = other._recvBuffer;
}

Client::~Client()
{
}

ISocket*	Client::getSock() const
{
  return (_sock);
}

std::string	Client::getSendBuffer() const
{
  return (_sendBuffer);
}

std::string	Client::getRecvBuffer() const
{
  return (_recvBuffer);
}

void		Client::setSock(ISocket *sock)
{
  _sock = sock;
}

void		Client::setId(int id)
{
  _id = id;
}

void		Client::setSendBuffer(const std::string &buffer)
{
  _sendBuffer = buffer;
}

void		Client::setRecvBuffer(const std::string &buffer)
{
  _recvBuffer = buffer;
}

int		Client::getId() const
{
  return (_id);
}

bool		Client::operator!=(Client &other) const
{
  if (_id != other._id)
    return (true);
  return (false);
}

bool		Client::operator==(Client &other) const
{
  if (_id == other._id)
    return (true);
  return (false);
}
