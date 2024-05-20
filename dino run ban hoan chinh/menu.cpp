#include "menu.h"

bool out = false;
bool startGame = false;

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
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            out = true;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if(x >= 600 && x <= 600 + 340 && y >= 430 - 168 && y <= 430)
            {
                startGame = true;
            }
        }
    }
}

void moveToGame()
{
    while (!out)
    {
        displayMenu();
        while (!startGame && !out)
        {
            playButton();
        }
        if (startGame)
        {
            start();
            startGame = false;
        }
    }
}
