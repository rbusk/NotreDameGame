//Sound class 
//Ryan Busk

#include "SoundClass.h"
#include <cstdio>


SoundClass::SoundClass() //default constructor
{
	loaded = 0; //not loaded
	effect = NULL; //set variables to NULL
	song = NULL; //set variables to NULL

}

SoundClass::SoundClass(string music, int typeOfSound) //load constructor
{
	loaded = 0; //loaded to zero
	effect = NULL; //sets variables to NULL
	song = NULL;
	int type = typeOfSound; //sets type of sound
	load(music, type); //loads song into variable


}

void SoundClass::play() //plays sound
{
	if (song != NULL && Mix_PlayingMusic() == 0)
	{
		//Play Music
		Mix_PlayMusic(song,-1);
	}
	if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 1) //resumes music if paused
	{
		Mix_ResumeMusic();
	}
	if (effect != NULL)
	{
		Mix_PlayChannel(-1, effect, 0); //play soundeffect
	}


}

void SoundClass::pause() //pause music
{
	if (song != NULL && Mix_PlayingMusic() != 0 && Mix_PausedMusic() == 0)
	{
		Mix_PauseMusic();
	}

}

void SoundClass::stop()
{
	Mix_HaltMusic(); //stop music from playing
}

void SoundClass::load(string music, int type)
{
	music = "resources/sounds/"+music; //add file path

	if (loaded == 0)
	{
		if (type == 1)
		{
			song = Mix_LoadMUS(music.c_str()); // load music if coder specifies music type
		}
		if (type == 2)
		{
			effect = Mix_LoadWAV(music.c_str()); // load sound effect specified by player
		}

		if (song == NULL)
		{
			cout << "error loading music " << music << Mix_GetError() << endl; //error thrown
		}
		loaded = 1;
	}
}
		
