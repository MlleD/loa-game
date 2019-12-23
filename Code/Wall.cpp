#include "Wall.hpp"
#include <iostream>

Wall::Wall()
{
    s = 'X';
}

Wall::~Wall()
{}

bool Wall::is_accessible()
{
    return false;
}
