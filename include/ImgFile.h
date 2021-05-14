#ifndef IMGFILE_H
#define IMGFILE_H

#include <string>

class PgmFile{
protected:
    std::string file;
public:
    PgmFile(std::string file);

    int getXSize();
    int getYSize();

};

class TimacFile : public PgmFile {
protected:
    int xsize;
    int ysize;
    int zmin;
    int zmax;
    float znear;
    float zfar;
    int fov;
public:
    TimacFile(std::string file);
    void buildFile();
    
};


#endif