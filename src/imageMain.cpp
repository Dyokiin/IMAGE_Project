#include <iostream>
#include <SDL2/SDL.h>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"
#include "../include/userI.h"
#include "../include/menus.h"



int main(int argc, char* argv[]){

    int currentMenu;

    SDL_Event event;
    bool quit = false;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Echec init SDL" << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Window* mainWin = NULL;
    mainWin = SDL_CreateWindow("IMAGE Project",SDL_WINDOWPOS_CENTERED,
                                                SDL_WINDOWPOS_CENTERED,
                                                1280, 720,
                                                SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer =NULL;
    renderer = SDL_CreateRenderer(mainWin, -1, 0);


    if(mainWin){

        currentMenu = 0;
        Ui* currentUi = new Ui();

        currentUi = mainMenu();

        std::string fps = "";
        Label *fpsl = new Label(fps, 10,10,20);

        while(!quit){
            Uint64 start = SDL_GetPerformanceCounter();
            SDL_WaitEvent(&event);

            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            
                case SDL_MOUSEBUTTONDOWN:
                    std::cout << currentUi->on_click() << std::endl;
                    switch (currentUi->on_click())
                    {
                        case 0:
                            if(currentMenu == 0){quit = true;}
                            else {
                                currentMenu--;
                                menuSwitch(currentMenu);
                            }
                            break;
                        case 1:
                            currentMenu++;
                            menuSwitch(currentMenu);
                            break;
                        
                        default:
                            gpgmMenu(currentUi->on_click());
                            break;
                    }
                    break;
            }


            currentUi->DrawUi(renderer);
            fpsl->DrawLabel(renderer);

            SDL_RenderPresent(renderer);
            SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		    SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);

            Uint64 end = SDL_GetPerformanceCounter();
            float elapsed = (end -start)/(float)SDL_GetPerformanceFrequency();
            fpsl->set_label(std::to_string(1.0/elapsed));
        }





        SDL_DestroyWindow(mainWin);
    } else {
        std::cout << "Echec window" << SDL_GetError() << std::endl;
    }



    SDL_Quit();
    return EXIT_SUCCESS;
}