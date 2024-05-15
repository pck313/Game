#include "graphics.h"

//Khoi tao thu vien
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
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Tao cua so khong thanh cong. " << endl;
        SDL_Quit();
        return nullptr;
    }
    return window;
}

//Giai phong thu vien
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer); //Giai phong renderner
    SDL_DestroyWindow(window); //Giai phong cua so
    SDL_Quit(); //Giai phong SDL
}

//Tai hinh anh vao texture
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Load texture %s", IMG_GetError());
    }

	return texture;
}

//Khoi tao render de ve anh
SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "Khong hien thi duoc anh. " << endl;
    }
    return renderer;
}

//Hien thi anh voi toa do cu the
void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	dest.x = x;
	dest.y = y - dest.h;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

//Giu cho cua so khong bi dong
void waitWindowClosed()
{
    SDL_Event event; //Luu tru su kien
    bool quit = true;
    while (quit)
    {
        if (SDL_WaitEvent(&event)) //Dung den khi Quit SDL
        {
            if (event.type == SDL_QUIT)
            {
                quit = false;
            }
        }
    }
}

