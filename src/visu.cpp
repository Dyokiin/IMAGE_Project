/* SUR LA BASE DE : */

/* *******************************************************/
/* Exemple de programme OpenGL / GLUT           (C) 2010 */
/* Venceslas Biri   Université Paris Est Marne La Vallée */
/* *******************************************************/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/visu.h"
#include "../include/QuadTree.h"
#include "../include/texture.h"

float profondeur = 3;
float latitude = 0.0;
float longitude = M_PI/2.;
float x;
float y;
float z;
float offx;
float offy;
float offz;

/* Global Class */
QTree *qtree;
Skybox* skybx;


/*********************************************************/
/* fonction de dessin de la scène à l'écran              */
static void drawFunc() { 
	/* reinitialisation des buffers : couleur et ZBuffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* modification de la matrice de la scène */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Debut du dessin de la scène */
	glPushMatrix();

	x = 0.1*sin(longitude)*sin(latitude);
	y = 0.1*cos(latitude);
	z = 0.1*cos(longitude)*sin(latitude);
	
	/* placement de la caméra */
	gluLookAt(x + offx,y + offy,z + offz,
              0.0 + offx,0.0 + offy,0.0 + offz,
              0.0,1.0,0.0);


	glPushMatrix();
	
	skybx->Display();

	glBegin(GL_TRIANGLES);
	qtree->display();
	glEnd();


	/* Fin du dessin */
	glPopMatrix();



	/* fin de la définition de la scène */
	glFinish();

	/* changement de buffer d'affichage */
	glutSwapBuffers();
}

/*********************************************************/
/* fonction de changement de dimension de la fenetre     */
/* paramètres :                                          */
/* - width : largeur (x) de la zone de visualisation     */
/* - height : hauteur (y) de la zone de visualisation    */
static void reshapeFunc(int width,int height) {
	GLfloat  h = (GLfloat) width / (GLfloat) height ;
	
	/* dimension de l'écran GL */
	glViewport(0, 0, (GLint)width, (GLint)height);
	/* construction de la matrice de projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* définition de la camera */
	gluPerspective( 60.0, h, 0.01, 1000.0 );			// Angle de vue, rapport largeur/hauteur, near, far

	/* Retour a la pile de matrice Modelview
			et effacement de celle-ci */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************************/
/* fonction associée aux interruptions clavier           */
/* paramètres :                                          */
/* - c : caractère saisi                                 */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdFunc(unsigned char c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	/* 'q' ou 'Q'*/
	switch(c) {
		case 27 :
			exit(0);
			break;
		case 'F' : case 'f' : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		case 'P' : case 'p' : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		case 'Z' : case 'z' : offx+=0.5;
			break;
		case 'Q' : case 'q' : offz-=0.5;
			break;
		case 'S' : case 's' : offx-=0.5;
			break;
		case 'D' : case 'd' : offz+=0.5;
			break;
		case 32 :
			offy+=0.5;
			break;
	}
	glutPostRedisplay();
}

/*********************************************************/
/* fonction associée aux interruptions clavier pour les  */
/*          touches spéciales                            */
/* paramètres :                                          */
/* - c : code de la touche saisie                        */
/* - x,y : coordonnée du curseur dans la fenêtre         */
static void kbdSpFunc(int c, int x, int y) {
	/* sortie du programme si utilisation des touches ESC, */
	switch(c) {
		case GLUT_KEY_UP :
			if (latitude>STEP_ANGLE) latitude += STEP_ANGLE;
			break;
		case GLUT_KEY_DOWN :
			if(latitude<M_PI-STEP_ANGLE) latitude -= STEP_ANGLE;
			break;
		case GLUT_KEY_LEFT :
			longitude += STEP_ANGLE;
			break;
		case GLUT_KEY_RIGHT :
			longitude -= STEP_ANGLE;
			break;
		case 114 :
			offy-=0.5;
			break;
	}
	glutPostRedisplay();
}


/*********************************************************/
/* fonction associée au clique de la souris              */
/* paramètres :                                          */
/* - button : nom du bouton pressé GLUT_LEFT_BUTTON,     */
/*   GLUT_MIDDLE_BUTTON ou GLUT_RIGHT_BUTTON             */
/* - state : état du bouton button GLUT_DOWN ou GLUT_UP  */
/* - x,y : coordonnées du curseur dans la fenêtre        */
static void mouseFunc(int button, int state, int x, int y) { 
}

/*********************************************************/
/* fonction associée au déplacement de la souris bouton  */
/* enfoncé.                                              */
/* paramètres :                                          */
/* - x,y : coordonnées du curseur dans la fenêtre        */
static void motionFunc(int x, int y) {
}

/*********************************************************/
/* fonction d'initialisation des paramètres de rendu et  */
/* des objets de la scènes.                              */
static void init() {
	
	profondeur = 10;
	latitude = 1.32;
	longitude = 3.94;

	/* INITIALISATION DES PARAMETRES GL */
	/* couleur du fond (gris sombre) */
	glClearColor(0.3,0.3,0.3,0.0);
	/* activation du ZBuffer */
	glEnable( GL_DEPTH_TEST);

	/* lissage des couleurs sur les facettes */
	//glShadeModel(GL_SMOOTH);

	/* INITIALISATION DE LA SCENE */
	// char *p = SDL_GetBasePath();
    std::string pgmpath = "./ressources/height_map1.pgm";
    PgmFile* pgm = new PgmFile(pgmpath);
    // free(p);

    qtree = pgm->parse();

	skybx = new Skybox();
	skybx->Bind();

}

int main(int argc, char** argv) {


	/* traitement des paramètres du programme propres à GL */
	glutInit(&argc, argv);
	/* initialisation du mode d'affichage :                */
	/* RVB + ZBuffer + Double buffer.                      */
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	/* placement et dimentions originales de la fenêtre */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 720);
	/* ouverture de la fenêtre */
	if (glutCreateWindow("IMAGE Project") == GL_FALSE) {
		return 1;
	}

	init();

	/* association de la fonction callback de redimensionnement */
	glutReshapeFunc(reshapeFunc);
	/* association de la fonction callback d'affichage */
	glutDisplayFunc(drawFunc);
	/* association de la fonction callback d'événement du clavier */
	glutKeyboardFunc(kbdFunc);
	/* association de la fonction callback d'événement du clavier (touches spéciales) */
	glutSpecialFunc(kbdSpFunc);
	/* association de la fonction callback d'événement souris */
	glutMouseFunc(mouseFunc);
	/* association de la fonction callback de DRAG de la souris */
	glutMotionFunc(motionFunc);

	//glutIdleFunc(idle);

	/* boucle principale de gestion des événements */
	glutMainLoop();
	/* Cette partie du code n'est jamais atteinte */
	return 0;
}
