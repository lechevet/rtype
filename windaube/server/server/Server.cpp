#include	<iostream>
#include	"NoSuchObjectException.hpp"

#include	"Server.hh"

Server::Server()
{
  _sock = new AbstractSocket(UDP);
  _mutex = new AbstractMutex();
  _maxId = 0;
}

Server::~Server()
{
}

 
ISocket*	Server::getSock() const
{
  return (_sock);
}

int		Server::getMaxId() const
{
  return (_maxId);
}

ClientManager		Server::getClient() const
{
  return (_clients);
}

void		Server::setSock(ISocket *sock)
{
  _sock = sock;
}

void		Server::setMaxId(int maxId)
{
  _maxId = maxId;
}

void*		Server::newClients(void *data)
{
  t_recv	rec;
  t_infos	infos;
  Server	*tmp;

  tmp = (Server *)data;
  while (true)
    {
      infos.len = sizeof(infos.sin);
      tmp->getSock()->recvDataFrom(&rec, sizeof(t_recv), 0, (SOCKADDR *)&(infos.sin), &(infos.len));
      tmp->setDataGest(rec.data, rec.id, &infos);
    }
}

void		Server::start()
{
  IThread *th = new AbstractThread();
  t_proto	rec;
  TIMEVAL		start;
  TIMEVAL		end;
  double			frame;
  int				ret;

  _sock->bind();
  _sock->listen();
  th->create(&newClients, this);
  while (true)
    {
      MySleep::gettimeofday(&start, NULL);  
      gestData();
      ret = _game.update();
      sendDatas(ret);
      MySleep::gettimeofday(&end, NULL);
      frame = ((double)(1000000*(end.tv_sec-start.tv_sec)+((end.tv_usec-start.tv_usec))));
      MySleep::usleep(1000000 / 120 - frame);
    }
}

void		Server::sendDatas(int deadId)
{
  t_proto	proto;
  struct sockaddr_in	sin;
  int		i;
  t_hello	newClient;
  static int	x = 0;
  EntityManager<IEntity*>	entityManager;
  int		count;
  IEntity	*tmp;
  Starfield	*starfield;

  i = 0;
  newClient.cmd = HELLO;
  entityManager = _game.getEntityManager();
  try
    {
      while (_clients.get(i))
	{
	  sin = _clients.get(i)->getInfos().sin;
	  if (_clients.get(i)->isActive() == false)
	    {
	      newClient.id = _clients.get(i)->getId();
	      _sock->sendDataTo(&newClient, sizeof(t_hello), 0, (SOCKADDR *)&sin, _clients.get(i)->getInfos().len);
	    }
	  else
	    {
	      count = 0;
	      while ((tmp = entityManager.find(count)))
		{
		  proto.type = tmp->getType();
		  proto.x = tmp->getCoord().getX();
		  proto.y = tmp->getCoord().getY();
		  proto.entityCount = entityManager.count();
		  proto.damaged = tmp->isDamaged();
		  proto.deadId = deadId;
		  _sock->sendDataTo(&proto, sizeof(t_proto), 0, (SOCKADDR *)&sin, _clients.get(i)->getInfos().len);
		  if (deadId != -1)
		    _clients.remove(_clients.findById(deadId));
		  if (tmp->getType() == STARFIELD)
		    {
		      starfield = (Starfield *)tmp;
		      proto.type = STARFIELD2;
		      proto.x = starfield->getCoord2().getX();
		      proto.y = starfield->getCoord2().getY();
		      proto.entityCount = entityManager.count();
		      _sock->sendDataTo(&proto, sizeof(t_proto), 0, (SOCKADDR *)&sin, _clients.get(i)->getInfos().len);
		    }
		  ++count;
		}
	    }
	  ++i;
	}
    }
  catch (NoSuchObjectException &e)
    {
    }
}

std::list<t_dataGest>	Server::getDataGest() const
{
  return (_dataGest);
}

void		Server::setDataGest(t_dataGest *dataGest)
{
  _mutex->lock();
  _dataGest.push_back(*dataGest);
  _mutex->unlock();
}

void		Server::setDataGest(EnumData enumData, int id, t_infos *infos)
{
  t_dataGest	tmp;

  _mutex->lock();
  tmp.cmd = enumData;
  tmp.id = id;
  tmp.infos.sin = infos->sin;
  tmp.infos.len = infos->len;
  _dataGest.push_back(tmp);
  _mutex->unlock();
}

void		Server::addClient(t_infos *infos)
{
  _clients.add(new Client(infos, _maxId));
  ++_maxId;
}

void		Server::activeClient(int id)
{
  Client	*tmp;

  try
    {
      tmp = _clients.findById(id);
      tmp->setActivity(true);
      _game.addShip(id);
    }
  catch (NoSuchObjectException &e)
    {
    }
}

void		Server::gestData()
{
  std::list<t_dataGest>::iterator it;
  t_dataGest	tmp;

  _mutex->lock();
  it = _dataGest.begin();
  while (it != _dataGest.end())
    {
      tmp = *it;
      if (tmp.cmd == NEW)
	{
	  addClient(&(tmp.infos));
	  tmp.cmd = NONE;
	}
      else if (tmp.cmd == OK)
	{
	  activeClient(tmp.id);
	  tmp.cmd = NONE;
	}
      else if (tmp.cmd == BYE)
	{
	  _game.removeShip(tmp.id);
	  _clients.remove(_clients.findById(tmp.id));
	}
      else if (tmp.cmd != NONE)
	_game.updateShip(tmp.cmd, tmp.id);
      it = _dataGest.erase(it);
    }
  _mutex->unlock();
}
