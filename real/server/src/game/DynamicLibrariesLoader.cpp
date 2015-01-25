#include	<stdexcept>
#include	"DynamicLibrariesLoader.hh"
#include	<iostream>

DynamicLibrariesLoader::DynamicLibrariesLoader()
{
  handler = new AbstractDl();

# ifdef	_WIN32
  handler->open("mods/Enemy.so", NULL);
# else
  handler->open("mods/Enemy.so", RTLD_NOW | RTLD_GLOBAL);
#endif
  if ((create = handler->sym("Create")) == NULL)
	{
	  std::cout << "dlsym create: ";
	  throw std::runtime_error(handler->error());
	}
  if ((destroy = handler->sym("Destroy")) == NULL)
	{
	  std::cout << "dlsym destroy: ";
	  throw std::runtime_error(handler->error());
	}
}

DynamicLibrariesLoader::~DynamicLibrariesLoader()
{
	handler->close();
}

Enemy*		DynamicLibrariesLoader::getInstanceObject(int id)
{
  return (((Enemy* (*)(int))create)(id));
}

void		DynamicLibrariesLoader::destroyInstanceObject(Enemy *enemy)
{
  ((void (*)(Enemy *))destroy)(enemy);
}
