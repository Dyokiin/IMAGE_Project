#ifndef __CREATE_OBJECT_H
#define __CREATE_OBJECT_H

#include "QuadTree.h"

extern unsigned int vertex_number;
extern float* vertex_coord;
extern float* normal_coord;
extern unsigned int triangle_number;
extern unsigned int* triangle_index;
extern QTree *qtree;

void createCoordinates();

#endif
