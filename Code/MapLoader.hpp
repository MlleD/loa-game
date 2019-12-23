#ifndef MAPLOADER
#define MAPLOADER

#include "Map.hpp"
#include "GameElement.hpp"
#include "MapBuilder.hpp"
#include "Monster.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class MapLoader
{
private :
    static GameElement* get_game_element (char symbol);
public:
    static Map* get_map (const std::string file_path);
    static void save (const Map map, const std::string file_path);
};

#endif