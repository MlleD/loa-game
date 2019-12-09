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
        Case c(new Wall());
        matrix.push_back(c);
    }
    
    // Lignes intermediaires
    for (int i = 1; i < height - 1; i++)
    {
        matrix.push_back(new Wall());
        for (int j = 1; j < width - 1; j++)
        {
            matrix.push_back(new Ground());
        }
        matrix.push_back(new Wall());
    }

    //Ligne du bas
        for (int i = 0; i < width; i++)
    {
        Case c(new Wall());
        matrix.push_back(c);
    }

    // Ajout d'une porte fermee, en bas a droite
    matrix[maxIndex - 1] = Case(new Door());
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
