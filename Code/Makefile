CPP = g++ --std=c++11 -Wall -Werror -Wextra
ALL = gp gc 
all: $(ALL)
gc : MapEditor.o Map.o Wall.o Case.o StructureElement.o GameElement.o Door.o Ground.o MapLoader.o MapBuilder.o Monster.o Player.o Game.o GameLoader.o Creature.o InteractiveElement.o Diamond.o Warp.o Teleporter.o
	$(CPP) -o $@ $^
gp : GameManager.o Map.o Wall.o Case.o StructureElement.o GameElement.o Door.o Ground.o MapLoader.o MapBuilder.o Monster.o Player.o Game.o GameLoader.o Creature.o InteractiveElement.o Diamond.o Warp.o Teleporter.o
	$(CPP) -o $@ $^
MapEditor.o : MapEditor.cpp MapEditor.hpp MapLoader.hpp Game.hpp GameLoader.hpp
GameManager.o : GameManager.cpp GameManager.hpp Map.hpp MapLoader.hpp MapBuilder.hpp Game.hpp GameLoader.hpp Creature.hpp
GameLoader.o :  GameLoader.cpp Game.hpp GameLoader.hpp MapLoader.hpp
Game.o : Game.cpp Game.hpp
MapLoader.o : MapLoader.cpp MapLoader.hpp GameElement.hpp Map.hpp MapBuilder.hpp
MapBuilder.o : MapBuilder.cpp MapBuilder.hpp
Map.o : Map.cpp Map.hpp Wall.hpp Case.hpp Ground.hpp Door.hpp MapBuilder.hpp
Case.o : Case.cpp Case.hpp
GameElement.o : GameElement.cpp
StructureElement.o : StructureElement.cpp StructureElement.hpp
Wall.o : Wall.cpp Wall.hpp StructureElement.hpp
Door.o : Door.cpp Door.hpp
Ground.o : Ground.cpp Ground.hpp
Creature.o : Creature.cpp Creature.hpp GameElement.hpp Map.hpp
Monster.o : Monster.cpp Monster.hpp Creature.hpp
Player.o : Player.cpp Player.hpp Creature.hpp
InteractiveElement.o : InteractiveElement.cpp InteractiveElement.hpp GameElement.hpp
Warp.o : Warp.cpp Warp.hpp

clean :
	rm -rf *.o $(ALL)
