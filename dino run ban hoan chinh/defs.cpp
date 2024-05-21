#include "defs.h"

const int width = 1540;
const int height = 850;
const char* title = "DINO GAME";

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

SDL_Texture* background = nullptr;
SDL_Texture* backsand = nullptr;
SDL_Texture* dino = nullptr;
SDL_Texture* cactus1 = nullptr;
SDL_Texture* cactus2 = nullptr;
SDL_Texture* sand = nullptr;
SDL_Texture* gameover = nullptr;

SDL_Texture* backmenu = nullptr;
SDL_Texture* dinorunendless = nullptr;
SDL_Texture* play = nullptr;
SDL_Texture* maps = nullptr;
SDL_Texture* quit = nullptr;

SDL_Texture* blackplay = nullptr;
SDL_Texture* blackmap = nullptr;
SDL_Texture* blackquit = nullptr;

Mix_Chunk* sound = nullptr;
Mix_Chunk* rattle = nullptr;
Mix_Chunk* wind = nullptr;
Mix_Chunk* lofi = nullptr;
