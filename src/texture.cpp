#include <SDL/SDL_image.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>
#include "../include/texture.h"
#include "../include/visu.h"

Skybox::Skybox(){
    front = 0;
    left = 0;
    back = 0;
    right = 0;
    top = 0;
    bot = 0;
}

//Dessine la Skybox
void Skybox::Display() {
    glEnable(GL_TEXTURE_2D);
    
    float l = 450;
    glColor3f(120, 120, 120);

    glBindTexture(GL_TEXTURE_2D, front);
    glBegin(GL_QUADS);
       
        glTexCoord2f(0.,1.); glVertex3f(-l+offx , l+offy, -l+offz);
        glTexCoord2f(0.,0.); glVertex3f(-l+offx , l+offy, l+offz);
        glTexCoord2f(1.,0.); glVertex3f(-l+offx , -l+offy, l+offz);
        glTexCoord2f(1.,1.); glVertex3f(-l+offx , -l+offy, -l+offz);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, top);
    glBegin(GL_QUADS);
        
        glTexCoord2f(1.,1.); glVertex3f(-l+offx , l+offy, -l+offz);
        glTexCoord2f(1.,0.); glVertex3f(-l+offx , l+offy, l+offz);
        glTexCoord2f(0.,0.); glVertex3f(l+offx, l+offy, l+offz);
        glTexCoord2f(0.,1.); glVertex3f(l+offx , l+offy, -l+offz);
    glEnd();

glBindTexture(GL_TEXTURE_2D, back);
    glBegin(GL_QUADS);
        
        glTexCoord2f(1.,1.); glVertex3f(l+offx , -l+offy, -l+offz);
        glTexCoord2f(1.,0.); glVertex3f(l+offx , -l+offy, l+offz);
        glTexCoord2f(0.,0.); glVertex3f(l+offx , l+offy, l+offz);
        glTexCoord2f(0.,1.); glVertex3f(l+offx , l+offy, -l+offz);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, bot);
    glBegin(GL_QUADS);
        
        glTexCoord2f(1.,1.); glVertex3f(l+offx , -l+offy, -l+offz);
        glTexCoord2f(1.,0.); glVertex3f(l+offx , -l+offy, l+offz);
        glTexCoord2f(0.,0.); glVertex3f(-l+offx , -l+offy, l+offz);
        glTexCoord2f(0.,1.); glVertex3f(-l+offx , -l+offy, -l+offz);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, right);
    glBegin(GL_QUADS);
        
        glTexCoord2f(0.,0.); glVertex3f(-l+offx , -l+offy, -l+offz);
        glTexCoord2f(1.,0.); glVertex3f(-l+offx , l+offy, -l+offz);
        glTexCoord2f(1.,1.); glVertex3f(l+offx, l+offy, -l+offz);
        glTexCoord2f(0.,1.); glVertex3f(l+offx , -l+offy, -l+offz);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, left);
    glBegin(GL_QUADS);
        glTexCoord2f(0.,0.); glVertex3f(-l+offx , -l+offy, l+offz);
        glTexCoord2f(1.,0.); glVertex3f(-l+offx , l+offy, l+offz);
        glTexCoord2f(1.,1.); glVertex3f(l+offx, l+offy, l+offz);
        glTexCoord2f(0.,1.); glVertex3f(l+offx , -l+offy, l+offz);
    glEnd();
    

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);   
    glEnd();
}


void Skybox::Bind(){
    IMG_Init(IMG_INIT_JPG);

    SDL_Surface* image = IMG_Load("./ressources/front.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &front);
    glBindTexture(GL_TEXTURE_2D, front);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);
    image = IMG_Load("./ressources/left.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &left);
    glBindTexture(GL_TEXTURE_2D, left);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);
    image = IMG_Load("./ressources/behind.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &back);
    glBindTexture(GL_TEXTURE_2D, back);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);
    image = IMG_Load("./ressources/right.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &right);
    glBindTexture(GL_TEXTURE_2D, right);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);
    image = IMG_Load("./ressources/above.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &top);
    glBindTexture(GL_TEXTURE_2D, top);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);
    image = IMG_Load("./ressources/below.jpg");
    if(!image){
        printf("%s\n", IMG_GetError());
    }else{
    glGenTextures(1, &bot);
    glBindTexture(GL_TEXTURE_2D, bot);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
    }
    SDL_FreeSurface(image);

    IMG_Quit();
   
}