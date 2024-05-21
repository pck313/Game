#include "graphic.h"

SDL_Window* initSDL(int width, int height, const char* title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "Khoi tao SDL khong thanh cong. " <<endl;
        return nullptr;
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        cout << "Khoi tao SDL hinh anh khong thanh cong. " <<endl;
        SDL_Quit();
        return nullptr;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Tao cua so khong thanh cong. " <<endl;
        IMG_Quit();
        SDL_Quit();
        return nullptr;
    }
    return window;
}

SDL_Renderer* createRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "Khong hien thi duoc anh. " <<endl;
        return nullptr;
    }
    return renderer;
}

SDL_Texture* loadTexture(char* filename)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
    if (texture == nullptr)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Tai anh that bai. ", IMG_GetError());
    }
    return texture;
}

void renderTexture(SDL_Texture* texture, int x, int y)
{
    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect dest = {x, y - h, w, h};
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void waiWindowClosed() //Doi khi man hinh tat thi dung man hinh
{
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        if (SDL_WaitEvent(&event) && event.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

void quitSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();

}
