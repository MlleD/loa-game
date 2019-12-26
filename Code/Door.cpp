#include "Door.hpp"
#include <iostream>

Door::Door()
{
    close();
}

Door::Door(int x, int y) : StructureElement(x,y)
{
    close();
}

Door::~Door()
{}

void Door::open()
{
    s = '+';
    is_opened = true;
}

void Door::close()
{
    s = '-';
    is_opened = false;
}

bool Door::is_accessible()
{
    return is_opened;
}