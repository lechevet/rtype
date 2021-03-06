#include	"AudioManager.hh"

AudioManager::AudioManager()
{
  (buffer[MUSIC]).loadFromFile("music/ffbattle.wav");
  (sound[MUSIC]).setBuffer(buffer[MUSIC]);
  (buffer[GAMEOVERAUDIO]).loadFromFile("music/continue.wav");
  (sound[GAMEOVERAUDIO]).setBuffer(buffer[GAMEOVERAUDIO]);
}

AudioManager::~AudioManager()
{
}

void		AudioManager::playMusic(EnumSound audio)
{
  (sound[audio]).play();
}

void		AudioManager::pauseMusic(EnumSound audio)
{
  (sound[audio]).pause();
}

void		AudioManager::stopMusic(EnumSound audio)
{
  (sound[audio]).stop();
}
