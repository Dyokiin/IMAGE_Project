#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

class Camera{
private:
    //camera position
    
    float cx;
    float cy;
    float cz;

    //camera look at
    float anglespeed;
    float phi;
    float teta;

    float vx;
    float vy;
    float vz;

    //camera up
    float ux;
    float uy;
    float uz;

public:
    Camera();
    void UpdateCamera(float cex, float cey, float cez, float phi, float teta);
    void useCamera();
};

void projection();
