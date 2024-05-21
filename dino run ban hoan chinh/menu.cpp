#include "menu.h"

bool out = false;
bool startGame = false;

void displayMenu() //Hien thi cac hinh anh cua menu
{
    SDL_RenderCopy(renderer, backmenu, nullptr, nullptr);
    renderTexture(dinorunendless, 358, 245);
    renderTexture(play, 600, 430);
    renderTexture(maps, 625, 508);
    renderTexture(quit, 600, 585);

    SDL_RenderPresent(renderer);
}

void playButton() //Bam nut play thi bat dau game
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
            if(x >= 580 && x <= 920 && y >= 332 && y <= 390) // Kiem tra con chuot co cham vao anh Play
            {
                renderTexture(blackplay, 600, 430);
                SDL_RenderPresent(renderer);
                SDL_Delay(150);
                startGame = true;
                start();
            }
            else if(x >= 580 && x <= 920 && y >= 490 && y <= 530) //Kiem tra co bam vao Quit
            {
                renderTexture(blackquit, 600, 585);
                SDL_RenderPresent(renderer);
                SDL_Delay(150);
                out = true;
            }
            else if(x >= 580 && x <= 920 && y >= 400 && y <= 480) //Kiem tra co bam vao Map
            {
                renderTexture(blackmap, 625, 508);
                SDL_RenderPresent(renderer);
                SDL_Delay(150);
                displayGame();
            }
        }
    }
}

void moveToGame() //Chuyen toi man hinh choi game
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
