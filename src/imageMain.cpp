#include <iostream>
#include "../include/QuadTree.h"
#include "../include/ImgFile.h"


int main(int argc, char* argv[]){
    
    std::string testc = "testc";
    TimacFile* test = new TimacFile(testc);

    test->buildFile();

    return EXIT_SUCCESS;
}