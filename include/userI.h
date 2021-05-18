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
    Label();
    Label(std::string label, int x, int y);
    Label(std::string label, int x, int y, int size);
    void DrawLabel(SDL_Renderer *renderer);
    void set_label(std::string new_label);
    std::string get_label();
    void set_x(int x);
    void set_y(int y);
    int get_x();
    int get_y();
    int get_size();
};

class Button : public Label {
protected:
    int maxx;
    int maxy;
    int signal;
public:
    Button(std::string label, int x, int y);
    Button();
    bool is_hovered();
    int is_clicked();
    void set_label(std::string label);
    void set_signal(int signal);
    int get_signal();
    void DrawButton(SDL_Renderer *renderer);
};

class Ui : public Button {
protected:
    Ui *next;
public:
    Ui();
    Ui(Button *button);
    Ui(Label *label);
    Ui* get_next();
    void set_next(Ui* element);
    void DrawUi(SDL_Renderer *renderer);
    void add_button(Button *button);
    void add_label(Label *label);
    int on_click();
};


#endif