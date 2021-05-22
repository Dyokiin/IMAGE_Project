#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/QuadTree.h"
#include "../include/ImgFile.h"
#include "../include/userI.h"
#include "../include/menus.h"
#include "../include/ImgGen.h"

static float aspectRatio;
static const float GL_VIEW_SIZE = 16.;

void onWindowResized(unsigned int width, unsigned int height)
{ 
    aspectRatio = width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) 
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio, 
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
    }
    else
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
        -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
    }
}

int main(int argc, char* argv[]){

    int currentMenu;

    SDL_Rect rect;
    rect.x = 64;
    rect.y = 104;
    rect.h = rect.w = 512;

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


    SDL_GLContext context;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    context = SDL_GL_CreateContext(mainWin);

    
    char *p = SDL_GetBasePath();
    std::string pgmpath = std::string(p) + "../ressources/height_map2.pgm";
    PgmFile* pgm = new PgmFile(pgmpath);
    free(p);

    int hi;

    QTree* qtree = pgm->parse();
    std::cout << qtree->get_area().x1 << ", " << qtree->get_area().y1 << " : " << qtree->get_area().x2 << ", " << qtree->get_area().y2 << std::endl;
    for(int i = 0; i< 4; i++){

        for(int j = 0; j < 4; j++){

            if(qtree->search(QTNodePosMake(j, i)) != NULL){
                hi = qtree->search(QTNodePosMake(j, i))->height;
                if(hi<10){std::cout << "  " << hi << " ";}
                else if(hi<100){std::cout << " " << hi << " ";}
                else {std::cout << hi << " ";}
            } else {
                std::cout << "error" << " ";
            }
        }

        std::cout << std::endl;
    }


    onWindowResized(1280, 720);

    if(mainWin){

        currentMenu = 0;
        Ui* currentUi = new Ui();

        currentUi = mainMenu();

        while(!quit){

            SDL_WaitEvent(&event);

            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
            
                // case SDL_MOUSEBUTTONDOWN:
                //     switch (currentUi->on_click())
                //     {
                //         case 0:
                //             if(currentMenu == 0){quit = true;}
                //             else {
                //                 currentMenu--;
                //                 currentUi = menuSwitch(currentMenu);
                //             }
                //             break;
                //         case 1:
                //             currentMenu++;
                //             currentUi = menuSwitch(currentMenu);
                //             break;
                        
                //         default:
                //             //currentUi->on_click();
                //             break;
                //     }
                //     break;
            }

            glClearColor(0,0,0,0);
            glClear(GL_COLOR_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glPointSize(7);

            // glBegin(GL_LINES);
		    //     glColor3f(1.,0.,0.);
		    //     glVertex3f(0.,0.,0.);
		    //     glVertex3f(1,0.,0.);
		    //     glColor3f(0.,1.,0.);
		    //     glVertex3i(0.,0.,0.);
		    //     glVertex3i(0.,1,0.);
		    //     glColor3f(0.,0.,1.);
		    //     glVertex3i(0.,0.,0.);
		    //     glVertex3i(0.,0.,1);
	        // glEnd();

            glBegin(GL_LINE_STRIP);

                glColor3f(1,1,1);
            
                qtree->display();


            //currentUi->DrawUi(renderer);

            glEnd();

            glViewport(0,0,1280,720);

            SDL_GL_SwapWindow(mainWin);

            SDL_Delay(30);
        }

        SDL_DestroyWindow(mainWin);
    } else {
        std::cout << "Echec window" << SDL_GetError() << std::endl;
    }

    SDL_GL_DeleteContext(context);
    SDL_Quit();
    return EXIT_SUCCESS;
}