// sound loader, to playm music and have sound effects

#ifndef SOUNDCLASS_H
#define SOUNDCLASS_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;

class SoundClass
{
	public:
		SoundClass(string,int);
		void play();
		void pause();
		void stop();
		void load();
	private:
		string filename;
		Mix_Chunk *effect;
		Mix_Music *song;

};

#endif
