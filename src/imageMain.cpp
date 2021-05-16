#include <iostream>
#include <SDL2/SDL.h>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"
#include "../include/userI.h"



int main(int argc, char* argv[]){

    // QTree *center = new QTree(QTCornersMake(1,1,8,8));

    // for(int i=0; i<=8;i++){
    //     for(int j=0;j<=8;j++){
    //         QTNode *a = new QTNode(QTNodePosMake(i,j), i*j);
    //         center->insert(a);
    //     }
    // }

    // for(int i=1; i<=8;i++){
    //     for(int j=1;j<=8;j++){
    //         std::cout << "Node in pos : (" << i << "," << j << ") = " << center->search(QTNodePosMake(i,j)) << std::endl;
    //     }
    // }


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