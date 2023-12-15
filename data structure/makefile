C_SOURCES = $(wildcard classes/*.cpp *.cpp)
HEADERS = $(wildcard *.hpp raylib/src/raylib.h)
SAND_BOX= $(HOME)/SAND_BOX


# Change this if your cross-compiler is somewhere else
CC = g++

# -g: Use debugging symbols in gcc
CFLAGS =


# First rule is run by default
main_app.o: main_app.cpp 
	${CC} ${CFLAGS} -c $^ 

# First rule is run by default
main_app.out: main_app.o ${HEADERS}
	${CC} ${CFLAGS} $^ -o $@ -I raylib/src/ -L raylib/src/ -lraylib


run: main_app.out
	-mkdir $(SAND_BOX)
	cp $< $(SAND_BOX)/
	chmod +x $(SAND_BOX)/*
	cd $(SAND_BOX) && \
	./$<



.PHONY:
clean:
	rm -rf *.out *.o *.a
	rm -rf headers/*.out classes/*.out $(SAND_BOX)/*
