#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
#include "dinojump.h"
#include "slideimage.h"

int main(int argc, char *argv[])
{
    const int width = 1540;
    const int height = 850;
    const char* title = "DINO WINDOW";

    SDL_Window* window = initSDL(width, height, title); //Tao cua so sdl

    SDL_Renderer* renderer = createRenderer(window); //Tao renderner

    SDL_Texture* background = loadTexture("background.png", renderer); //Nap anh
    SDL_RenderCopy( renderer, background, NULL, NULL); //Hien thi anh len cua so

    SDL_Texture* sand = loadTexture("sand.png", renderer);
    renderTexture(sand, 0, 860, renderer);

    SDL_Texture* dino = loadTexture("dino.png", renderer);
    renderTexture(dino, 200, 800, renderer);

    SDL_Texture* cactus1 = loadTexture("cactus1.png", renderer);
    renderTexture(cactus1, 500, 800, renderer);

    SDL_RenderPresent(renderer); //Hien thi ban ve len man hinh

    jumpUp(renderer, background, sand, dino, cactus1); //Giu cua so mo khi chuong trinh chay

    SDL_DestroyTexture(background); //Giai phong bo nho texture ko dung den
    background = NULL; //De phong truong hop dung nham con tro da giai phong

    quitSDL(window, renderer); //Dong cua so va giai phong renderner

    return 0;
}
