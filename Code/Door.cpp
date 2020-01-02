#include "Door.hpp"
#include "Game.hpp"
#include <iostream>


Door::Door()
{
    close();
    visible = true;
}

Door::Door(int x, int y) : StructureElement(x,y)
{
    close();
    visible = true;
}

Door::~Door()
{}

void Door::open()
{
    s = opened_door_symbol();
    is_opened = true;
}

void Door::close()
{
    s = closed_door_symbol();
    is_opened = false;
}

bool Door::is_accessible() const
{
    return is_opened;
}