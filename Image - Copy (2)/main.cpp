#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* initSDL(int width, int height, const char* title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) !=0) //Khoi tao SDL
    {
        cout << "Khoi tao SDL khong thanh cong. " << endl;
        return nullptr;
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) //SDL Image
    {
        cout << "Khoi tao SDL Image khong thanh cong. " << endl;
        SDL_Quit();
        return nullptr;
    }
    // Tao cua so SDL
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Tao cua so khong thanh cong. " << endl;
        SDL_Quit();
        return nullptr;
    }
    return window;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();
    SDL_DestroyRenderer(renderer); //Giai phong renderner
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Chuyen doi anh thanh Texture
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                     "Loading %s", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Load texture %s", IMG_GetError());
    }

	return texture;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "Khong hien thi duoc anh. " << endl;
    }
    return renderer;
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

//Hien thi anh voi toa do cu the
void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	dest.x = x;
	dest.y = y - dest.h;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}
int main(int argc, char *argv[])
{
    const int width = 1540;
    const int height = 850;
    const char* title = "DINO WINDOW";

    SDL_Window* window = initSDL(width, height, title); //Tao cua so sdl

    SDL_Renderer* renderer = createRenderer(window); //Tao renderner

    SDL_Texture* background = loadTexture("background.png", renderer); //Nap anh
    SDL_RenderCopy( renderer, background, NULL, NULL); //Hien thi anh len cua so

    SDL_Texture* sand = loadTexture("sand.png", renderer);
    renderTexture(sand, 0, 860, renderer);

    SDL_Texture* dino = loadTexture("dino.png", renderer);
    renderTexture(dino, 200, 800, renderer);

    SDL_Texture* cactus1 = loadTexture("cactus1.png", renderer);
    renderTexture(cactus1, 500, 800, renderer);

    SDL_RenderPresent(renderer); //Hien thi ban ve len man hinh
	
    SDL_DestroyTexture(background); //Giai phong bo nho texture ko dung den
    background = NULL; //De phong truong hop dung nham con tro da giai phong

    quitSDL(window, renderer); //Dong cua so va giai phong renderner

    return 0;
}
