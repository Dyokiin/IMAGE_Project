#include <iostream>
#include "../include/QuadTree.h"


QTNodeData QTNodeDataMake(float x, float y, float height){

    QTNodeData data;
    data.x = x;
    data.y = y;
    data.height = height;

    return data;
}

QTCorners QTCornersMake(float x1, float x2, float y1, float y2){

    QTCorners corners;
    corners.x1 = x1;
    corners.x2 = x2;
    corners.y1 = y1;
    corners.y2 = y2;

    return corners;
}

QTNode::QTNode(QTCorners corners){

    this->nW = NULL;
    this->nE = NULL;
    this->sE = NULL;
    this->sW = NULL;
    this->area = corners;
    this->data = (QTNodeData*)malloc(sizeof(QTNodeData));
}

QTNode::~QTNode(){
    if(this->nE!=NULL) delete this->nE;
    if(this->nW!=NULL) delete this->nW;
    if(this->sE!=NULL) delete this->sE;
    if(this->sW!=NULL) delete this->sW;

    free(this->data);
    
    delete this->data;
}

QTree::QTree(QTCorners img_size) : QTNode(img_size){}
