#include	"AudioManager.hh"

AudioManager::AudioManager()
{
  buffer[MUSIC].loadFromFile("music/ffbattle.wav");
  sound[MUSIC].setBuffer(buffer[MUSIC]);
}

AudioManager::~AudioManager()
{
}

void		AudioManager::playMusic()
{
  sound[MUSIC].play();
}

void		AudioManager::pauseMusic()
{
  sound[MUSIC].pause();
}

void		AudioManager::stopMusic()
{
  sound[MUSIC].stop();
}

void		AudioManager::playWeaponSound(const AWeapon &weapon)
{
  sound[weapon.getType()].play();
}

void		AudioManager::pauseWeaponSound(const AWeapon &weapon)
{
  sound[weapon.getType()].pause();
}

void		AudioManager::stopWeaponSound(const AWeapon &weapon)
{
  sound[weapon.getType()].stop();
}
