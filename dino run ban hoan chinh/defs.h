#ifndef _DEFS__H
#define _DEFS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

extern const int width;
extern const int height;
extern const char* title;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern SDL_Texture* background;
extern SDL_Texture* backsand;
extern SDL_Texture* dino;
extern SDL_Texture* cactus1;
extern SDL_Texture* cactus2;
extern SDL_Texture* sand;
extern SDL_Texture* gameover;

extern SDL_Texture* backmenu;
extern SDL_Texture* dinorunendless;
extern SDL_Texture* play;
extern SDL_Texture* maps;
extern SDL_Texture* quit;

extern SDL_Texture* blackplay;
extern SDL_Texture* blackmap;
extern SDL_Texture* blackquit;

extern Mix_Chunk* sound;
extern Mix_Chunk* rattle;
extern Mix_Chunk* wind;
extern Mix_Chunk* lofi;

#endif

