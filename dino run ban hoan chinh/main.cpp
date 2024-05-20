#include "defs.h"
#include "graphic.h"

int main(int argc, char* argv[])
{
    window = initSDL(width, height, title);
    renderer = createRenderer();
    loadImage();
}
