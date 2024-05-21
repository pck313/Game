#include "destroy.h";

void destroy() //Giai phong bo nho
{
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(backsand);
    SDL_DestroyTexture(sand);
    SDL_DestroyTexture(cactus1);
    SDL_DestroyTexture(cactus2);
    SDL_DestroyTexture(dino);
    SDL_DestroyTexture(backmenu);
    SDL_DestroyTexture(dinorunendless);
    SDL_DestroyTexture(play);
    SDL_DestroyTexture(maps);
    SDL_DestroyTexture(quit);

    Mix_FreeChunk(wind);
    Mix_FreeChunk(rattle);
}
