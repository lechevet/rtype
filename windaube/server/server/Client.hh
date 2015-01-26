#ifndef		CLIENT_HH
# define	CLIENT_HH

# include	"CrossType.hh"

typedef struct		s_infos
{
  SOCKADDR_IN	sin;
  socklen_t		len;
}			t_infos;

class		Client
{
private:
  t_infos	_infos;
  int		_id;
  bool		_active;

public:
  Client();
  Client(t_infos *, int);
  ~Client();

  t_infos	getInfos() const;
  int		getId() const;

  void		setInfos(t_infos *);
  void		setId(int);

  bool		isActive() const;
  void		setActivity(bool);
};

#endif
