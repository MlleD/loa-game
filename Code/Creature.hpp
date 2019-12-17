#ifndef CREATURE_H
#define CREATURE_H

#include "GameElement.hpp"
#include <algorithm>
#include <vector>

class Creature : public GameElement
{
    private:
        int accessible_relative_positions[8];
        int nb_accessible_relative_positions;
        bool can_move(Position& p);
    protected:
        void set_accessible_relative_positions(std::vector<Position> val);
    public:
        //Creature(Position& p);
        //Creature(Creature& c);
        int move(Position& p);
};

#endif
