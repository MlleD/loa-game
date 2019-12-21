#include <iostream>
#include <stdexcept>

#include "Wall.hpp"
#include "Case.hpp"
#include "Ground.hpp"
#include "Door.hpp"
#include "Map.hpp"
#include "Creature.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "GameManager.hpp"

Map::Map(MapBuilder builder)
 : height(builder.get_height()), width(builder.get_width()), maxIndex(height * width - 1),
 number_chargers(builder.get_chargers()), number_diamonds(builder.get_diamonds()), number_monsters(builder.get_monsters())
 {
    // Premiere ligne, celle du haut
    for (int i = 0; i < width; i++)
    {
        Wall w;
        matrix.push_back(Case(w));
    }
    
    // Lignes intermediaires
    for (int i = 1; i < height - 1; i++)
    {
        Wall w1;
        matrix.push_back(w1);
        for (int j = 1; j < width - 1; j++)
        {
            Ground g;
            matrix.push_back(Case(g));
        }
        Wall w2;
        matrix.push_back(Case(w2));
    }

    //Ligne du bas
    for (int i = 0; i < width; i++)
    {
        Wall w;
        matrix.push_back(Case(w));
    }
}

void Map::print()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (i % width == 0)
        {
            std::cout << std::endl;
        }
        matrix[i].print();
    }
    std::cout << std::endl;
}

int Map::get_height() const
{
    return height;
}

int Map::get_width() const
{
    return width;
}

GameElement Map::get(int x, int y) const
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    return matrix.at(y * Map::get_width() + x).get_element();
}

void Map::put(int x, int y, GameElement element)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        throw std::invalid_argument(std::string("Index out of range"));
    }
    matrix[y*get_width() + x].set_element(element);
}

int Map::get_number_monsters() const
{
    return number_monsters;
}

int Map::get_number_diamonds() const
{
    return number_diamonds;
}

int Map::get_number_chargers() const
{
    return number_chargers;
}


void Map::set_file_path(std::string file_path)
{
    Map::file_path = file_path;
}

std::string Map::get_file_path()
{
    return Map::file_path;
}