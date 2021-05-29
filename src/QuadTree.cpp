#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "../include/QuadTree.h"
#include "../include/frustrum.h"
#include "../include/texture.h"


QTNodePos QTNodePosMake(int x, int y){

    QTNodePos Pos;
    Pos.x = x;
    Pos.y = y;

    return Pos;
}

QTCorners QTCornersMake(int x1, int y1, int x2, int y2){
    QTCorners corners;
    corners.x1 = x1;
    corners.x2 = x2;
    corners.y1 = y1;
    corners.y2 = y2;

    return corners;
}

QTNode::QTNode(){
    this->height = 0;
}

QTNode::QTNode(QTNodePos pos, float height){
    this->pos = pos;
    this->height = height;
}

QTNode::~QTNode(){}

void QTNode::display(){
    if(this != NULL){
        float height = this->height;
        if(height <= 50){glColor3f(0, 0, height/255 +.3);}
        else if(height <= 80){glColor3f(height/255, height/255,0);}
        else if(height >= 210){glColor3f(height/255, height/255, height/255);}
        else{glColor3f(0, height/255,0);}
        glVertex3f(this->pos.x, height/10 -25.5, this->pos.y);
    }
}

void QTNode::displayD(){
    if(this != NULL){
        float height = this->height;
        if(height <= 50){glColor3f(0, 0, height/255 +.3);}
        else if(height <= 80){glColor3f(height/255, height/255,0);}
        else if(height >= 210){glColor3f(height/255, height/255, height/255);}
        else{glColor3f(0, height/255,0);}
        glVertex3f(this->pos.x + 20, height/10 -25.5, this->pos.y);
    }
}

QTree::QTree(){
    this->area = QTCornersMake(0,0,0,0);
    this->qtnode = NULL;
    this->nW = NULL;
    this->nE = NULL;
    this->sE = NULL;
    this->sW = NULL;
}

QTree::QTree(QTCorners corners){
    this->area = corners;
    this->qtnode = NULL;  
    this->nW = NULL;
    this->nE = NULL;
    this->sE = NULL;
    this->sW = NULL;
}

QTree::~QTree(){
    if(this->nE!=NULL) delete this->nE;
    if(this->nW!=NULL) delete this->nW;
    if(this->sE!=NULL) delete this->sE;
    if(this->sW!=NULL) delete this->sW;

    delete this->qtnode;
    delete this;
}

QTCorners QTree::get_area(){
    return this->area;
}

int QTree::insert(QTNode *node){

    if(node == NULL){return 1;}

    if(!(this->contain(node->pos))){return 2;}

    if((abs(this->area.x1 - this->area.x2) <= 1) && (abs(this->area.y1 - this->area.y2) <= 1)){
        this->qtnode = node;
        return 0;
    }

    if((this->area.x1 + this->area.x2) / 2 >= node->pos.x){
        if((this->area.y1 + this->area.y2) / 2 >= node->pos.y){
            if(this->nW == NULL){
                this->nW = new QTree(QTCornersMake(this->area.x1,
                                                    this->area.y1,
                                                    (this->area.x1 + this->area.x2)/2,
                                                    (this->area.y1 + this->area.y2)/2 ));
            }
            this->nW->insert(node);
        } 
        if((this->area.y1 + this->area.y2) / 2 <= node->pos.y){
            if(this->sW == NULL){
                this->sW = new QTree(QTCornersMake(this->area.x1,
                                                    (this->area.y1 + this->area.y2)/2,
                                                    (this->area.x1 + this->area.x2)/2,
                                                    this->area.y2));
            }
            this->sW->insert(node);
        }
    }
    if((this->area.x1 + this->area.x2)/2 <= node->pos.x){
        if((this->area.y1 + this->area.y2) / 2 >= node->pos.y){
            if(this->nE == NULL){
                this->nE = new QTree(QTCornersMake((this->area.x1 + this->area.x2)/2,
                                                    this->area.y1,
                                                    this->area.x2,
                                                    (this->area.y1 + this->area.y2)/2 ));
            }
            this->nE->insert(node);
        }
        if((this->area.y1 + this->area.y2)/2 <= node->pos.y){
            if(this->sE == NULL){
                this->sE = new QTree(QTCornersMake((this->area.x1 + this->area.x2)/2 ,
                                                    (this->area.y1 + this->area.y2)/2 ,
                                                    this->area.x2,
                                                    this->area.y2));    
            }
            this->sE->insert(node);
        }
    }
    return 0;
}

QTNode* QTree::search(QTNodePos pos){

    if(!this->contain(pos)){return NULL;}
    if(this->qtnode != NULL){return this->qtnode;}

    if((this->area.x1 + this->area.x2) / 2 > pos.x){
        if((this->area.y1 + this->area.y2) / 2 > pos.y){
            if(this->nW == NULL){return NULL;}
            return this->nW->search(pos);
        }
        else {
            if(this->sW == NULL){return NULL;}
            return this->sW->search(pos);
        }
    }
    else {
        if((this->area.y1 + this->area.y2) / 2 > pos.y){
            if(this->nE == NULL){return NULL;}
            return this->nE->search(pos);
        }
        else {
            if(this->sE == NULL){return NULL;}
            return this->sE->search(pos);
        }
    }
}

bool QTree::contain(QTNodePos pos){
    return(pos.x >= this->area.x1 && pos.x <= this->area.x2 && pos.y >= this->area.y1 && pos.y <= this->area.y2);
}

bool QTree::isViewed(){
    if(this==NULL){return true;}

    Vec3 p1(this->area.x1, this->search(QTNodePosMake(this->area.x1,this->area.y1))->height, this->area.y1);
    Vec3 p2(this->area.x2, this->search(QTNodePosMake(this->area.x2,this->area.y2))->height, this->area.y2);

    if(frustrum.pointInFrustum(p1)==1 || frustrum.pointInFrustum(p2)==1){return true;}
    if( frustrum.pl[0].distance(p1)*frustrum.pl[1].distance(p2)>=0 &&
        frustrum.pl[4].distance(p1)*frustrum.pl[5].distance(p2)>=0 &&
        frustrum.pl[2].distance(p1)*frustrum.pl[3].distance(p2)>=0   ){return true;}
    return false;
}

void QTree::display(){
    if(this->nW->qtnode != NULL){
        this->nW->qtnode->display();
        this->nE->qtnode->display();
        this->sE->qtnode->display();

        this->sE->qtnode->display();
        this->nW->qtnode->display();
        this->sW->qtnode->display();
    } else {
        if(this->nW != NULL){
            this->nW->display();
        }
        if(this->nE != NULL){
            this->nE->display();
        }
        if(this->sE != NULL){
            this->sE->display();
        }
        if(this->sW != NULL){
            this->sW->display();
        }
    }
}


// void QTree::displayDebug(){    
//     for(int x=this->area.x1; x<=this->area.x2; x++){
//         for(int y=this->area.y1; y<=this->area.y2; y++){
//             drawTriangle(this->search(QTNodePosMake(x+1,y)),
//                         this->search(QTNodePosMake(x+1,y+1)),
//                         this->search(QTNodePosMake(x,y)));

//             drawTriangle(this->search(QTNodePosMake(x,y)),
//                         this->search(QTNodePosMake(x,y+1)),
//                         this->search(QTNodePosMake(x+1,y+1)));
//         }
//     }
// }
