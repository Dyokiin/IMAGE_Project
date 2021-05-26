BIN = bin/image
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm -lSDL2-2.0
LIBDIR = 
GCC = g++
OBJECTS = obj/QuadTree.o obj/ImgFile.o obj/ImgGen.o obj/camera.o obj/visu.o obj/gldrawing.o obj/create_object.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgGen.o: src/ImgGen.cpp include/ImgGen.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/camera.o: src/camera.cpp include/camera.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/gldrawing.o: src/gldrawing.cpp include/gldrawing.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/create_object.o: src/create_object.cpp include/create_object.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/visu.o: src/visu.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@






clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
