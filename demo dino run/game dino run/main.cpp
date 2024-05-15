#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "dinojump.h"
#include "slideimage.h"

int main(int argc, char *argv[])
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); //Khoi tao SDL_mixer
    Mix_Chunk *sound = Mix_LoadWAV("sound.mp3");
    Mix_Chunk *ground = Mix_LoadWAV("ground.mp3");
    Mix_PlayChannel(-1, sound, 0);

    SDL_Window* window = initSDL(width, height, title); //Tao cua so sdl
    SDL_Renderer* renderer = createRenderer(window); //Tao renderner

    SDL_Texture* background = loadTexture("background.png", renderer);
    SDL_Texture* sand = loadTexture("sand.png", renderer);
    SDL_Texture* dino = loadTexture("dino.png", renderer);
    SDL_Texture* cactus1 = loadTexture("cactus1.png", renderer);
    SDL_Texture* cactus2 = loadTexture("cactus2.png", renderer);

    jumpUp(renderer, background, sand, dino, cactus1, cactus2, ground);

    SDL_DestroyTexture(background); //Giai phong bo nho texture ko dung den
    background = NULL; //De phong truong hop dung nham con tro da giai phong
    Mix_FreeChunk(sound); //Giai phong bo nho

    quitSDL(window, renderer); //Dong cua so va giai phong renderner

    return 0;
}
