#ifndef CREATURE_H
#define CREATURE_H

#include "GameElement.hpp"
#include "Map.hpp"
#include <algorithm>
#include <vector>

class Creature : public GameElement
{
    public:
        Creature();
        Creature(int x, int y);
        virtual ~Creature();
        int move_to(const Position& p);
        virtual Position& wich_move(const Map* map);
};

#endif
