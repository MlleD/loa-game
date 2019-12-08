CPP = g++ --std=c++11 -Wall
ALL = Game
all: $(ALL)
Game : Game.o Wall.o Case.o GameStructure.o GameElement.o Door.o Ground.o
	$(CPP) -o $@ $^
Game.o : Game.cpp Wall.hpp Case.hpp Ground.hpp Door.hpp
GameElement.o : GameElement.cpp
GameStructure.o : GameStructure.cpp GameStructure.hpp
Wall.o : Wall.cpp Wall.hpp GameStructure.hpp
Case.o : Case.cpp Case.hpp
Door.o : Door.cpp Door.hpp
Ground.o : Ground.cpp Ground.hpp
clean :
	rm -rf *.o $(ALL)
