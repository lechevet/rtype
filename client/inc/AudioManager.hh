#ifndef		AUDIOMANAGER_HH
# define	AUDIOMANAGER_HH

# include	<SFML/Audio.hpp>
# include	"Definitions.hh"
# include	"AWeapon.hh"

using namespace sf;

class		AudioManager
{
private:
  SoundBuffer	buffer[5];
  Sound		sound[5];

public:
  AudioManager();
  ~AudioManager();
  void		playMusic();
  void		pauseMusic();
  void		stopMusic();
  void		playWeaponSound(const AWeapon &);
  void		pauseWeaponSound(const AWeapon &);
  void		stopWeaponSound(const AWeapon &);
};

#endif
