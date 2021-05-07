BIN = bin/image
FLAGS = -Wall
INC = 
LIBS = -lglut -lGLU -lGL -lm `sdl-config --clfags --libs`
LIBDIR = 
GCC = g++
OBJECTS = obj/QuadTree.o obj/ImgFile.o obj/Button.o obj/imageMain.o

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/imageMain.o: src/imageMain.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/Button.o: src/Button.cpp include/Button.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@


clean:
	rm -f *.o $(BIN)
	find . -name "*~" -exec rm {} \;
