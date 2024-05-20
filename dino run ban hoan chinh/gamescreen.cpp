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
bool gameOver = false;

int backsand1 = 0, backsand2 = 1918;
int sand1 = 0, sand2 = 1918;
int cactusx1 = 3000, cactusx2 = 4500;

void displayGame()
{
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

void checkCrash()
{
    SDL_Event event;
    if ((x < cactusx1 && x + 200 > cactusx1 && y > 710) || (x < cactusx2 && x + 200 > cactusx2 && y > 710))
    {
        renderTexture(gameover, 400, 650);
        SDL_RenderPresent(renderer);
        while (!gameOver)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    esc = true;
                    gameOver = true;
                }
                if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
                {
                    gameOver = true;
                }
            }

        }
        esc = true;
    }
}

void slideImage()
{
    sand1 -= speed;
    sand2 -= speed;

    backsand1 -= backsandSpeed;
    backsand2 -= backsandSpeed;

    cactusx1 -= speed;
    cactusx2 -= speed;

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

    if (backsand1 <= -1918)
    {
        backsand1 = backsand2 + 1918;
    }
    if (backsand2 <= -1918)
    {
        backsand2 = backsand1 + 1918;
    }

    if (cactusx1 <= -100)
    {
        cactusx1 = 3000;
    }
    if (cactusx2 <= -100)
    {
        cactusx2 = 1500;
    }

    if (sand2 > 0 && sand2 % (1918 * 3) == 0)
    {
        speed += 1;
        backsandSpeed += 1;
    }
}

void earthQuake()
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

void dinoJump()
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
        earthQuake();
        shake--;
    }
}
void start()
{
    while (!esc)
    {
        dinoJump();
        slideImage();
        checkCrash();
        SDL_RenderPresent(renderer);
        displayGame();
        displayScore(score);
        SDL_Delay(2.5);
    }
}
