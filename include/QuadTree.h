#ifndef QUADTREE_H
#define QUADTREE_H

#include "ImgFile.h"


typedef struct QTNodePos {
    int x;
    int y;
} QTNodePos;

QTNodePos QTNodePosMake(int x, int y);

typedef struct QTCorners {
    int x1;
    int x2;
    int y1;
    int y2;
} QTCorners;

QTCorners QTCornersMake(int x1, int y1, int x2, int y2);

class QTNode {
public:  
    QTNodePos pos;
    float height;
public:
    QTNode();
    QTNode(QTNodePos pos, float height);
    ~QTNode();
};

class QTree {
    QTCorners area;
    QTNode *qtnode;
    QTree *nW;
    QTree *nE;
    QTree *sW;
    QTree *sE;
public:
    QTree();
    QTree(QTCorners area);
    ~QTree();
    QTree QTreeMake(TimacFile file);
    int insert(QTNode *node);
    QTNode* search(QTNodePos pos);
    bool contain(QTNodePos pos);
    void display();
    QTCorners get_area();
};

#endif