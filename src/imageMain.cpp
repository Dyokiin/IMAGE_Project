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
                                                1000, 1000,
                                                SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer =NULL;
    renderer = SDL_CreateRenderer(mainWin, -1, 0);

    if(mainWin){

        std::string tests = "Quitter";
        Button *test = new Button(tests, 400, 700);
        test->set_signal(1);

        std::string tests2 = "IMAGE Project";
        Label *test2 = new Label(tests2, 100,100, 100);

        ui menutest = (ui)malloc(sizeof(ui));
        add_label(menutest, test2);
        add_button(menutest, test);



        while(!quit){
            SDL_WaitEvent(&event);

            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if(test->is_clicked() == 1){
                    quit = true;
                }
                break;

            default:
                break;
            }

            test->DrawButton(renderer);
            test2->DrawLabel(renderer);
            //DrawUi(menutest, renderer);
            SDL_RenderPresent(renderer);
        }





        SDL_DestroyWindow(mainWin);
    } else {
        std::cout << "Echec window" << SDL_GetError() << std::endl;
    }



    SDL_Quit();
    return EXIT_SUCCESS;
}