#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"

using namespace std;

SDL_Window* initSDL(int width, int height, const char* title);
void quitSDL();
SDL_Texture* loadTexture(const char* filename);
SDL_Renderer* createRenderer();
void renderTexture(SDL_Texture* texture, int x, int y);
void waitWindowClosed();

#endif
