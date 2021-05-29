#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>


class QTNode;

void loadGrass();
void drawTriangle(QTNode *n1, QTNode *n2, QTNode *n3);

class Tree {
private :
    GLuint texture;
public :
    Tree();
    Tree(QTNode* Node);
    void Display();
    void Bind();
};

class Skybox {
private :
    GLuint front;
    GLuint left;
    GLuint back;
    GLuint right;
    GLuint top;
    GLuint bot;
public :
    Skybox();
    void Display();
    void Bind();
};


#endif