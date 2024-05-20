#include "defs.h"
#include "graphic.h"
#include "loadimage.h"
#include "gamescreen.h"

int main(int argc, char* argv[])
{
    window = initSDL(width, height, title);
    renderer = createRenderer();

    loadImage();
    start();

}
