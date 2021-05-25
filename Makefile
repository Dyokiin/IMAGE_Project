BIN = bin/image
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm -lSDL2-2.0
LIBDIR = 
GCC = g++
OBJECTS = obj/QuadTree.o obj/ImgFile.o obj/imageMain.o obj/ImgGen.o obj/camera.o obj/glbiri.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/glbiri.o: src/glbiri.cpp include/glbiri.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgGen.o: src/ImgGen.cpp include/ImgGen.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/camera.o: src/camera.cpp include/camera.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/imageMain.o: src/imageMain.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@






clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
