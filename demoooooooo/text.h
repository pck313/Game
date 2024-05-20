#ifndef _TEXT__H
#define _TEXT__H

#include "defs.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "graphics.h"

TTF_Font* loadFont(const char* path, int size);
SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
void displayScore(int score);

#endif
