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
		SoundClass();//default constructor
		SoundClass(string,int); //constructor that loads song
		void play(); //plays song
		void pause(); //pauses song, only works for music, not effects
		void stop(); // stops music
		void load(string, int); //loads song
	private:
		string filename; //name of song
		Mix_Chunk *effect; //file loaded
		Mix_Music *song; // file loaded
		int loaded; //says if song is loaded

};

#endif
