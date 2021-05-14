#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Label {
protected:
    std::string label;
    int posx;
    int posy;
public:
    Label(std::string label, int x, int y);
    void DrawLabel(SDL_Renderer *renderer);
    std::string get_label();
    int get_x();
    int get_y();
};

class Button : public Label {
protected:
    int maxx;
    int maxy;
    int signal;
public:
    Button(std::string label, int x, int y);
    bool is_hovered();
    int is_clicked();
    void DrawButton(SDL_Renderer *renderer);
};

class Ui {
protected:
    Label *text[8];
    Button *menu[8];
public:
    Ui();
    void add(Label* Label);
    void add(Button* Button);
    void DrawUi(SDL_Renderer *renderer);
};



#endif