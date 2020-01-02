#include "Door.hpp"
#include <iostream>

Door::Door() : GameElement() , StructureElement(), InteractiveElement()
{
    close();
}

Door::Door(int x, int y) : GameElement(x,y) , StructureElement(x,y), InteractiveElement(x,y)
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


void Door::interact(Game* game)
{

}

bool Door::is_accessible() const
{
    return is_opened;
}