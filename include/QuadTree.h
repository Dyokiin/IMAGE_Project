#ifndef QUADTREE_H
#define QUADTREE_H

#include "ImgFile.h"


typedef struct QTNodePos {
    float x;
    float y;
} QTNodePos;

QTNodePos* QTNodePosMake(float x, float y);

typedef struct QTCorners {
    float x1;
    float x2;
    float y1;
    float y2;
} QTCorners;

QTCorners* QTCornersMake(float x1, float x2, float y1, float y2);

class QTNode {
public:  
    QTNodePos *Pos;
    float height;
public:
    QTNode();
    QTNode(QTNodePos* pos, float height);
    ~QTNode();
};

class QTree {
    QTNode *qtnode;
    QTCorners *area;
    QTree *nW;
    QTree *nE;
    QTree *sW;
    QTree *sE;
public:
    QTree();
    QTree(QTCorners *area);
    ~QTree();
    QTree QTreeMake(TimacFile file);
    void insert(QTNode *node);
    QTCorners* getArea();
    QTNode* search(QTNodePos *pos);
    bool contain(QTNodePos *pos);
};

#endif