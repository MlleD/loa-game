#include "Creature.hpp"

bool Creature::can_move(Position& p)
{
    for (int i = 0; i < nb_accessible_relative_positions; i++)
    {
        if (pos.get_x() + accessible_relative_positions[i] == p.get_x()
         && pos.get_y() + accessible_relative_positions[i] == p.get_y())
        {
            return true;
        }
    }
    return false;    
}

int Creature::move(Position& p)
{
    if (can_move(p))
    {
        pos.set_x(p.get_x());
        pos.set_y(p.get_y());
        return 0;
    }
    return -1;
}

void Creature::set_accessible_relative_positions(std::vector<Position> val)
{
    //std::copy(val.begin(), val.end(), accessible_relative_positions);
}