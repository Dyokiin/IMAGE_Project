BIN = bin/image
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm -lSDL2-2.0 -lSDL2_ttf
LIBDIR = 
GCC = g++
OBJECTS = obj/QuadTree.o obj/ImgFile.o obj/userI.o obj/imageMain.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/userI.o: src/userI.cpp include/userI.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/imageMain.o: src/imageMain.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@




clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
