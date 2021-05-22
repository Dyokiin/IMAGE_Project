#ifndef IMGFILE_H
#define IMGFILE_H

class QTree;

class PgmFile{
protected:
    std::string file;
public:
    int xsize;
    int ysize;
    PgmFile(std::string file);
    void builPgm(int mode);
    QTree* parse();
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
    TimacFile(std::string file, int maxx, int maxy);
    void buildFile();
    
};


#endif