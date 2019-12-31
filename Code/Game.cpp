#include "Game.hpp"


Game::Game()
{
    Game(0,std::vector<Map*>());
}

Game::Game(int map_number, std::vector<Map*> maps)
{
    Game(map_number,maps,1,0);
}

Game::Game(int map_number, std::vector<Map*> maps, int current_map, int teleport_number)
{
    Game::set_map_number(map_number);
    Game::set_maps(maps);
    Game::set_current_map(current_map);
    Game::set_teleport_number(teleport_number);
}

Game::~Game()
{
    for (auto iter = maps.begin(); iter < maps.end() ; ++iter)
    {
        delete *iter;
    }
}

int Game::get_map_number() const
{
    return Game::map_number;
}

void Game::set_map_number(int map_number)
{
    Game::map_number = map_number;
}

int Game::get_current_map() const
{
    return Game::current_map;
}

void Game::set_current_map(int current_map)
{
    Game::current_map = current_map;
}

int Game::get_teleport_number() const
{
    return Game::teleport_number;
}

void Game::set_teleport_number(int teleport_number)
{
    Game::teleport_number = teleport_number;
}

std::vector<Map*> Game::get_maps() const
{
    return Game::maps;
}

void Game::set_maps(std::vector<Map*> maps)
{
    for (auto iter = std::begin(maps); iter != std::end(maps); ++iter)
    {
        Game::maps.push_back(*iter);
    }
}
