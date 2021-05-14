#include <iostream>
#include <SDL2/SDL.h>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"
#include "../include/userI.h"



int main(int argc, char* argv[]){

    SDL_Event event;
    bool quit = false;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Echec init SDL" << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Window* mainWin = NULL;
    mainWin = SDL_CreateWindow("IMAGE Project",SDL_WINDOWPOS_CENTERED,
                                                SDL_WINDOWPOS_CENTERED,
                                                500, 500,
                                                SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer =NULL;
    renderer = SDL_CreateRenderer(mainWin, -1, 0);

    if(mainWin){

        std::string tests = "Test";
        Label *test = new Label(tests, 50, 50);
        test->DrawLabel(renderer);

        while(!quit){
            SDL_WaitEvent(&event);

            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            
            default:
                break;
            }

            SDL_RenderPresent(renderer);
        }





        SDL_DestroyWindow(mainWin);
    } else {
        std::cout << "Echec window" << SDL_GetError() << std::endl;
    }



    SDL_Quit();
    return EXIT_SUCCESS;
}