#include "Ground.hpp"
#include <iostream>

Ground::Ground()
{
    s = ' ';
}
Ground::~Ground()
{}

bool Ground::is_accessible()
{
    return true;
}