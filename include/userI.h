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
    int size;
public:
    Label(std::string label, int x, int y);
    Label(std::string label, int x, int y, int size);
    void DrawLabel(SDL_Renderer *renderer);
    void set_label(std::string new_label);
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
    void set_signal(int signal);
    void DrawButton(SDL_Renderer *renderer);
};

typedef struct Ui_element {
    Label *label;
    Button *button;
    Ui_element *next;
} element, *ui ;

void add_label(ui menu, Label *label);
void add_button(ui menu, Button *Button);
void DrawUi(ui menu, SDL_Renderer *renderer);


#endif