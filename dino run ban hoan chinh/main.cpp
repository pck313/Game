#include "defs.h"
#include "graphic.h"
#include "loadimage.h"
#include "gamescreen.h"
#include "menu.h"



int main(int argc, char* argv[])
{
    TTF_Init();
    window = initSDL(width, height, title);
    renderer = createRenderer();
    loadImage();

    moveToGame();

}
