#include <iostream>
#include <SDL2/SDL.h>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"
#include "../include/userI.h"



int main(int argc, char* argv[]){


    QTree *center = new QTree(QTCornersMake(0,0,8,8));
    QTNode a(QTNodePosMake(1,1), 1);
    QTNode b(QTNodePosMake(2,5), 2);
    QTNode c(QTNodePosMake(7,6), 3);
    center->insert(&a);
    center->insert(&b);
    center->insert(&c);

    std::cout << "Node a: " << center->search(QTNodePosMake(1,1)) << std::endl;
    std::cout << "Node b: " << center->search(QTNodePosMake(2,5)) << std::endl;
    std::cout << "Node c: " << center->search(QTNodePosMake(7,6)) << std::endl;


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
            }




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