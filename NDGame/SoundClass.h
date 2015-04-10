// sound loader, to playm music and have sound effects

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class SoundClass
{
	public:
		SoundLoader(Mix_Chunk*);
		~SoundLoader();

