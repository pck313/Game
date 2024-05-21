#include "defs.h"
#include "loadimage.h"
#include "menu.h"

int main(int argc, char* argv[])
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();
    window = initSDL(width, height, title);
    renderer = createRenderer();
    loadImage();
    moveToGame();
}
