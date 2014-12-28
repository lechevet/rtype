#include	<iostream>
#include	"Game.hh"
#include	"Select.hh"

int main()
{
  // try
  //   {
  //     Server server;
  //     Select select(&server);

  //     while (select.waitFds(&server) != -1)
  // 	{
  // 	  if (select.isThereNewClient(&server) == true)
  // 	    server.addClient();
  // 	  // select.sendThings(&server);
  // 	  // select.recvThings(&server);
  // 	  // server.gestClient();
  // 	}
  //   }
  // catch (const RtypeException &e)
  //   {
  //     std::cout << e.what() << std::endl;
  //   }
  ClientManager	clientManager;
  Game	game(clientManager);

  game.start();
  return (0);
}
