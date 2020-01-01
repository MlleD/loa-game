#include "Wall.hpp"
#include <iostream>

Wall::Wall()
{
    s = 'X';
}

Wall::Wall(int x, int y) : StructureElement(x,y)
{
    s = 'X';
}

Wall::~Wall()
{}

bool Wall::is_accessible() const
{
    return false;
}
