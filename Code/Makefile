CPP = g++ --std=c++11 -Wall
ALL = gp gc 
all: $(ALL)
gc : MapEditor.o Map.o Wall.o Case.o GameStructure.o GameElement.o Door.o Ground.o MapLoader.o MapBuilder.o Monster.o Player.o Game.o GameLoader.o
	$(CPP) -o $@ $^
gp : GameManager.o Map.o Wall.o Case.o GameStructure.o GameElement.o Door.o Ground.o MapLoader.o MapBuilder.o Monster.o Player.o Game.o GameLoader.o
	$(CPP) -o $@ $^
MapEditor.o : MapEditor.cpp MapEditor.hpp MapLoader.hpp Game.hpp GameLoader.hpp
GameManager.o : GameManager.cpp GameManager.hpp Map.hpp MapLoader.hpp MapBuilder.hpp Game.hpp GameLoader.hpp
GameLoader.o :  GameLoader.cpp Game.hpp GameLoader.hpp MapLoader.hpp
Game.o : Game.cpp Game.hpp
MapLoader.o : MapLoader.cpp MapLoader.hpp GameElement.hpp Map.hpp MapBuilder.hpp
MapBuilder.o : MapBuilder.cpp MapBuilder.hpp
Map.o : Map.cpp Map.hpp Wall.hpp Case.hpp Ground.hpp Door.hpp MapBuilder.hpp
GameElement.o : GameElement.cpp
GameStructure.o : GameStructure.cpp GameStructure.hpp
Wall.o : Wall.cpp Wall.hpp GameStructure.hpp
Case.o : Case.cpp Case.hpp
Door.o : Door.cpp Door.hpp
Ground.o : Ground.cpp Ground.hpp
Monster.o : Monster.cpp Monster.hpp
Player.o : Player.cpp Player.hpp
clean :
	rm -rf *.o $(ALL)
