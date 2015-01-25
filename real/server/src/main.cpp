#include <iostream>
#include "Server.hh"

int	main()
{
  Server	server;

  try
    {
      srand(time(NULL));
      server.start();
    }
  catch (RtypeException &e)
    {
      std::cout << "Error: " << e.what() << std::endl;
    }
  return (0);
}
