#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

SDL_Window* initSDL(int width, int height, const char* title)
{
    if (!SDL_Init(SDL_INIT_EVERYTHING)) //Khoi tao SDL
    {
        cout << "Khoi tao SDL khong thanh cong. ";
        return nullptr;
    }
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) //SDL Image
    {
        cout << "Khoi tao SDL Image khong thanh cong. ";
        SDL_Quit();
        return nullptr;
    }
    // Tao cua so SDL
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Tao cua so khong thanh cong. ";
        SDL_Quit();
        return nullptr;
    }
    return window;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();
    SDL_DestroyRenderer(renderer); //Giai phong
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//Chuyen doi anh thanh Texture
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)
{
    cout << "Loading " << endl;
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                     "Loading %s", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Load texture %s", IMG_GetError());
      }

	return texture;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cout << "Khong hien thi duoc anh. ";
    }
    return renderer;
}

int main(int argc, char *argv[])
{
    const int width = 1550;
    const int height = 700;
    const char* title = "SDL Window";

    SDL_Window* window = initSDL(width, height, title);

    SDL_Renderer* renderer = createRenderer(window); //Tao renderner

    SDL_Texture* background = loadTexture("anime-style-clouds (2).jpg", renderer); //Nap anh
    SDL_RenderCopy( renderer, background, NULL, NULL); //Hien thi anh len cua so

    SDL_RenderPresent( renderer ); //Hien thi ban ve len man hinh

    SDL_DestroyTexture( background );//Giai phong bo nho texture ko dung den
    background = NULL; //De phong truong hop dung nham con tro da giai phong

    quitSDL(window, renderer); //Dong cua so va giai phong renderner
    return 0;
}
