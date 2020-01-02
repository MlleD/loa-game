#include "Ground.hpp"
#include <iostream>

Ground::Ground()
{
    s = ' ';
}

Ground::Ground(int x, int y) : StructureElement(x,y)
{
    s = ' ';
}

Ground::~Ground()
{}

bool Ground::is_accessible() const
{
    return true;
}