#include <iostream>
#include <string.h>
#include <fstream>
#include "../include/ImgFile.h"

#define DEFAULTFOV  70
#define DEFAULTNEAR 0
#define DEFAULTFAR  0
#define DEFAULTZMIN 0
#define DEFAULTZMAX 255

std::string path = "/bin";
std::string ext = ".timac";

PgmFile::PgmFile(char* file){
    strcpy(file, this->file);
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
        }
        image.close();
    }
    return ysize;
}

TimacFile::TimacFile(char* file) : PgmFile(file){
    this->xsize = this->getXSize();
    this->ysize = this->getYSize();
    this->zmin = DEFAULTZMIN;
    this->zmax = DEFAULTZMAX;
    this->fov = DEFAULTFOV;
    this->znear = DEFAULTNEAR;
    this->zfar = DEFAULTFAR;
}

void TimacFile::buildFile(){
    std::fstream timac;
    std::string name = "";
    name.append(path);
    name.append(this->file);
    name.append(ext);
    timac.open(name);
    if(timac.is_open()){
        timac << this->file << std::endl;
        timac << this->xsize << std::endl;
        timac << this->ysize << std::endl;
        timac << this->zmin << std::endl;
        timac << this->zmax << std::endl;
        timac << this->znear << std::endl;
        timac << this->zfar << std::endl;
        timac << this->fov << std::endl;
        timac.close();
    }
}