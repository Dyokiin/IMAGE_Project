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
#include "../include/camera.h"

static float aspectRatio;
static float GL_VIEW_SIZE = 900.;

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

    //int currentMenu;

    // SDL_Rect rect;
    // rect.x = 64;
    // rect.y = 104;
    // rect.h = rect.w = 512;

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
    std::string pgmpath = std::string(p) + "../ressources/height_map1.pgm";
    PgmFile* pgm = new PgmFile(pgmpath);
    free(p);

    QTree* qtree = pgm->parse();

    onWindowResized(1280, 720);

    if(mainWin){

        //currentMenu = 0;
        //Ui* currentUi = new Ui();

        //currentUi = mainMenu();

        Camera *view = new Camera();

        while(!quit){

            Uint32 startTime = SDL_GetTicks();

            SDL_WaitEvent(&event);

            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                        onWindowResized(event.window.data1, event.window.data2);
                    }

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_z :
                            std::cout << "z" << std::endl;
                            view->UpdateCamera(1,0,0,0,0);
                        break;

                        case SDLK_s :
                            view->UpdateCamera(-1,0,0,0,0);
                        break;

                        case SDLK_q :
                            view->UpdateCamera(0,1,0,0,0);
                        break;

                        case SDLK_d :
                            view->UpdateCamera(0,-1,0,0,0);
                        break;

                        case SDLK_SPACE :
                            view->UpdateCamera(0,0,1,0,0);
                        break;

                        case SDLK_LCTRL :
                            view->UpdateCamera(0,0,-1,0,0);
                        break;

                        case SDLK_UP :
                            view->UpdateCamera(0,0,0,1,0);
                        break;

                        case SDLK_DOWN :
                            view->UpdateCamera(0,0,0,-1,0);
                        break;

                        case SDLK_LEFT :
                            view->UpdateCamera(0,0,0,0,1);
                        break;

                        case SDLK_RIGHT :
                            view->UpdateCamera(0,0,0,0,-1);
                        break;
                    }
            
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

            glBegin(GL_TRIANGLES);

            glClearColor(0,0,0,0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(atan(tan(50.0 * 3.14159 / 360.0) / 1.0) * 360.0 / 3.141593, 1.0, 3.0, 7.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0.0, 0.0, 100.0,
                      0.0, 0.0, 0.0,
                      0.0, 1.0, 0.0);

            //view->useCamera();


            glColor3f(1,1,1);
            
            qtree->display();


            //currentUi->DrawUi(renderer);
            glPopMatrix();

            SDL_GL_SwapWindow(mainWin);

            glEnd();

            Uint32 elaspedTime = SDL_GetTicks() - startTime;
            if(elaspedTime < 1000/60){SDL_Delay(1000/60 - elaspedTime);}
        }

        SDL_DestroyWindow(mainWin);
    } else {
        std::cout << "Echec window" << SDL_GetError() << std::endl;
    }

    SDL_GL_DeleteContext(context);
    SDL_Quit();
    return EXIT_SUCCESS;
}