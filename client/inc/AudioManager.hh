#ifndef		AUDIOMANAGER_HH
# define	AUDIOMANAGER_HH

# include	<SFML/Audio.hpp>
# include	"Definitions.hh"

using namespace sf;

class		AudioManager
{
private:
  std::map<EnumSound, SoundBuffer>	buffer;
  std::map<EnumSound, Sound>		sound;

public:
  AudioManager();
  ~AudioManager();
  void		playMusic(EnumSound);
  void		pauseMusic(EnumSound);
  void		stopMusic(EnumSound);
};

#endif
