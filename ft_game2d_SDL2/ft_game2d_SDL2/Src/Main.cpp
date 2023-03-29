#include "Game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("fttest_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

    while (game->running()) {
        frameStart = SDL_GetTicks();


        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}

/*#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* flower = NULL;

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Can't init video: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags)) {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return false;
    }

    win = SDL_CreateWindow("Растяжка PNG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        std::cout << "Can't create window: " << SDL_GetError() << std::endl;
        return false;
    }

    scr = SDL_GetWindowSurface(win);

    return true;
}

bool load() {
    Class SDsd;

    flower = IMG_Load("flower.png");
    if (flower == NULL) {
        std::cout << "Can't load: " << IMG_GetError() << std::endl;
        return false;
    }

    flower = SDL_ConvertSurface(flower, scr->format, NULL);
    if (flower == NULL) {
        std::cout << "Can't convert: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void quit() {
    SDL_FreeSurface(flower);

    SDL_FreeSurface(scr);
    SDL_DestroyWindow(win);

    SDL_Quit();
    IMG_Quit();
}

int main(int argc, char** args) {
    if (!init()) {
        system("pause");
        quit();
        return 1;
    }

    if (!load()) {
        system("pause");
        quit();
        return 1;
    }

    SDL_Rect bg_flower;
    bg_flower.w = 30;
    bg_flower.h = 30;
    bg_flower.x = 0;
    bg_flower.y = 0;
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < 41; j++) {
            bg_flower.x += 30;
            SDL_BlitScaled(flower, NULL, scr, &bg_flower);
        }
        bg_flower.x = 0;
        bg_flower.y += 30;
    }
    

    SDL_UpdateWindowSurface(win);

    SDL_Delay(10000);

    quit();

    return 0;
};*/
/*
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* john = NULL;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Can't init: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    win = SDL_CreateWindow("События", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        std::cout << "Can't create window: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    scr = SDL_GetWindowSurface(win);

    return 0;
}

int load() {
    john = SDL_LoadBMP("john.bmp");

    if (john == NULL) {
        std::cout << "Can't load image: " << SDL_GetError() << std::endl;
        system("pause");
        return 1;
    }

    return 0;
}

int quit() {
    SDL_FreeSurface(john);

    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}
int main(int argc, char** args) {
    if (init() == 1) {
        return 1;

    }

    if (load() == 1) {
        return 1;
    }

    bool run = true;
    SDL_Event e;
    SDL_Rect r;

    int x = 0;
    int y = 0;

    r.x = x;
    r.y = y;

    while (run) {
        while (SDL_PollEvent(&e) != NULL) {
            if (e.type == SDL_QUIT) {
                run = false;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    y -= 1;
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    y += 1;
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    x += 1;
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    x -= 1;
                }
            }
        }
        r.x = x;
        r.y = y;

        SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 255, 255, 255));

        SDL_BlitSurface(john, NULL, scr, &r);

        SDL_UpdateWindowSurface(win);
    }

    return quit();
}*/