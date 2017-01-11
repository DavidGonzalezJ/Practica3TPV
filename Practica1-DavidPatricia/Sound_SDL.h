#pragma once
#include "checkML.h"
#include <string>
#include "SDL_mixer.h"

class Sound_SDL
{
public:
	Sound_SDL(std::string musica, std::string efecto);
	~Sound_SDL();
	void soundInit();
	void playMusic();
	void playEffect();
	void load(std::string musica, std::string efecto);
	static void close();

private:
	Mix_Music* pMusic;
	Mix_Chunk* pEffect;
};

