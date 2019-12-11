#include <iostream>

#include "Wall.hpp"
#include "Case.hpp"
#include "Ground.hpp"
#include "Door.hpp"
#include "Map.hpp"

Map::Map(int h, int w) : height(h), width(w), maxIndex(w * h - 1)
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

    // Ajout d'une porte fermee, en bas a droite
    Door d;
    matrix[maxIndex - 1] = Case(d);
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

GameElement Map::get(int x, int y)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        std::cout << "Index out of range" << std::endl;
        //todo: generate an Exception
        return GameElement();
    }
    return matrix[y * Map::get_width() + x].get_element();
}

int Map::put(int x, int y, GameElement element)
{
    if (x >= Map::get_width() || y >= Map::get_height())
    {
        std::cout << "Index out of range" << std::endl;
        return -1;
    }
    matrix[y*get_width() + x].set_element(element);
    return 0;
}