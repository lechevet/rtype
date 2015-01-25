#include	"Client.hh"

Client::Client()
{
  _active = false;
}

Client::Client(t_infos *infos, int id)
{
  _id = id;
  _infos.sin = infos->sin;
  _infos.len = infos->len;
  _active = false;
}

Client::~Client()
{
}

t_infos		Client::getInfos() const
{
  return (_infos);
}

int		Client::getId() const
{
  return (_id);
}

void		Client::setInfos(t_infos *infos)
{
  _infos.sin = infos->sin;
  _infos.len = infos->len;
}

void		Client::setId(int id)
{
  _id = id;
}

bool		Client::isActive() const
{
  return (_active);
}

void		Client::setActivity(bool value)
{
  _active = value;
}
