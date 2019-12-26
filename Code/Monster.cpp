#include "Monster.hpp"

Monster::Monster()
{
    s = 's';
}


Monster::Monster(int x, int y) : Creature(x,y)
{
    s = 's';
}

Monster::~Monster()
{}

Position& Monster::wich_move(const Map map)
{
    return *pos;
}