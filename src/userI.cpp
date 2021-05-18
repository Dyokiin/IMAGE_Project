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

Label::Label(){
    this->label = "";
    this->posy = 0;
    this->posx = 0;
    this->size = BASESIZEFONT;
}

void Label::set_label(std::string new_label){
    this->label = new_label;
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
    SDL_Surface *surface = TTF_RenderText_Blended(font, this->label.c_str(), color);
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

int Label::get_size(){
    return this->size;
}

void Label::set_x(int x){
    this->posx = x;
}

void Label::set_y(int y){
    this->posy = y;
}

Button::Button(std::string label, int x, int y) : Label(label, x, y){
    this->maxy = y+57;
    this->maxx = x+label.length()*25+5;
}

Button::Button() : Label() {
    this->maxx = 0;
    this->maxy = 0;
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

int Button::get_signal(){
    return this->signal;
}

void Button::set_label(std::string label){
    this->label = label;
    this->maxx = this->posx+label.length()*25+5;
    this->maxy = this->posy+57;
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

Ui::Ui() : Button() {
    this->next = NULL;
}

Ui::Ui(Button *button) : Button(button->get_label(), button->get_x(), button->get_y()) {
    this->next = NULL;
    this->signal = button->get_signal();
}

Ui::Ui(Label *label) : Button(label->get_label(), label->get_x(), label->get_y()) {
    this->next = NULL;
    this->signal = -1;
    this->size = label->get_size();
}

Ui* Ui::get_next(){
    return this->next;
}

void Ui::set_next(Ui* element){
    this->next = element;
}

void Ui::add_button(Button* button){
    if(this->next == NULL){
        this->next = new Ui(button);
        return;
    }
    this->next->add_button(button);
}

void Ui::add_label(Label *label){
    if(this->next == NULL){
        this->next = new Ui(label);
        return;
    }
    this->next->add_label(label);
}

void Ui::DrawUi(SDL_Renderer *renderer){
    if(this->next != NULL){
        this->next->DrawUi(renderer);
    }
    if(this->signal == -1){
        this->DrawLabel(renderer);
    } else {
        this->DrawButton(renderer);
    }
}

int Ui::on_click(){
    if(this->is_clicked() != -1){
        return this->signal;
    } else if(this->next != NULL){
        return this->next->on_click();
    }
    return -1;
}