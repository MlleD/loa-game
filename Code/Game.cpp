#include "Game.hpp"
#include "iostream"
using namespace std;

Game::Game() : map_number(0), current_map(1), teleport_number(0)
{}

Game::Game(int map_number, std::vector<Map*> maps) : map_number(map_number), current_map(1), teleport_number(0)
{
    for ( int i = 0; i < maps.size(); i++)
    {
        Game::maps.push_back(maps.at(i));
    }
}

Game::Game(int map_number, std::vector<Map*> maps, int current_map, int teleport_number) : map_number(map_number), current_map(current_map), teleport_number(teleport_number)
{
    cout << Game::current_map <<endl;
    for ( int i = 0; i < maps.size(); i++)
    {
        Game::maps.push_back(maps.at(i));
    }
}

Game::~Game()
{
    cout << "destroying game" << endl;
    for (int i = 0; i < get_map_number(); i++)
    {
        delete get_map(i);
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

Map* Game::get_map(int i) const
{
    return Game::maps.at(i);
}

void Game::set_maps(std::vector<Map*> maps)
{
    for ( int i = 0; i < maps.size(); i++)
    {
        Game::maps.push_back(maps.at(i));
    }
}
