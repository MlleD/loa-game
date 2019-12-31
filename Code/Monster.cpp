#include "Monster.hpp"
#include <iostream>

using namespace std;
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

vector<Position> Monster::possible_movements(const Map* map)
{
    vector<Position> positions;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1 ; y < 2 ; y++)
        {
            //if (is_accessible())
        }
    }
    return positions;
}

Position& Monster::wich_move(const Map* map)
{
    cout << "mouvement possible : " << possible_movements(map).size() << endl;
    return *pos;
}