#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.hpp"

class Player : public Creature
{
    public:
        Player();
        ~Player();
        Position& wich_move(const Map map);
};

#endif