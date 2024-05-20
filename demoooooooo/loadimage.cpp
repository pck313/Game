#include "loadimage.h"

void loadImage() //Tai cac hinh anh cua menu va man hinh choi game
{
    background = loadTexture("background.png");
    backsand = loadTexture("backsand.png");
    dino = loadTexture("dino.png");
    cactus1 = loadTexture("cactus1.png");
    cactus2 = loadTexture("cactus2.png");
    sand = loadTexture("sand.png");
    gameover = loadTexture("gameover.png");

    backmenu = loadTexture("backmenu.png");
    dinorunendless = loadTexture("dinorunendless.png");
    play = loadTexture("play.png");
    maps = loadTexture("maps.png");
    quit = loadTexture("quit.png");
}

