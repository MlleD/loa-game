#ifndef MONSTER_H
#define MONSTER_H
#include "Creature.hpp"
class Map;

class Monster : public Creature
{
    private:
        std::vector<Position*> possible_movements(const Map* map);
    public:
        Monster();
        Monster(int x, int y);
        ~Monster();
        Position* wich_move(const Game* game);
};
#endif
