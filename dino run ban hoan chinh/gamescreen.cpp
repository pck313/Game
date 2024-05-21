#include "gamescreen.h"

int x = 100;
int y = 800;
int score = 0;
int speed = 5;
int shake = 0;
int backsandSpeed = 1;

bool jump = false;
bool esc = false;
bool ground = false;

int backsand1 = 0, backsand2 = 1918;
int sand1 = 0, sand2 = 1918;
int cactusx1 = 3000, cactusx2 = 4500;

void displayGame() //Hien thi cac hinh anh cua game
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    renderTexture(backsand, backsand1, 830);
    renderTexture(backsand, backsand2, 830);
    renderTexture(sand, sand1, 900);
    renderTexture(sand, sand2, 900);
    renderTexture(cactus1, cactusx1, 800);
    renderTexture(cactus2, cactusx2, 800);
    renderTexture(dino, x, y);
    SDL_RenderPresent(renderer);
}

void checkCrash() //Kiem tra va cham cua dino va cactus
{
    if ((x < cactusx1 && x + 200 > cactusx1 && y > 710) || (x < cactusx2 && x + 200 > cactusx2 && y > 710))
    {
        Mix_FreeChunk(wind);
        SDL_Event event;
        renderTexture(gameover, 400, 650);
        SDL_RenderPresent(renderer);
        bool gameOver = false;
        while (!gameOver && SDL_WaitEvent(&event))
        {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
            {
                gameOver = true;
                esc = true;
            }
        }
    }
}

void slideImage() //Tao chuyen dong cho boi canh
{
    sand1 -= speed;
    sand2 -= speed;
    if (sand1 <= -1918)
    {
        sand1 = sand2 + 1918;
        score += 100;
    }
    if (sand2 <= -1918)
    {
        sand2 = sand1 + 1918;
        score += 100;
    }
    backsand1 -= backsandSpeed;
    backsand2 -= backsandSpeed;
    if (backsand1 <= -1918)
    {
        backsand1 = backsand2 + 1918;
    }
    if (backsand2 <= -1918)
    {
        backsand2 = backsand1 + 1918;
    }

    cactusx1 -= speed;
    if (cactusx1 <= -100)
    {
        cactusx1 = 3000;
    }
    cactusx2 -= speed;
    if (cactusx2 <= -100)
    {
        cactusx2 = 1600;
    }

}

void earthQuake() //Tao dong dat khi dino nhay xuong
{
    SDL_Rect shakeBackground = {0, 0, 1540, 850};
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            shakeBackground.x = -5;
        }
        else
        {
            shakeBackground.x = 5;
        }
    SDL_RenderCopy(renderer, background, nullptr, &shakeBackground);
    SDL_RenderPresent(renderer);
    SDL_Delay(30);
    }
}

void dinoJump() //Khung long nhay len va roi xuong
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            esc = true;
        }
        if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
        {
            jump = true;
        }
    }

    if (jump)
    {
        y -= speed;
        if (y <= 550)
        {
            jump = false;
        }
    }
    else if (y < 800)
    {
        y += speed;
        if (y >= 800)
        {
            y = 800;
            ground = true;
            shake = 1;
        }
    }

    if (ground && shake > 0)
    {
        Mix_PlayChannel(-1, rattle, 0); //Tao am thanh khi dong dat
        earthQuake();
        shake--;
    }
}
void start() //Chay man hinh game
{
    Mix_PlayChannel(-1, wind, -1);
    while (!esc)
    {
        dinoJump();
        slideImage();
        checkCrash();
        displayGame();
        displayScore(score);
        SDL_Delay(2.5);
    }
}
