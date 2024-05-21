#include "text.h"

TTF_Font* loadFont(const char* path, int size)
{
    TTF_Font* font = TTF_OpenFont(path, size);
    if (!font)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Tai font that bai. ", TTF_GetError());
    }
    return font;
}

SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color color)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    if (!textSurface)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Tao text surface that bai. ", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!texture)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Tai texture tu surface that bai. ", SDL_GetError());
    }
    SDL_FreeSurface(textSurface);
    return texture;
}

void displayScore(int score) //Hien thi diem so len man hinh
{
    TTF_Font* font = loadFont ("friz.otf", 60);
    SDL_Color color = {255, 255, 255, 255};
    string scoreText = "Score: " + to_string(score);

    SDL_Texture* mark = renderText(scoreText.c_str(), font, color);
    renderTexture(mark, 1050, 90);
    SDL_RenderPresent(renderer);
}
