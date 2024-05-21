#ifndef _GRAPHIC__H
#define _GRAPHIC__H

#include "defs.h"
#include <iostream>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace std;

SDL_Window* initSDL(int width, int height, const char* title);
SDL_Renderer* createRenderer();
SDL_Texture* loadTexture(char* filename);
void renderTexture(SDL_Texture* texture, int x, int y);
void waiWindowClosed(); //Dung man hinh cho den khi dong cua so

#endif
