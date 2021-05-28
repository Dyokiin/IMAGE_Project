#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"


#define DEFAULTFOV  60
#define DEFAULTZMIN 0
#define DEFAULTZMAX 255

std::string ext = ".timac";

PgmFile::PgmFile(std::string file){
    this->file = file;
}

QTree* PgmFile::parse(){
    
    std::string line;

    this->xsize = 0;
    this->ysize = 0;
    
    std::fstream image;
    image.open(this->file);
    if(image.is_open()){
        int i;
        for(i=0;i<3;i++){std::getline(image, line);}
        int j=0;
        while(line[j] != ' '){
            this->xsize*=10;
            this->xsize+=(int)line[j]-48;
            j++;
        }
        j++;
        while(line[j] != 0){
            this->ysize*=10;
            this->ysize+=(int)line[j]-48;
            j++;
        }
        std::getline(image, line);
        std::getline(image, line);
        float value;
        QTree *qtree = new QTree(QTCornersMake(0, 0, this->xsize, this->ysize));
        int x, y, l;

        for(x = 0; x<this->xsize; x++){

            for(y = 0; y< this->ysize; y++){
                value = 0;
                l=0;

                while(line[l] != 0){
                    value*=10;
                    value+=(int)line[l]-48;
                    l++;
                }
                QTNode* qnode = new QTNode(QTNodePosMake(y, x), value);
                
                qtree->insert(qnode);
                std::getline(image, line);
            }

        }

        image.close();

        TimacFile* tim = new TimacFile(this->file, this->xsize, this->ysize);
        tim->buildFile();

        return qtree;
    } else {
        return NULL;
    }
    
}

TimacFile::TimacFile(std::string file, int maxx, int maxy) : PgmFile(file){
    this->xsize = maxx;
    this->ysize = maxy;
    this->zmin = DEFAULTZMIN;
    this->zmax = DEFAULTZMAX;
    this->fov = DEFAULTFOV;
    this->znear = 0.1;
    this->zfar = maxx;
}

void TimacFile::buildFile(){
    FILE *timac;
    char name[64];
    int x = 0;

    for(long unsigned int i=0; i<this->file.length(); i++){
        name[i] = this->file[i];
        x++;
    } 
    for(long unsigned int j=0; j<=ext.length(); j++){
        name[x+j] = ext[j];
    }

    timac = fopen(name, "w");

    fprintf(timac, "%s\n%d\n%d\n%d\n%d\n%f\n%f\n%d\n", 
        name, 
        this->xsize, this->ysize, 
        this->zmax, this->zmin, 
        this->znear, this->zfar, 
        this->fov);

    fclose(timac);
}
