#ifndef MONSTER_H
#define MONSTER_H
#include "Creature.hpp"

class Monster : public Creature
{
    private:
    public:
        Monster();
        Monster(int x, int y);
        ~Monster();
        Position& wich_move(const Map map);
};
#endif
