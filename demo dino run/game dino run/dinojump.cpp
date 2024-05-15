#include "dinojump.h"

void earthQuake(SDL_Renderer* renderer, SDL_Texture* background)
{
    SDL_Rect shakeRect = {0, 0, 1540, 850};
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
        {
            shakeRect.x = -5; //rung sang trái
        }
        else
        {
            shakeRect.x = 5; // rung sang phải khi i lẻ
        }
        SDL_RenderCopy(renderer, background, NULL, &shakeRect);
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }
}

void jumpUp(SDL_Renderer* renderer, SDL_Texture* background, SDL_Texture* sand, SDL_Texture* dino, SDL_Texture* cactus1,SDL_Texture* cactus2, Mix_Chunk* ground)
{
    int score = 0;

    int x = 100;
    int y = 800;
    const int y0 = y;

    bool jump = false;
    bool exit = false;

    int sandX1 = 0;
    int sandX2 = 1918;
    const int sandSpeed = 5;

    int cactus1X = 1560;
    const int cactus1Speed = 5;

    int cactus2X = 3025;
    const int cactus2Speed = 5;

    bool isOnGround = false;
    int earthquakeDuration = 0;

    while (!exit)
    {
       SDL_Event event;
       while (SDL_PollEvent(&event))
       {
          if (event.type == SDL_QUIT) //Kiem tra viec dong cua so
          {
              exit = true;
          }
          if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN) //Su kien nhan phim hoac bam chuot
          {
              jump = true; //Nhay len khi bam phim hoac chuot
          }
       }
       if (jump)
       {
           y -= 5;
           if (y < 550)
           {
               jump = false; //Doi huong
           }
       }
       else if (y < y0) //khi quay ve toa do ban dau
       {
           y += 5; //Di chuyen xuong duoi
           if (y >= y0)
           {
               y = y0; //Cham dat thi dung lai
               isOnGround = true;
               earthquakeDuration = 1;
           }
       }
       if (isOnGround && earthquakeDuration > 0)
       {
           earthQuake(renderer, background);
           earthquakeDuration--;
       }

    sandX1 -= sandSpeed;
    sandX2 -= sandSpeed;
       if (sandX1 <= -1918)
       {
           sandX1 = sandX2 + 1918;
           score += 100;
       }
       if (sandX2 <= -1918)
       {
           sandX2 = sandX1 + 1918;
           score += 100;
       }

    cactus1X -= cactus1Speed;
    if (cactus1X <= -100)
    {
        cactus1X = 3000;
    }

    cactus2X -= cactus2Speed;
    if (cactus2X <= -100)
    {
        cactus2X = 1600;
    }

    if ((x < cactus2X && x + 200 > cactus2X && y > 720) || (x < cactus1X && x + 200 > cactus1X && y > 720))
    {
        exit = true;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL); //Ve lai nen


    renderTexture(sand, sandX1, 860, renderer);
    renderTexture(sand, sandX2, 860, renderer);

    renderTexture(cactus1, cactus1X, 800, renderer);
    renderTexture(cactus2, cactus2X, 800, renderer);

    renderTexture(dino, x, y, renderer);


    SDL_RenderPresent(renderer); //Hien anh len cua so
    SDL_Delay(2.8);

    }
    cout << "Your scores are: " << score;
}
