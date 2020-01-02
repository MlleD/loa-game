#include "Ground.hpp"
#include <iostream>


Ground::Ground()
{
    s = ground_symbol();
    visible = true;
}

Ground::Ground(int x, int y) : StructureElement(x,y)
{
    s = ground_symbol();
    visible = true;
}

Ground::~Ground()
{}

bool Ground::is_accessible() const
{
    return true;
}