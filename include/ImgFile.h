#ifndef IMGFILE_H
#define IMGFILE_H

#include <string>
class QTree;

class PgmFile{
protected:
    std::string file;
public:
    int xsize;
    int ysize;
    PgmFile(std::string file);
    int getXSize();
    int getYSize();
    void builPgm(int mode);
    int getValue(int x, int y);
    QTree* parse();
    QTree* generateQTreeImage();

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