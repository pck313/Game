#include "menu.h"

void displayMenu()
{
    SDL_RenderCopy(renderer, backmenu, nullptr, nullptr);
    renderTexture(dinorunendless, 358, 245);
    renderTexture(play, 600, 430);
    renderTexture(maps, 625, 508);
    renderTexture(quit, 600, 585);

    SDL_RenderPresent(renderer);
}

void playButton()
{

}
