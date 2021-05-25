/* *******************************************************/
/* Exemple de programme OpenGL / GLUT           (C) 2010 */
/* Venceslas Biri   Université Paris Est Marne La Vallée */
/* *******************************************************/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/glbiri.h"
#include "../include/QuadTree.h"



/* variables globales pour la gestion de la caméra */
float profondeur = 3;
float latitude = 0.0;
float longitude = M_PI/2.;

float obj_rot = 0.0;

unsigned int vertex_number;
float* vertex_coord;
float* normal_coord;
unsigned int triangle_number;
unsigned int* triangle_index;

void createCoordinates() {
	// Vous devez fixer :
	// - le nombre de sommets (vertex_number)
	// - le tableau des coordonnees des sommets (vertex_coord)
	// - le tableau des coordonnees des normales (normal_coord)
	// - le nombre de triangles (triangle_number)
	// - le tableau des indices des sommets constituant les triangles (triangle_index)
	// CUBE
	vertex_number = 0; // A CHANGER
	triangle_number = 0; // A CHANGER
	
	vertex_coord = (float*) calloc(sizeof(float),3*vertex_number);
	normal_coord = (float*) calloc(sizeof(float),3*vertex_number);
	triangle_index = (unsigned int*) calloc(sizeof(unsigned int),3*triangle_number);
	
	// CONSTRUIRE LES TABLEAUX
}

/*********************************************************/
/* fonction de dessin de la scène à l'écran              */
void drawFunc(QTree *qtree) { 
	/* reinitialisation des buffers : couleur et ZBuffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* modification de la matrice de la scène */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Debut du dessin de la scène */
	glPushMatrix();
	
	/* placement de la caméra */
	gluLookAt(profondeur*sin(longitude)*sin(latitude),profondeur*cos(latitude),profondeur*cos(longitude)*sin(latitude)+5,
              0.0,0.0,0.0,
              0.0,1.0,0.0);

	glColor3f(1.0,0.0,0.0);

    glColor3f(1.,0.,0.);
    glVertex3f(0.,0.,0.);
    glVertex3f(2,0.,0.);
    glColor3f(0.,1.,0.);
    glVertex3i(0.,0.,0.);
    glVertex3i(0.,2,0.);
    glColor3f(0.,0.,1.);
    glVertex3i(0.,0.,0.);
    glVertex3i(0.,0.,2);

    
    qtree->display();



	/* Fin du dessin */
	glPopMatrix();

	/* fin de la définition de la scène */


	/* changement de buffer d'affichage */

}

/*********************************************************/
/* fonction de changement de dimension de la fenetre     */
/* paramètres :                                          */
/* - width : largeur (x) de la zone de visualisation     */
/* - height : hauteur (y) de la zone de visualisation    */
void reshapeFunc(int width,int height) {
	GLfloat  h = (GLfloat) width / (GLfloat) height ;
	
	/* dimension de l'écran GL */
	glViewport(0, 0, (GLint)width, (GLint)height);
	/* construction de la matrice de projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* définition de la camera */
	gluPerspective( 60.0, h, 0.01, 10.0 );			// Angle de vue, rapport largeur/hauteur, near, far

	/* Retour a la pile de matrice Modelview
			et effacement de celle-ci */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


/*********************************************************/
/* fonction d'initialisation des paramètres de rendu et  */
/* des objets de la scènes.                              */
void init() {
	profondeur = 3;
	latitude = M_PI/2.0;
	longitude = 0.0;

	obj_rot = 0.0;

	/* INITIALISATION DES PARAMETRES GL */
	/* couleur du fond (gris sombre) */
	glClearColor(0.3,0.3,0.3,0.0);
	/* activation du ZBuffer */
	glEnable( GL_DEPTH_TEST);

	/* lissage des couleurs sur les facettes */


	/* INITIALISATION DE LA SCENE */

}

void idle(void) {
	obj_rot+=STEP_ANGLE;
	glutPostRedisplay();
}

// int main(int argc, char** argv) {
// 	/* traitement des paramètres du programme propres à GL */
// 	glutInit(&argc, argv);
// 	/* initialisation du mode d'affichage :                */
// 	/* RVB + ZBuffer + Double buffer.                      */
// 	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
// 	/* placement et dimentions originales de la fenêtre */
// 	glutInitWindowPosition(0, 0);
// 	glutInitWindowSize(500, 500);
// 	/* ouverture de la fenêtre */
// 	if (glutCreateWindow("VIZU PRG") == GL_FALSE) {
// 		return 1;
// 	}

// 	init();

// 	/* association de la fonction callback de redimensionnement */
// 	glutReshapeFunc(reshapeFunc);
// 	/* association de la fonction callback d'affichage */
// 	glutDisplayFunc(drawFunc);
// 	/* association de la fonction callback d'événement du clavier */
// 	glutKeyboardFunc(kbdFunc);
// 	/* association de la fonction callback d'événement du clavier (touches spéciales) */
// 	glutSpecialFunc(kbdSpFunc);
// 	/* association de la fonction callback d'événement souris */
// 	glutMouseFunc(mouseFunc);
// 	/* association de la fonction callback de DRAG de la souris */
// 	glutMotionFunc(motionFunc);

// 	glutIdleFunc(idle);

// 	/* boucle principale de gestion des événements */
// 	glutMainLoop();
// 	/* Cette partie du code n'est jamais atteinte */
// 	return 0;
// }