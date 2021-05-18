#ifndef MENUS_H
#define MENUS_H

#include "userI.h"
#include <SDL2/SDL.h>

Ui* menuSwitch(int targetMenu);

Ui* mainMenu();
Ui* helpMenu();
Ui* gpgmMenu();
Ui* imagMain();


#endif