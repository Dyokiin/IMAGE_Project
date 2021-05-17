#include <iostream>
#include <SDL2/SDL.h>
#include "../include/userI.h"
#include "../include/ImgFile.h"
#include "../include/QuadTree.h"
#include "../include/menus.h"

Ui* menuSwitch(int targetMenu){
    switch (targetMenu)
    {
    case 0:
        return mainMenu();
    case 1:
        return gpgmMenu();
    case 2:
        return imagMain();
    case 3:
        return helpMenu();
    default:
        return mainMenu();
    }
}

Ui* mainMenu(){
    std::string Title = "IMAGE Project";
    Label *MainTitle = new Label(Title, 383, 200, 60);

    std::string Name1 = "Theo Arnauld Des Lions";
    std::string Name2 = "Clement Bourhis";
    std::string Name3 = "Leo Delplanque";
    Label *LName1 = new Label(Name1, 1280-22*12, 630, 20);
    Label *LName2 = new Label(Name2, 1280-15*12, 660, 20);
    Label *LName3 = new Label(Name3, 1280-14*12, 690, 20);

    std::string quit = "Quit";
    Button *QuitButton = new Button(quit, 597, 460);
    QuitButton->set_signal(0);

    std::string start = "Start";
    Button *StartButton = new Button(start, 583, 400);
    StartButton->set_signal(1);

    Ui* MainMenu = new Ui(QuitButton);

    MainMenu->add_button(StartButton);
    MainMenu->add_label(MainTitle);
    MainMenu->add_label(LName1);
    MainMenu->add_label(LName2);
    MainMenu->add_label(LName3);

    return MainMenu;
}

Ui* gpgmMenu(){
    std::string prev = "Previous";
    std::string next = "Next";
    Button *Quit = new Button(prev, 30 ,640);
    Button *Next = new Button(next, 1280-4*25-30, 640);

    Quit->set_signal(0);
    Next->set_signal(1);

    std::string s064 = "64  x  64";
    std::string s128 = "128 x 128";
    std::string s256 = "256 x 256";
    std::string s512 = "512 x 512";
    Button *b064 = new Button(s064,1088-3*25,260);
    Button *b128 = new Button(s128,1088-3*25,320);
    Button *b256 = new Button(s256,1088-3*25,380);
    Button *b512 = new Button(s512,1088-3*25,440);
    b064->set_signal(2);
    b128->set_signal(3);
    b256->set_signal(4);
    b512->set_signal(5);

    std::string random = "Random";
    std::string perlin = "Perlin";
    Button *brand = new Button(random,830-3*25,260);
    Button *bperl = new Button(perlin,830-3*25,320);
    brand->set_signal(6);
    bperl->set_signal(7);

    std::string column1 = "Modes";
    std::string column2 = "Sizes";
    std::string hint = "Heightmap Options";
    Label *L1 = new Label(hint, 960-9*20, 60, 30);
    Label *L2 = new Label(column2, 1088-3*25, 110, 40);
    Label *L3 = new Label(column1, 830-3*25, 110, 40);

    Ui* GpgmMenu = new Ui(Quit);

    GpgmMenu->add_button(Next);
    GpgmMenu->add_button(b064);
    GpgmMenu->add_button(b128);
    GpgmMenu->add_button(b256);
    GpgmMenu->add_button(b512);
    GpgmMenu->add_button(brand);
    GpgmMenu->add_button(bperl);
    GpgmMenu->add_label(L1);
    GpgmMenu->add_label(L2);
    GpgmMenu->add_label(L3);

    return GpgmMenu;
}


Ui* imagMain(){
    std::string prev = "Previous";
    std::string next = "Help";
    Button *Quit = new Button(prev, 30 ,640);
    Button *Next = new Button(next, 1280-4*25-30, 640);

    Quit->set_signal(0);
    Next->set_signal(1);

    Ui* imagMenu = new Ui(Quit);

    imagMenu->add_button(Next);

    return imagMenu;
}

Ui* helpMenu(){
    std::string prev = "Previous";
    Button *Quit = new Button(prev, 30 ,640);

    Quit->set_signal(0);

    std::string help1 = "z : turn camera up";
    std::string help2 = "s : turn camera down";
    std::string help3 = "q : turn camera left";
    std::string help4 = "d : turn camera right";
    std::string help5 = "space : go forward";
    std::string help6 = "Lalt : go backward";
    std::string help7 = "Lmaj : go up";
    std::string help8 = "Lctrl : go down";

    Label *Lh1 = new Label(help1, 320, 140);
    Label *Lh2 = new Label(help2, 320, 200);
    Label *Lh3 = new Label(help3, 320, 260);
    Label *Lh4 = new Label(help4, 320, 320);
    Label *Lh5 = new Label(help5, 320, 380);
    Label *Lh6 = new Label(help6, 320, 440);
    Label *Lh7 = new Label(help7, 320, 500);
    Label *Lh8 = new Label(help8, 320, 560);

    Ui* HelpMenu = new Ui(Quit);
    HelpMenu->add_label(Lh1);
    HelpMenu->add_label(Lh2);
    HelpMenu->add_label(Lh3);
    HelpMenu->add_label(Lh4);
    HelpMenu->add_label(Lh5);
    HelpMenu->add_label(Lh6);
    HelpMenu->add_label(Lh7);
    HelpMenu->add_label(Lh8);

    return HelpMenu;
}