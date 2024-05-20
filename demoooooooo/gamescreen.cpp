#include "gamescreen.h"

    int x = 100;
    int y = 800;
    int backsand1 = 0;
    int backsand2 = 1918;
    int sand1 = 0;
    int sand2 = 1918;
    int cactus1X = 3000;
    int cactus2X = 4500;

    int speed = 5;
    int backsandSpeed = 1;
    int score = 0;
    int shake = 0;

    bool esc = false;
    bool jump = false;
    bool gameOver = false;
    bool ground = false;

    SDL_Event event;

void slideImage() //Tao chuyen dong cho cat va xuong rong
{
    sand1 -= speed;
    sand2 -= speed;

    backsand1 -= backsandSpeed;
    backsand2 -= backsandSpeed;

    cactus1X -= speed;
    cactus2X -= speed;

    if (backsand1 <= -1918)
    {
        backsand1 = backsand2 + 1918;
    }
    if (backsand2 <= -1918)
    {
        backsand2 = backsand1 + 1918;
    }
    if (sand1 <= -1918)
    {
        sand1 = sand2 + 1918;
    }
    if (sand2 <= -1918)
    {
        sand2 = sand1 + 1918;
    }
    if (cactus1X <= -100)
    {
        cactus1X = 3000;
    }

    if (cactus2X <= -100)
    {
        cactus2X = 1600;
    }
    if (sand2 > 0 && sand2 % 1918*3 == 0) //tang toc do chuyen dong
    {
        speed += 1;
        backsandSpeed += 1;
    }
    frameCount++;

}

void checkCrash() //Kiem tra khung long co cham xuong rong khong
{
    if ((x < cactus2X && x + 200 > cactus2X && y > 710) || (x < cactus1X && x + 200 > cactus1X && y > 720))
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

void earthQuake() //Tao dong dat khi khung long cham dat
{
    SDL_Rect shakeBackground = {0, 0, 1540, 850};
    for (int i = 0; i < 10; ++i)
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

void dinoJump() //Con khung long nhay len va xuong
{
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
        if (y < 550)
        {
            jump = false; //Doi huong
        }
    }
    else if (y < 800)
    {
        y += speed;
        if (y >= 800)
        {
            y = 800; //Cham dat thi dung lai
            ground = true;
            shake = 1;
        }
    }
    if (ground && shake > 0) //Cham dat thi dong dat
    {
        earthQuake();
        shake--;
    }
}

void displayGame() //Hien thi cac hinh anh cua man hinh game
{
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    renderTexture(backsand, backsand1, 830);
    renderTexture(backsand, backsand2, 830);
    renderTexture(sand, sand1, 900);
    renderTexture(sand, sand2, 900);
    renderTexture(cactus1, cactus1X, 800);
    renderTexture(cactus2, cactus2X, 800);
    renderTexture(dino, x, y);

    SDL_RenderPresent(renderer);
}

void gameStart() //Choi game
{
    while (!esc)
    {
        dinoJump();
        slideImage();
        checkCrash();
        SDL_RenderClear(renderer);
        displayGame();
        displayScore(score);
        SDL_Delay(3);
    }
    cout << score;
}
