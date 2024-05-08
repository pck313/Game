#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* initSDL(int width, int height, const char* title);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture* loadTexture(const char* filename, SDL_Renderer* renderer);
SDL_Renderer* createRenderer(SDL_Window* window);
void renderTexture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer);
void waitWindowClosed();

#endif
