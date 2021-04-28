#ifndef QUADTREE_H
#define QUADTREE_H


typedef struct QTNodeData {
    float x;
    float y;
    float height;
} QTNodeData;

QTNodeData QTNodeDataMake(float x, float y, float height);

typedef struct QTCorners {
    float x1;
    float x2;
    float y1;
    float y2;
} QTCorners;

QTCorners QTCornersMake(float x1, float x2, float y1, float y2);

class QTNode { 
protected:    
    QTNode *nW;
    QTNode *nE;
    QTNode *sW;
    QTNode *sE;
    QTCorners area;
    QTNodeData *data;
public:
    QTNode(QTCorners area);
    ~QTNode();

    QTNodeData getData();
    QTCorners getArea();
};

class QTree : public QTNode {
public:
    QTree(QTCorners img_size);
};

#endif