#include "dinojump.h"

void jumpUp(SDL_Renderer* renderer, SDL_Texture* background, SDL_Texture* sand, SDL_Texture* dino, SDL_Texture* cactus1)
{
    int x = 200;
    int y = 800;
    const int y0 = y;

    bool jump = false;
    bool exit = false;

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
           if (y < 610) jump = false; //Doi huong
       }
       else if (y < y0) //khi quay ve toa do ban dau
       {
           y += 5; //Di chuyen xuong duoi
           if (y >= y0)
           {
               y = y0; //Cham dat thi dung lai
           }
       }
    SDL_RenderClear(renderer); //Xoa hinh anh
    SDL_RenderCopy(renderer, background, NULL, NULL); //Ve lai nen
    renderTexture(sand, 0, 860, renderer);
    renderTexture(dino, x, y, renderer);
    renderTexture(cactus1, 500, 800, renderer);
    SDL_RenderPresent(renderer); //Hien anh len cua so
    SDL_Delay(1); //Chinh toc do
    }
}
