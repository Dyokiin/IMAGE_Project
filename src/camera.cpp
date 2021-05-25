#include "../include/camera.h"

/* Default camera position and speed*/
#define DEFX 0.0
#define DEFY 0.0
#define DEFZ 10.0
#define DEFSPEED 0.5

/* Default camera center, spherical */
#define DEFPHI 0
#define DEFTET M_PI/2
#define DEFANGSPEED M_PI/12
#define DEFPROF 3

/* Default camera Up vector */
#define DEFUPZ 0.0


Camera::Camera(){
    this->cx = DEFX;
    this->cy = DEFY;
    this->cz = DEFZ;

    this->latitude = DEFPHI;
    this->longitude = DEFTET;
    this->STEP_ANGLE = DEFANGSPEED;
    this->profondeur = DEFPROF;

    this->vx = cos(latitude)*sin(longitude)+cx;
    this->vy = sin(latitude)*sin(longitude)+cy;
    this->vz = cos(longitude)+cz;

    this->ux = (vx-cx)*cos(latitude+M_PI/2);
    this->uy = (vy-cy)*sin(latitude+M_PI/2);
    this->uz = DEFUPZ;
}

void Camera::UpdateCamera(float cex, float cey, float cez, float latitude, float longitude){
    this->cx+=cex*DEFSPEED;
    this->cy+=cey*DEFSPEED;
    this->cz+=cez*DEFSPEED;
    this->latitude+=latitude*this->STEP_ANGLE;
    this->longitude+=longitude*this->STEP_ANGLE;

    this->vx = cos(latitude)*sin(longitude);
    this->vy = sin(latitude)*sin(longitude);
    this->vz = cos(longitude)+cez;

    this->ux = (vx-cex)*cos(latitude+M_PI/2);
    this->uy = (vy-cey)*sin(latitude+M_PI/2);

    std::cout << this->cx << ", " << this->cy << ", " << this->cz << std::endl;

}

void Camera::useCamera(){
    /* placement de la caméra */
    gluLookAt(this->profondeur*sin(this->longitude)*sin(this->latitude),profondeur*cos(this->latitude),profondeur*cos(this->longitude)*sin(this->latitude),
                    0.0,0.0,0.0,
                    0.0,1.0,0.0);

}


//à compléter ! ??
void projection(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2, 2, -1, 1, 1, 20);
}
