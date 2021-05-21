#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"


#define DEFAULTFOV  70
#define DEFAULTNEAR 0
#define DEFAULTFAR  0
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
            std::cout << line[j] << std::endl;
            this->xsize*=10;
            this->xsize+=(int)line[j]-48;
            j++;
            std::cout << xsize << std::endl;
        }
        std::cout << " " << std::endl;
        j++;
        while(line[j] != 0){
            std::cout << line[j] << std::endl;
            this->ysize*=10;
            this->ysize+=(int)line[j]-48;
            std::cout << ysize << std::endl;
            j++;
        }
        std::getline(image, line);
        std::getline(image, line);
        int value, l;
        QTree *qtree = new QTree(QTCornersMake(0, 0, this->xsize, this->ysize));
        int x, y;

        for(x = 0; x<=this->xsize; x++){

            for(y = 0; y<=this->ysize; y++){
                value = 0;
                l=0;

                while(line[l] != 0){
                    value*=10;
                    value+=(int)line[l]-48;
                    l++;
                }
                QTNode* qnode = new QTNode(QTNodePosMake(x, y), value);

                qtree->insert(qnode);
                std::getline(image, line);
            }

        }

        image.close();
        return qtree;
    } else {
        return NULL;
    }
    
}

int PgmFile::getXSize(){
    std::string line;
    int xsize = 0;
    std::fstream image;
    image.open(this->file);
    if(image.is_open()){
        int i;
        for(i=0;i<3;i++){std::getline(image, line);}
        i=0;
        while(line[i] != ' '){
            xsize*=10;
            xsize+=line[i];
            i++;

            if(i > 3){
                break;
            }
        }
        image.close();
    }
    return xsize;
}

int PgmFile::getYSize(){
    std::string line;
    std::fstream image;
    int ysize = 0;
    image.open(this->file);
    if(image.is_open()){        
        int i;
        for(i=0;i<3;i++){std::getline(image, line);}
        i=0;
        while(line[i] != ' '){
            i++;
        }
        i++;
        while(line[i] != ' '){
            ysize*=10;
            ysize+=line[i];
            i++;
            if(i > 3){
                break;
            }
        }
        image.close();
    }
    return ysize;
}

int PgmFile::getValue(int x, int y){
    std::string line;
    std::fstream image;
    int value =0;
    image.open(this->file);
    if(image.is_open()){
        int i = 0;
        int maxx = this->getXSize();
        for(i=0; i<=3; i++){std::getline(image, line);}
        for(i=0; i<=x+ maxx*(y); i++){
            std::getline(image, line);
        }
        i=0;

        while(line[i] != '\n'){
            value*=10;
            value+=line[i];
            i++;
            if(i>3){
                break;
            }
        }
        image.close();
    }
    return value;
}

TimacFile::TimacFile(std::string) : PgmFile(file){
    this->xsize = this->getXSize();
    this->ysize = this->getYSize();
    this->zmin = DEFAULTZMIN;
    this->zmax = DEFAULTZMAX;
    this->fov = DEFAULTFOV;
    this->znear = DEFAULTNEAR;
    this->zfar = DEFAULTFAR;
}

void TimacFile::buildFile(){
    FILE *timac;
    char name[32];
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

QTree* PgmFile::generateQTreeImage(){
    
    
    int width = this->getXSize();
    int height = this->getYSize();

    QTree* qtree = new QTree(QTCornersMake(0, 0, width, height));

    for(int i = 0; i < width; i++){

        for (int j = 0; j < height; j++)
        {   
            QTNode* qnode = new QTNode(QTNodePosMake(i, j), 255);

            qtree->insert(qnode);
        }
        

    }

    return qtree;
}