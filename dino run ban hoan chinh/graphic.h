#ifndef _GRAPHIC__H
#define _GRAPHIC__H

#include "defs.h"
#include <iostream>

using namespace std;

SDL_Window* initSDL(int width, int height, int title);
SDL_Renderer* createRenderer();
SDL_Texture* loadTexture(char* filename);
void renderTexture(SDL_Texture* texture, int x, int y);
void waiWindowClosed();

#endif
