#include	<stdexcept>
#include	<dlfcn.h>
#include	"DynamicLibrariesLoader.hh"
#include	<iostream>

DynamicLibrariesLoader::DynamicLibrariesLoader()
{
  if ((handler = dlopen("mods/Enemy.so", RTLD_NOW | RTLD_GLOBAL)) == NULL)
    {
      std::cout << "dlopen: ";
      throw std::runtime_error(dlerror());
    }
  if ((create = dlsym(handler, "Create")) == NULL)
    {
      std::cout << "dlsym create: ";
      throw std::runtime_error(dlerror());
    }
  if ((destroy = dlsym(handler, "Destroy")) == NULL)
    {
      std::cout << "dlsym destroy: ";
      throw std::runtime_error(dlerror());
    }
}

DynamicLibrariesLoader::~DynamicLibrariesLoader()
{
  dlclose(handler);
}

Enemy*		DynamicLibrariesLoader::getInstanceObject(SpriteGiver &sprites)
{
  return (((Enemy* (*)(SpriteGiver &))create)(sprites));
}

void		DynamicLibrariesLoader::destroyInstanceObject(Enemy *enemy)
{
  ((void (*)(Enemy *))destroy)(enemy);
}
