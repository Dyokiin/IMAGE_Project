BIN = bin/image
FLAGS = -Wall -g
INC = 
LIBS = -lglut -lGLU -lGL -lm -lSDL -lSDL_image
LIBDIR = 
GCC = g++
OBJECTS = obj/QuadTree.o obj/ImgFile.o obj/frustrum.o obj/visu.o  obj/texture.o	

default: $(BIN)

all: $(OBJECT)

$(BIN): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(BIN) $(LIBDIR) $(LIBS)

obj/QuadTree.o: src/QuadTree.cpp include/QuadTree.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/ImgFile.o: src/ImgFile.cpp include/ImgFile.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/frustrum.o: src/frustrum.cpp include/frustrum.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/texture.o: src/texture.cpp include/texture.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

obj/visu.o: src/visu.cpp
	$(GCC) $(INC) $(FLAGS) -c $< -o $@






clean:
	rm -f *.o $(OBJECTS)
	find . -name "*~" -exec rm {} \;
