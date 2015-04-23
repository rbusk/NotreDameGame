//Sound class 
//Ryan Busk

#include "SoundClass.h"
#include <cstdio>

SoundClass::SoundClass(string music, int type)
{
	effect = NULL;
	song = NULL;
	music = "resources/sounds/"+music;

	if (type == 1)
	{
		song = Mix_LoadMUS(music.c_str());
	}
	if (type == 2)
	{
		effect = Mix_LoadWAV(music.c_str());
	}

	if (song == NULL)
	{
		cout << "error loading music " << music << Mix_GetError() << endl;
	}

}

void SoundClass::play()
{
	if (song != NULL && Mix_PlayingMusic() == 0)
	{
		//Play Music
		Mix_PlayMusic(song,-1);
	}
	if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
	if (effect != NULL)
	{
		Mix_PlayChannel(-1, effect, 0);
	}


}

void SoundClass::pause()
{
	if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 0)
	{
		Mix_PauseMusic();
	}

}

void SoundClass::stop()
{
	Mix_HaltMusic();
}
		
