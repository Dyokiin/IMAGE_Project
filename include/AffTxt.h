
#ifndef AFFTXT_H
#define AFFTXT_H
#include <SDL2/SDL.h>


void AffL(int n, float taille, int x, int y, SDL_Renderer* ren);
int AffTxt(std::string mot, float taille, int x, int y, SDL_Renderer* ren);
void AffChfr(int chiffre, float taille, int x, int y, SDL_Renderer* ren);
int AffNb(int nb, float taille, int x, int y, SDL_Renderer* ren);
void DrawBot(int x, int y, SDL_Renderer* ren);

#endif 