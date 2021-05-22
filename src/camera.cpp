#include "../include/camera.h"

/* Default camera position and speed*/
#define DEFX 0.0
#define DEFY 0.0
#define DEFZ 100.0
#define DEFSPEED 0.5

/* Default camera center, spherical */
#define DEFPHI -M_PI/6
#define DEFTET -M_PI/6
#define DEFANGSPEED M_PI/12

/* Default camera Up vector */
#define DEFUPZ 0.0


Camera::Camera(){
    this->cx = DEFX;
    this->cy = DEFY;
    this->cz = DEFZ;

    this->phi = DEFPHI;
    this->teta = DEFTET;
    this->anglespeed = DEFANGSPEED;

    this->vx = cos(phi)*sin(teta)+cx;
    this->vy = sin(phi)*sin(teta)+cy;
    this->vz = cos(teta)+cz;

    this->ux = (vx-cx)*cos(phi+M_PI/2);
    this->uy = (vy-cy)*sin(phi+M_PI/2);
    this->uz = DEFUPZ;
}

void Camera::UpdateCamera(float cex, float cey, float cez, float phi, float teta){
    this->cx+=cex*DEFSPEED;
    this->cy+=cey*DEFSPEED;
    this->cz+=cez*DEFSPEED;
    this->phi+=phi*this->anglespeed;
    this->teta+=teta*this->anglespeed;

    this->vx = cos(phi)*sin(teta)+cex;
    this->vy = sin(phi)*sin(teta)+cey;
    this->vz = cos(teta)+cez;

    this->ux = (vx-cex)*cos(phi+M_PI/2);
    this->uy = (vy-cey)*sin(phi+M_PI/2);

    std::cout << this->cx << ", " << this->cy << ", " << this->cz << std::endl;

}

void Camera::useCamera(){
    gluLookAt(this->cx, this->cy, this->cz, this->vx, this->vy, this->vz, this->ux, this->uy, this->uz);
}


//à compléter ! ??
void projection(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1, 1, 1, 20);
}
