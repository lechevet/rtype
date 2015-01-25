#ifndef		CROSSTYPE_HH
# define	CROSSTYPE_HH


# ifdef		_WIN32
#  define       WIN32_LEAN_AND_MEAN
#  include	<winsock2.h>
#  define       NOMINMAX
#  include	<windows.h>
#  include	<winioctl.h>
#  include	<ws2tcpip.h>
#  include	<stdint.h>
#  pragma comment(lib, "ws2_32.lib")
#  pragma comment(lib, "winmm.lib")
# else
#  include	<sys/types.h>
#  include	<sys/socket.h>
#  include	<sys/ioctl.h>
#  include	<netinet/in.h>
#  include	<arpa/inet.h>
#  include	<unistd.h>
#  include      <netdb.h>

typedef		int			SOCKET;
typedef		struct sockaddr_in	SOCKADDR_IN;
typedef		struct sockaddr_in6	SOCKADDR_IN6;
typedef		struct sockaddr_storage	SOCKADDR_STORAGE;
typedef		struct sockaddr		SOCKADDR;
typedef		struct in_addr		IN_ADDR;
typedef		struct timeval		TIMEVAL;

# endif

#endif
