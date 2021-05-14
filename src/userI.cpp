#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "../include/userI.h"

#define BASESIZEFONT 40


Label::Label(std::string label, int x, int y){
    this->label = label;
    this->posx = x;
    this->posy = y;
    this->size = BASESIZEFONT;
}

Label::Label(std::string label, int x, int y, int size){
    this->label = label;
    this->posx = x;
    this->posy = y;
    this->size = size;
}

void Label::DrawLabel(SDL_Renderer *renderer){

    char *p = SDL_GetBasePath();
    std::string ttfpath = std::string(p) + "unispace rg.ttf";
    SDL_free(p);
    Uint8 r = 0;
    Uint8 g = 0;
    Uint8 b = 0;
    Uint8 a = 0;
    SDL_GetRenderDrawColor(renderer,&r,&g,&b,&a);

    TTF_Init();
    TTF_Font *font = TTF_OpenFont(ttfpath.c_str(), this->size);
    SDL_Color color = {r,g,b,a};
    SDL_Surface *surface = TTF_RenderText_Solid(font, this->label.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int textW = 5;
    int textH = 5;

    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    SDL_Rect lrect = {this->posx,this->posy,textW,textH};
    SDL_RenderCopy(renderer, texture, NULL, &lrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
}

std::string Label::get_label(){
    return this->label ;
}

int Label::get_x(){
    return this->posx;
}

int Label::get_y(){
    return this->posy;
}

Button::Button(std::string label, int x, int y) : Label(label, x, y){
    this->maxy = y+57;
    this->maxx = x+label.length()*25+5;
    this->size = BASESIZEFONT;
}

bool Button::is_hovered(){
    int x,y;
    SDL_GetMouseState(&x,&y);
    return( x>=this->posx && x<=maxx
        &&  y>=this->posy && y<=this->maxy);
}

int Button::is_clicked(){
    if(this->is_hovered()){
        return this->signal;
    }
    return -1;
}

void Button::set_signal(int signal){
    this->signal = signal;
}

void Button::DrawButton(SDL_Renderer *renderer){

    if(this->is_hovered()){
        SDL_SetRenderDrawColor(renderer, 155,155,155,255);    
    }

    this->DrawLabel(renderer);

    SDL_Rect rect;
    rect.x = this->posx-5;
    rect.y = this->posy-5;
    rect.h = this->maxy - this->posy;
    rect.w = this->maxx - this->posx;

    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
}

void add_button(ui menu, Button *button){
    element* temp = menu;
    while(temp->next != NULL){
        temp = temp->next;
    }
    element *next = (element*)malloc(sizeof(element));
    next->button = button;
    next->label = NULL;
    next->next = NULL;
    temp->next = next;
}

void add_label(ui menu, Label *label){
    element* temp = menu;
    while(temp->next != NULL){
        temp = temp->next;
    }

    element *next = (element*)malloc(sizeof(element));
    next->label = label;
    next->button = NULL;
    next->next = NULL;
    temp->next = next;
}

void DrawUi(ui menu, SDL_Renderer *renderer){
    element* temp = menu;
    while(temp->next != NULL){
        if(temp->button != NULL){temp->button->DrawButton(renderer);}
        if(temp->label != NULL){temp->label->DrawLabel(renderer);}
        
        temp = temp->next;
    }
}
