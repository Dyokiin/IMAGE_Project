#ifndef IMGFILE_H
#define IMGFILE_H

class PgmFile{
protected:
    char file[32];
public:
    PgmFile(char* file);

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
    TimacFile(char* file);
    void buildFile();
};


#endif