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
        return gpgmMenu(0);
    case 2:
        return helpMenu();
    case 3:
        return imagMain();
    default:
        return mainMenu();
    }
}

Ui* mainMenu(){
    std::string Title = "IMAGE Project";
    Label *MainTitle = new Label(Title, 383, 200, 60);

    std::string quit = "Quit";
    Button *QuitButton = new Button(quit, 597, 460);
    QuitButton->set_signal(0);

    std::string start = "Start";
    Button *StartButton = new Button(start, 583, 400);
    StartButton->set_signal(1);

    Ui* MainMenu = new Ui();
    MainMenu->add_label(MainTitle);
    MainMenu->add_button(QuitButton);
    MainMenu->add_button(StartButton);

    return MainMenu;
}

Ui* helpMenu(){
    return NULL;
}

Ui* gpgmMenu(int signal){
    return NULL;
}

Ui* imagMain(){
    return NULL;
}