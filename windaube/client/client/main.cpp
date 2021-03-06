#include        <SFML/Graphics.hpp>
#include        <SFML/Audio.hpp>
#include <iostream>
#include "Socket.hh"
#include "SpriteGiver.hh"
#include "Client.hh"

int	main()
{
  Client	client;
  EnumData	data;
  AudioManager	audioManager;

  client.makeConnection();
  audioManager.playMusic(MUSIC);
  while (true)
    {
      if ((data = client.eventGest()) != NONE)
	client.sendData(data);
      if (client.isDead() == true ||client.rendering() == -1)
	client.gameOver(audioManager);
    }
  return (0);
}
