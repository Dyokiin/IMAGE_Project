/************************************************************
 * Réutilisation d'une lib écrite au S1 pour remplacer      *
 * SDL2.ttf                                                 *
 * Cette lib peut être améliorée clairement                 *
 ***********************************************************/



#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

#define H_MIN 3
#define L_MIN 25


/* Affiche la lettre n de l'alphabet */
void AffL(int n, float taille, int x, int y, SDL_Renderer* ren){

	SDL_Rect rect;

	switch (n) {
		case 1:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN)/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 2:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN)/1.5;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =(L_MIN*taille)/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.5;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/1.5;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 3:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 4:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.5;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.5;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/1.5;
			rect.y =y+3*taille;
			rect.h =L_MIN*taille-3*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 5:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN/2 *taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN/1.5*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 6:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.5;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 7:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y+L_MIN*taille/2;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/1.75;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2;
			rect.w =L_MIN*taille/1.75;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 8:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN)/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 9:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN);
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN)/2;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 10:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN);
			rect.w =L_MIN*taille/2;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN)/2;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 11:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille+H_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/2.25;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y+H_MIN*taille*2+L_MIN*taille/2;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+H_MIN*taille;
			rect.y =y+(taille*L_MIN)/2+H_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.15;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 12:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 13:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y;
			rect.h =L_MIN*taille/1.75;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 14:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 15:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 16:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =(L_MIN*taille)/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 17:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/1.25;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 18:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =(L_MIN*taille)/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN)/1.50;
			rect.y =y+(taille*L_MIN)/2;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/1.75;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 19:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.5;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/1.5;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 20:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN)/2;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 21:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 22:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+H_MIN*taille;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille/1.25;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/1.25;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 23:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2	;
			rect.h =L_MIN*taille/1.75;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 24:
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+H_MIN*taille*2+L_MIN*taille/2;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/2.25;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y+H_MIN*taille*2+L_MIN*taille/2;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+H_MIN*taille;
			rect.y =y+(taille*L_MIN)/2+H_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/1.15;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 25:
			rect.x =x;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.w =L_MIN*taille;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/1.50;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 26:
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/1.75;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2+H_MIN*taille;
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille/1.75;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.w =L_MIN*taille/1.10;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+H_MIN*taille*2;
			rect.y =y+L_MIN*taille;
			rect.w =L_MIN*taille/1.10;
			rect.h =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		default:
			break;
	}
}


/* Affiche grace à la fonction précédente un char passé en paramètre */
int AffTxt(std::string mot, float taille, int x, int y, SDL_Renderer* ren){

	int xi = x;
	for(int j=0; j<=mot.size(); j++){
		AffL((int)mot[j]-96, taille, xi, y, ren);
		xi += 30*taille; }
	return xi;
}


/* Affiche le chiffre passé en paramètre */		
void AffChfr(int chiffre, float taille, int x, int y, SDL_Renderer* ren){

	SDL_Rect rect;

	switch (chiffre) {
		case 0:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN);
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 1:
			rect.x =x;
			rect.y =y+(taille*L_MIN);
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN/2;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/2;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 2:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 3:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille/2;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille/2;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 4: 
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 5:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 6: 
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y+L_MIN*taille/2;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 7:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 8:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+(taille*L_MIN);
			rect.y =y;
			rect.w =H_MIN*taille;
			rect.h =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+(taille*L_MIN);
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			
			break;
		case 9:
			rect.x =x;
			rect.y =y;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y;
			rect.h =L_MIN*taille/2;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille/2;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x+L_MIN*taille;
			rect.y =y;
			rect.h =L_MIN*taille;
			rect.w =H_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			rect.x =x;
			rect.y =y+L_MIN*taille;
			rect.h =H_MIN*taille;
			rect.w =L_MIN*taille;
			SDL_RenderFillRect(ren, &rect);
			break;
		default:
			break;
	}
}


/* Affiche un nombre passé en paramètres grâce à la fonction précédente */
int AffNb(int nb, float taille, int x, int y, SDL_Renderer* ren){
	int xi = x;
	int n = 100;
	for(int j=0; j<=2; j++){
		AffChfr(nb/n%10, taille, xi, y, ren);
		xi += 30*taille;
		if (n>=10) n = n/10; }
	return xi;
}


/* Dessine Roboto */
void DrawBot(int x, int y, SDL_Renderer* ren){
	SDL_Rect bot;
	
	bot.x = x+5;
	bot.y = y+5;
	bot.h = 40;
	bot.w = 40;
	SDL_RenderDrawRect(ren, &bot);
	bot.x = x;
	bot.y = y+10;
	bot.h = 20;
	bot.w = 5;
	SDL_RenderFillRect(ren, &bot);
	bot.x = x+45;
	SDL_RenderFillRect(ren, &bot);
	bot.x = x + 10;
	bot.y = y + 35;
	bot.h = 5;
	bot.w = 30;
	SDL_RenderFillRect(ren, &bot);
	bot.y = y + 15;
	bot.h = 10;
	bot.w = 10;
	SDL_RenderFillRect(ren, &bot);
	bot.x = x + 30;
	SDL_RenderFillRect(ren, &bot);
}
