#ifndef _DINOJUMP__H
#define _DINOJUMP__H

#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include <math.h>
#include <SDL_mixer.h>

using namespace std;

void jumpUp(SDL_Renderer* renderer, SDL_Texture* background, SDL_Texture* sand, SDL_Texture* dino, SDL_Texture* cactus1, SDL_Texture* cactus2, Mix_Chunk* ground);

#endif

