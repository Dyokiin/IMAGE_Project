#ifndef __VISU_CM_H
#define __VISU_CM_H

#define STEP_ANGLE	M_PI/90.
#define STEP_PROF	M_PI/90.

class QTNode;

/* variables globales pour la gestion de la caméra */
extern float profondeur;
extern float latitude;
extern float longitude;
extern float offx;
extern float offy;
extern float offz;

void drawtriangle(QTNode *n1, QTNode *n2, QTNode *n3);

#endif
