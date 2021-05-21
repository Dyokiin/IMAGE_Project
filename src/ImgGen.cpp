#include <iostream>
#include "../include/QuadTree.h"
#include "../include/ImgGen.h"



QTree* generateRandomQT(int width, int height){
    
    QTree* qtree = new QTree(QTCornersMake(0, 0, width, height));

    for(int i = 0; i < width; i++){

        for (int j = 0; j < height; j++)
        {   
            QTNode* qnode = new QTNode(QTNodePosMake(i, j), rand() % 256);

            qtree->insert(qnode);
        }
        

    }

    return qtree;

};

int perlinN(int x, int y){

};


