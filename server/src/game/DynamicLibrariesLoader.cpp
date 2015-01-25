#include	<stdexcept>
#include	<dlfcn.h>
#include	"game/DynamicLibrariesLoader.hh"
#include	<iostream>

DynamicLibrariesLoader::DynamicLibrariesLoader()
{
  handler = new AbstractDl();

  handler->open("mods/Enemy.so", RTLD_NOW | RTLD_GLOBAL);
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
  dlclose(handler);
}

Enemy*		DynamicLibrariesLoader::getInstanceObject(int id)
{
  return (((Enemy* (*)(int))create)(id));
}

void		DynamicLibrariesLoader::destroyInstanceObject(Enemy *enemy)
{
  ((void (*)(Enemy *))destroy)(enemy);
}
