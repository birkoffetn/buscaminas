SOURCES= $(wildcard src/*.cpp)
OBJECTS= $(patsubst src/%.cpp,output/%.o,${SOURCES}) resource.o
INCLUDE= -Iinclude
CXXFLAGS= -Wall -Wextra -ggdb -std=c++11 ${INCLUDE}
LIBS= -lsfml-system -lsfml-window -lsfml-graphics
BIN= bin/game

all: bin output ${BIN}

run: bin output ${BIN}
	./${BIN}
src/%.cpp: include/%.hpp

output/%.o: src/%.cpp
	g++ -c $< -o $@ ${CXXFLAGS}

${BIN}: ${OBJECTS} main.cpp
	g++ $^ -o $@ ${LIBS}

bin:
	mkdir $@

output:
	mkdir $@

clean:
	rm -f ${OBJECTS} ${BIN}


resource.o: resource.rc game.ico
	windres $< $@	
