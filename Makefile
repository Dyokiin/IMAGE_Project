BIN = bin/image
FLAGS = -Wall
INC = 
LIBS = -lglut -lGLU -lGL -lm `sdl-config --clfags --libs`
LIBDIR = 
GCC = g++
OBJECTS = bin/QuadTree.o bin/ImgFile.o bin/imageMain.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

bin/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

bin/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

bin/imageMain.o: src/imageMain.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@


clean:
	rm -f *.o $(BIN)
	find . -name "*~" -exec rm {} \;
