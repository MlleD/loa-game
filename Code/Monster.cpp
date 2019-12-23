#include "Monster.hpp"

Monster::Monster()
{
    s = 's';
}

Monster::~Monster()
{}

Position& Monster::wich_move(const Map map)
{
    return *pos;
}