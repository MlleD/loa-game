#include "Door.hpp"
#include <iostream>

Door::Door()
{
    close();
}
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
