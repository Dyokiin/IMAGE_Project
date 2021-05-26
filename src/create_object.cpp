#include "../include/create_object.h"
#include "../include/QuadTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <iostream>

unsigned int vertex_number;
float* vertex_coord;
float* normal_coord;
unsigned int triangle_number;
unsigned int* triangle_index;
QTree* qtree;

void createCoordinates() {

    char *p = SDL_GetBasePath();
    std::string pgmpath = std::string(p) + "../ressources/height_map1.pgm";
    PgmFile* pgm = new PgmFile(pgmpath);
    free(p);

    qtree = pgm->parse();

	int x = qtree->get_area().x2;
	int y = qtree->get_area().y2;

	int index = 0;


	// Vous devez fixer :
	// - le nombre de sommets (vertex_number)
	// - le tableau des coordonnees des sommets (vertex_coord)
	// - le tableau des coordonnees des normales (normal_coord)
	// - le nombre de triangles (triangle_number)
	// - le tableau des indices des sommets constituant les triangles (triangle_index)

	vertex_number = x * y ; // A CHANGER
	triangle_number = (2*x - 2) * (y-1); // A CHANGER
	
	vertex_coord = (float*) calloc(sizeof(float),3*vertex_number);
	normal_coord = (float*) calloc(sizeof(float),3*vertex_number);
	triangle_index = (unsigned int*) calloc(sizeof(unsigned int),3*triangle_number);
	
	// CONSTRUIRE LES TABLEAUX

	for(int i=0; i<=x; i++){
        for(int j=0; j<=y; j++){
			vertex_coord[index] = x;
			vertex_coord[index+1] = y;
			vertex_coord[index+2] = qtree->search(QTNodePosMake(x,y))->height;

			index+=3;
        }
    }
}