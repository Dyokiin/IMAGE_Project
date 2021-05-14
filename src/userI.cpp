#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include "../include/userI.h"


Label::Label(std::string label, int x, int y){
    this->label = label;
    this->posx = x;
    this->posy = y;
}

void Label::DrawLabel(SDL_Renderer *renderer){
    TTF_Init();
    TTF_Font *font = TTF_OpenFontIndex("Arialn.ttf", 10, 10);
    if(!font){std::cout << TTF_GetError() << std::endl;}
    SDL_Color color = {255,255,255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, this->label.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int textW = 1;
    int textH = 1;

    SDL_QueryTexture(texture, NULL, NULL, &textW, &textH);
    SDL_Rect lrect = {0,0,textW,textH};
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
    this->maxy = y+35;
    this->maxx = x+label.length()*20;
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

void Button::DrawButton(SDL_Renderer *renderer){
    this->DrawLabel(renderer);
}

Ui::Ui(){}

void Ui::add(Label* label){
    int i=0;
    while(this->text[i] != NULL){
        i++;
    }
    this->text[i] = new Label(label->get_label(), label->get_x(), label->get_y());
}

void Ui::add(Button* button){
    int i=0;
    while(this->menu[i] != NULL){
        i++;
    }
    this->menu[i] = new Button(button->get_label(), button->get_x(), button->get_y());
}

void Ui::DrawUi(SDL_Renderer *renderer){
    for(int i=0; i<5; i++){
        if(this->menu[i] != NULL){
            this->menu[i]->DrawButton(renderer);
        }
        if(this->text[i] != NULL){
            this->text[i]->DrawLabel(renderer);
        }
    }
}