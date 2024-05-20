#include "graphics.h"

SDL_Window* initSDL(int width, int height, const char* title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) !=0)
    {
        cout << "Khoi tao SDL khong thanh cong. " << endl;
        return nullptr;
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        cout << "Khoi tao SDL Image khong thanh cong. " << endl;
        SDL_Quit();
        return nullptr;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Tao cua so khong thanh cong. " << endl;
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
        cout << "Khong hien thi duoc anh. " << endl;
    }
    return renderer;
}

SDL_Texture *loadTexture(const char *filename)
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == nullptr)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Tai anh that bai: ", IMG_GetError());
    }
	return texture;
}

//Hien thi anh voi toa do cu the
void renderTexture(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;
	SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
	dest.x = x;
	dest.y = y - dest.h;
	SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

//Giu cho cua so khong bi dong
void waitWindowClosed()
{
    SDL_Event event;
    bool quit = true;
    while (quit)
    {
        if (SDL_WaitEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = false;
            }
        }
    }
}

//Giai phong thu vien
void quitSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

