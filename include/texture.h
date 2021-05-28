#include <string>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "QuadTree.h"



class Tree {
private :
    std::string name;
    GLuint texture;
    QTNodePos pos;
public :
    Tree();
    Tree(std::string name);
    QTNodePos Get_pos();
    QTNodePos Set_pos(QTNodePos pos);
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