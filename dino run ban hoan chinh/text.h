#ifndef _TEXT__H
#define _TEXT__H

#include "graphic.h"
#include "defs.h"
#include <SDL_ttf.h>

TTF_Font* loadFont(const char* path, int size);
SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color color);
void displayScore(int score); //Hien thi diem so len man hinh

#endif
