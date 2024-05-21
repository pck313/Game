#include "loadimage.h"

void loadImage() //Tai cac hinh anh cua menu va man hinh game
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

    blackplay = loadTexture("blackplay.png");
    blackmap = loadTexture("blackmap.png");
    blackquit = loadTexture("blackquit.png");

//Tai cac am thanh
    rattle = Mix_LoadWAV("rattle.mp3"); //am thanh dong dat
    wind = Mix_LoadWAV("wind.mp3");
}
