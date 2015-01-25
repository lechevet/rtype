#ifndef		SERVER_HH
# define	SERVER_HH

#include	"Socket.hh"
#include	"Thread.hh"
#include	"ClientManager.hh"
#include	"Mutex.hh"
#include	"game/Game.hh"

class		Server
{
private:
  Game		_game;
  ISocket*	_sock;
  IMutex*	_mutex;
  int		_maxId;
  ClientManager _clients;
  std::list<t_dataGest>	_dataGest;

  void		sendDatas(int);
  static void	*newClients(void *);
  void		addClient(t_infos *infos);
  void		activeClient(int);
  void		gestData();

public:
  Server();
  ~Server();

  ISocket*	getSock() const;
  int		getMaxId() const;
  ClientManager	getClient() const;
  std::list<t_dataGest>	getDataGest()const;

  void		setSock(ISocket *);
  void		setMaxId(int);
  void		setDataGest(t_dataGest *);
  void		setDataGest(EnumData, int, t_infos *);

  void		start();
};

#endif
