#ifndef GAMELOADER
#define GAMELOADER

#include "MapLoader.hpp"
#include "Game.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>


class GameLoader
{
public:
    static Game* get_game(const std::string file_path);
    static void save(const Game* game, const std::string file_path);
};


#endif