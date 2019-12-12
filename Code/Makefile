CPP = g++ --std=c++11 -Wall
ALL = gp gc 
all: $(ALL)
gc : MapEditor.o Map.o Wall.o Case.o GameStructure.o GameElement.o Door.o Ground.o MapLoader.o
	$(CPP) -o $@ $^
gp : GameManager.o Map.o Wall.o Case.o GameStructure.o GameElement.o Door.o Ground.o MapLoader.o
	$(CPP) -o $@ $^
MapEditor.o : MapEditor.cpp MapEditor.hpp MapLoader.hpp
GameManager.o : GameManager.cpp GameManager.hpp Map.hpp MapLoader.hpp
MapLoader.o : MapLoader.cpp MapLoader.hpp GameElement.hpp Map.hpp
Map.o : Map.cpp Map.hpp Wall.hpp Case.hpp Ground.hpp Door.hpp
GameElement.o : GameElement.cpp
GameStructure.o : GameStructure.cpp GameStructure.hpp
Wall.o : Wall.cpp Wall.hpp GameStructure.hpp
Case.o : Case.cpp Case.hpp
Door.o : Door.cpp Door.hpp
Ground.o : Ground.cpp Ground.hpp
clean :
	rm -rf *.o $(ALL)
