#include "Wall.hpp"
#include <iostream>




Wall::Wall()
{
    s = wall_symbol();
    visible = true;
}

Wall::Wall(int x, int y) : StructureElement(x,y)
{
    s = wall_symbol();
    visible = true;
}

Wall::~Wall()
{}

bool Wall::is_accessible() const
{
    return false;
}
